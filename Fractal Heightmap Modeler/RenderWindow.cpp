#include "RenderWindow.h"

RenderWindow::RenderWindow(int x, int y, int w, int h) 
	: Fl_Gl_Window(x, y, w, h), camera(4.f, 0.f, 0.f), mode(DisplayMode::Mesh) {
	r = 1.f;
	g = 1.f;
	b = 1.f;
	selected_vertex = nullptr;
	snow_cap_level = 0.f;
}

void RenderWindow::ToggleDisplayMode() {
	switch (mode) {
		case DisplayMode::Mesh:
			mode = DisplayMode::Wire;
			std::cout << "Wire Mode!" << std::endl;
			break;
		case DisplayMode::Wire:
			mode = DisplayMode::WireMesh;
			std::cout << "Both!" << std::endl;
			break;
		case DisplayMode::WireMesh:
			mode = DisplayMode::Mesh;
			std::cout << "Mesh Mode!" << std::endl;
			break;
		default:
			break;
	}
}

void RenderWindow::initialize() {
	glViewport(0, 0, w(), h());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 0.1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
}

void RenderWindow::draw() {
	if (!valid()){
		initialize();				// make sure the OpenGL settings are completed once before drawing
		valid(1);
	}
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(camera.getEye()[0], camera.getEye()[1], camera.getEye()[2], 0, 0, 0, camera.getUp()[0], camera.getUp()[1], camera.getUp()[2]);

	auto facelist = controller.getFaces();
	for (auto face : facelist) {
		auto verticies = face.getPoints();
		switch (mode) {
			case DisplayMode::Mesh:
				glBegin(GL_TRIANGLES);
				for (auto vertex : verticies) {
					if ((*vertex)[2] >= snow_cap_level) {
						glColor3f(1.f, 1.f, 1.f);
					}
					else {
						glColor3f(r, g, b);
					}
					glVertex3f((*vertex)[0], (*vertex)[1], (*vertex)[2]);
				}
				glEnd();
				break;
			case DisplayMode::Wire:
				glBegin(GL_LINE_LOOP);
				for (auto vertex : verticies) {
					if (vertex == selected_vertex) {
						glColor3f(1.f, 0.f, 0.f);
					}
					else {
						glColor3f(0.f, 1.f, 0.f);
					}
					glVertex3f((*vertex)[0], (*vertex)[1], (*vertex)[2]);
				}
				glEnd();
				break;
			case DisplayMode::WireMesh:
				glBegin(GL_TRIANGLES);
				for (auto vertex : verticies) {
					if ((*vertex)[2] >= snow_cap_level) {
						glColor3f(1.f, 1.f, 1.f);
					}
					else {
						glColor3f(r, g, b);
					}
					glVertex3f((*vertex)[0], (*vertex)[1], (*vertex)[2]);
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				for (auto vertex : verticies) {
					if (vertex == selected_vertex) {
						glColor3f(1.f, 0.f, 0.f);
					}
					else {
						glColor3f(0.f, 1.f, 0.f);
					}
					glVertex3f((*vertex)[0], (*vertex)[1], (*vertex)[2]);
				}
				glEnd();
				break;
			default:
				break;
		}
	}
}

int RenderWindow::handle(int event) {
	if (event == FL_KEYUP){
		if (Fl::event_key() == 'a'){
			camera.increasePhi(-7);
			redraw();
		}
		if (Fl::event_key() == 'd'){
			camera.increasePhi(7);
			redraw();
		}
		if (Fl::event_key() == 'w'){
			camera.increaseTheta(-7);
			redraw();
		}
		if (Fl::event_key() == 's'){
			camera.increaseTheta(7);
			redraw();
		}
		if (Fl::event_key() == 'e'){
			camera.increaseRad(-.5);
			redraw();
		}
		if (Fl::event_key() == 'q'){
			camera.increaseRad(.5);
			redraw();
		}
	}
	return Fl_Gl_Window::handle(event);
}