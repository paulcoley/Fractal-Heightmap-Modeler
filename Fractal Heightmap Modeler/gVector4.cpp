#include "gVector4.h"

gVector4::gVector4() {
	data[0] = 0.0f;
	data[1] = 0.0f;
	data[2] = 0.0f;
	data[3] = 0.0f;
}

gVector4::gVector4(float x, float y, float z, float w) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

float gVector4::operator[](unsigned int index) const {
	assert(index < 4 && index >=0);
	return data[index];
}

float& gVector4::operator[](unsigned int index) {
	assert(index < 4 && index >= 0);
	return data[index];
}

void gVector4::print() {
	std::cout << "(" << data[0] << ", " << data[1] << ", " << data[2] << ", " << data[3] << ")" << std::endl;
}

float gVector4::length() const {
	return std::sqrtf(std::powf(data[0], 2) + std::powf(data[1], 2) + std::powf(data[2], 2) + std::powf(data[3], 2));
}

gVector4 gVector4::normalize() const {
	return *this / length();
}

bool operator==(const gVector4& v1, const gVector4& v2) {
	return (std::abs(v1[0] - v2[0]) < EPSILON) && (std::abs(v1[1] - v2[1]) < EPSILON) && (std::abs(v1[2] - v2[2]) < EPSILON && (std::abs(v1[3] - v2[3]) < EPSILON));
}

bool operator!=(const gVector4& v1, const gVector4& v2) {
	return (std::abs(v1[0] > v2[0]) > EPSILON) || (std::abs(v1[1] - v2[1]) > EPSILON) || (std::abs(v1[2] - v2[2]) > EPSILON || (std::abs(v1[3] - v2[3]) > EPSILON));
}

gVector4 operator+ (const gVector4& v1, const gVector4& v2) {
	return gVector4(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2], v1[3] + v2[3]);
}

gVector4 operator- (const gVector4& v1, const gVector4& v2) {
	return gVector4(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2], v1[3] - v2[3]);
}

gVector4 operator* (const gVector4& v, float c) {
	return gVector4(v[0] * c, v[1] * c, v[2] * c, v[3] * c);
}

gVector4 operator* (float c, const gVector4& v) {
	return gVector4(c * v[0], c * v[1], c * v[2], c * v[3]);
}

gVector4 operator/ (const gVector4& v, float c) {
	assert(std::abs(c) > EPSILON);
	return gVector4(v[0] / c, v[1] / c, v[2] / c, v[3] / c);
}

float operator* (const gVector4& v1, const gVector4& v2) {
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3];
}

gVector4 operator% (const gVector4& v1, const gVector4& v2) {
	return gVector4(v1[1] * v2[2] - v1[2] * v2[1],
		v1[2] * v2[0] - v1[0] * v2[2],
		v1[0] * v2[1] - v1[1] * v2[0],
		1);
}