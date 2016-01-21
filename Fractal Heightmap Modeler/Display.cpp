#include "Display.h"

Display::Display(int x, int y, int w, int h) : 
	Fl_Window(x, y, w, h, "Final Project"),
	render_window(0, 0, 700, 600),
	row_number_spinner(800, 10, 50, 25, "# of Rows"),
	column_number_spinner(800, 40, 50, 25, "# of Colums"),
	length_number_spinner(800, 70, 50, 25, "Length"),
	width_number_spinner(800, 100, 50, 25, "Width"),
	color_chooser(710, 150, 175, 95, "Color Picker"),
	create_mesh_button(725, 250, 135, 40, "Create Mesh"),
	top_view_button(725, 300, 135, 40, "Top View"),
	side_view_button(725, 350, 135, 40, "Side View"),
	mesh_display_button(725, 400, 145, 40, "Mesh Display Toggle"),
	xpos_button(725, 450, 30, 25, "X+"),
	xneg_button(725, 475, 30, 25, "X-"),
	ypos_button(760, 450, 30, 25, "Y+"),
	yneg_button(760, 475, 30, 25, "Y-"),
	zpos_button(795, 450, 30, 25, "Z+"),
	zneg_button(795, 475, 30, 25, "Z-"),
	fractalize_mesh_button(725, 550, 90, 40, "Fractalize"),
	snowcap_slider(10, 610, 690, 35, "Snow Cap Height"),
	range_number_spinner(770, 510, 50, 25, "Range"),
	vertex_list(900, 10, 150, 650, "Vertex List") {

	snowcap_slider.type(FL_HORIZONTAL);
	row_number_spinner.type(FL_INT_INPUT);
	column_number_spinner.type(FL_INT_INPUT);
	length_number_spinner.type(FL_INT_INPUT);
	width_number_spinner.type(FL_INT_INPUT);

	create_mesh_button.callback((Fl_Callback*)create_meshCB, &*this);
	color_chooser.callback((Fl_Callback*)colorCB, &*this);
	mesh_display_button.callback((Fl_Callback*)mesh_displayCB, &*this);
	top_view_button.callback((Fl_Callback*)top_viewCB, &*this);
	side_view_button.callback((Fl_Callback*)side_viewCB, &*this);
	xpos_button.callback((Fl_Callback*)xposCB, &*this);
	xneg_button.callback((Fl_Callback*)xnegCB, &*this);
	ypos_button.callback((Fl_Callback*)yposCB, &*this);
	yneg_button.callback((Fl_Callback*)ynegCB, &*this);
	zpos_button.callback((Fl_Callback*)zposCB, &*this);
	zneg_button.callback((Fl_Callback*)znegCB, &*this);
	fractalize_mesh_button.callback((Fl_Callback*)fractalize_meshCB, &*this);
	snowcap_slider.callback((Fl_Callback*)snowcapCB, &*this);
	vertex_list.callback((Fl_Callback*)vertex_listCB, &*this);
	snowcap_slider.range(-2, 2);

	this->end();
}

void create_meshCB(Fl_Button* button, Display* data) {
	data->glwindow().mesh().CreateField(data->row_number(), data->column_number(), data->length_number(), data->width_number());
	data->vertex_selection().clear();
	data->vertecies = data->glwindow().mesh().getVertecies();
	int face = 1;
	int vertex_number = 1;
	for (auto& vertex : data->vertecies) {
		data->vertex_selection().add(("Face " + std::to_string(face) + " : Vertex " + std::to_string(vertex_number++)).c_str(), &vertex);
		if (vertex_number > 3) {
			face++;
			vertex_number = 1;
			std::cout << "Here!" << std::endl;
		}
	}
	data->glwindow().redraw();
	data->redraw();
}
void colorCB(Fl_Color_Chooser* button, Display* data) {
	data->glwindow().setRGB(static_cast<float>(button->r()), static_cast<float>(button->g()), static_cast<float>(button->b()));
	data->glwindow().redraw();
}
void mesh_displayCB(Fl_Button* button, Display* data) {
	data->glwindow().ToggleDisplayMode();
	data->glwindow().redraw();
}
void top_viewCB(Fl_Button* button, Display* data) {
	data->glwindow().ResetCameraToTop();
	data->glwindow().redraw();
}
void side_viewCB(Fl_Button* button, Display* data) {
	data->glwindow().ResetCameraToSide();
	data->glwindow().redraw();
}
void xposCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[0] += .25f;
	data->glwindow().redraw();
	data->redraw();
}
void xnegCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[0] -= .25f;
	data->glwindow().redraw();
	data->redraw();
}
void yposCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[1] += .25f;
	data->glwindow().redraw();
	data->redraw();
}
void ynegCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[1] -= .25f;
	data->glwindow().redraw();
	data->redraw();
}
void zposCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[2] += .25f;
	data->glwindow().redraw();
	data->redraw();
}
void znegCB(Fl_Button* button, Display* data) {
	if (data->glwindow().GetSelectedVertex() == nullptr) {
		return;
	}
	(*data->glwindow().GetSelectedVertex())[2] -= .25f;
	data->glwindow().redraw();
	data->redraw();
}
void fractalize_meshCB(Fl_Button* button, Display* data) {
	static float base_range = 0.f;
	static float current_range = 0.f;
	if (std::abs(base_range - data->range_number()) > EPSILON) {
		base_range = data->range_number();
		current_range = data->range_number();
	}
	data->glwindow().mesh().Fractalize(current_range);
	data->vertex_selection().clear();
	data->vertecies = data->glwindow().mesh().getVertecies();
	int face = 1;
	int vertex_number = 1;
	for (auto& vertex : data->vertecies) {
		data->vertex_selection().add(("Face " + std::to_string(face) + " : Vertex " + std::to_string(vertex_number++)).c_str(), &vertex);
		if (vertex_number > 3) {
			face++;
			vertex_number = 1;
			std::cout << "Here!" << std::endl;
		}
	}
	data->glwindow().redraw();
	data->redraw();
	current_range /= 2.f;
}
void snowcapCB(Fl_Slider* button, Display* data) {
	button->copy_label(("Snow Cap Height: " + std::to_string(static_cast<float>(button->value()))).c_str());
	data->glwindow().SetSnowCap(static_cast<float>(button->value()));
	data->glwindow().redraw();
}

void vertex_listCB(Fl_Hold_Browser* button, Display* data) {
	if (button->value() == 0) {
		data->glwindow().SetSelectedVertex(nullptr);
		data->glwindow().redraw();
		data->redraw();
		return;
	}
	auto temp = *((std::shared_ptr<gVector4>*) button->data(button->value()));
	data->glwindow().SetSelectedVertex(temp);
	data->glwindow().redraw();
	data->redraw();
}