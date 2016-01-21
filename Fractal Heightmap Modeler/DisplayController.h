#pragma once
#include <memory>
#include "Display.h"

class DisplayController {
private:
	Display display;
protected:
public:
	DisplayController() : display(10, 10, 1075, 700) {
		display.show();
	}
};