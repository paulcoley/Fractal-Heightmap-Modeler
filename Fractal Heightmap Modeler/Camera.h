#pragma once
#include "gMatrix4.h"

class Camera {
private:
	gMatrix4 rotation;
	gVector4 up;
	gVector4 eye;
public:
	Camera(float, float, float);
	void increasePhi(float);
	void increaseTheta(float);
	void increaseRad(float);
	gVector4 getEye();
	gVector4 getUp();
};