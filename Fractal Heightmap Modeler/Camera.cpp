#include "Camera.h"

Camera::Camera(float r, float phi, float theta) {
	rotation = gMatrix4::identity();
	up = gVector4(0, 1, 0, 1);
	eye = gVector4(0, 0, r, 1);
}

void Camera::increasePhi(float inc) {
	rotation = rotation * gMatrix4::rotation3D(gVector4(0, 1, 0, 1), inc);
}

void Camera::increaseTheta(float inc) {
	rotation = rotation * gMatrix4::rotation3D(gVector4(1, 0, 0, 1), inc);
}

void Camera::increaseRad(float inc) {
	eye[2] = eye[2] + inc;
}

gVector4 Camera::getEye() {
	return rotation * eye;
}

gVector4 Camera::getUp() {
	return rotation * up;
}