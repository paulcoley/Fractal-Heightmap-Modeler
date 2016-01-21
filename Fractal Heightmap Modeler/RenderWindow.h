#pragma once
#include <memory>
#include <list>
#include <Fl/Fl_Gl_Window.H>
#include <Fl/Gl.H>
#include <GL/glu.h>
#include <Fl/Fl.H>
#include "Camera.h"
#include "MeshController.h"

enum class DisplayMode {
	Mesh,
	Wire,
	WireMesh
};

class RenderWindow : public Fl_Gl_Window {
private:
	Camera camera;
	MeshController controller;
	DisplayMode mode;
	float r, g, b;
	std::shared_ptr<gVector4> selected_vertex;
	float snow_cap_level;

	void initialize();
	void draw();
	int handle(int);
public:
	RenderWindow(int, int, int, int);

	void ToggleDisplayMode();
	MeshController& mesh() { return controller; }
	void setRGB(float red, float green, float blue) {
		r = red;
		g = green;
		b = blue;
	}
	void ResetCameraToTop() {
		camera = Camera(4.f, 0.f, 0.f);
	}
	void ResetCameraToSide() {
		camera = Camera(4.f, 0.f, 0.f);
		camera.increaseTheta(90);
	}

	void SetSelectedVertex(std::shared_ptr<gVector4> vertex) {
		selected_vertex = vertex;
	}

	std::shared_ptr<gVector4>& GetSelectedVertex() {
		return selected_vertex;
	}

	void SetSnowCap(float input) {
		snow_cap_level = input;
	}
};