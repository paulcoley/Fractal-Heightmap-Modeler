#pragma once
#include <Fl/Fl_Window.H>
#include <memory>
#include "RenderWindow.h"
#include <Fl/Fl_Button.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Float_Input.H>
#include <Fl/Fl_Hold_Browser.H>
#include <string>

class Display : public Fl_Window {
private:
	RenderWindow render_window;

	Fl_Button create_mesh_button;
	Fl_Spinner row_number_spinner;
	Fl_Spinner column_number_spinner;
	Fl_Spinner length_number_spinner;
	Fl_Spinner width_number_spinner;
	Fl_Color_Chooser color_chooser;

	Fl_Button mesh_display_button;
	Fl_Button top_view_button;
	Fl_Button side_view_button;

	Fl_Button xpos_button;
	Fl_Button xneg_button;
	Fl_Button ypos_button;
	Fl_Button yneg_button;
	Fl_Button zpos_button;
	Fl_Button zneg_button;

	Fl_Float_Input range_number_spinner;
	Fl_Button fractalize_mesh_button;
	Fl_Slider snowcap_slider;

	Fl_Hold_Browser vertex_list;
public:
	std::list<std::shared_ptr<gVector4>> vertecies;

	Display(int, int, int, int);

	RenderWindow& glwindow() { return render_window; }
	int row_number() { return static_cast<int>(row_number_spinner.value()); }
	int column_number() { return static_cast<int>(column_number_spinner.value()); }
	int length_number() { return static_cast<int>(length_number_spinner.value()); }
	int width_number() { return static_cast<int>(width_number_spinner.value()); }
	float range_number() {
		if (std::string(range_number_spinner.value()) == "") return 0.f;
		return stof(std::string(range_number_spinner.value())); }
	Fl_Browser& vertex_selection() { return vertex_list; }
};

void create_meshCB(Fl_Button*, Display*);
void colorCB(Fl_Color_Chooser*, Display*);

void mesh_displayCB(Fl_Button*, Display*);
void top_viewCB(Fl_Button*, Display*);
void side_viewCB(Fl_Button*, Display*);

void xposCB(Fl_Button*, Display*);
void xnegCB(Fl_Button*, Display*);
void yposCB(Fl_Button*, Display*);
void ynegCB(Fl_Button*, Display*);
void zposCB(Fl_Button*, Display*);
void znegCB(Fl_Button*, Display*);

void fractalize_meshCB(Fl_Button*, Display*);
void snowcapCB(Fl_Slider*, Display*);
void vertex_listCB(Fl_Hold_Browser*, Display*);