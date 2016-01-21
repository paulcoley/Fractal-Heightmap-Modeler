#include "gMatrix4.h"

gMatrix4::gMatrix4() {
	data[0] = gVector4();
	data[1] = gVector4();
	data[2] = gVector4();
	data[3] = gVector4();
}

gMatrix4::gMatrix4(const gVector4& row1, const gVector4& row2, const gVector4& row3, const gVector4& row4) {
	data[0] = row1;
	data[1] = row2;
	data[2] = row3;
	data[3] = row4;
}

gVector4 gMatrix4::operator[](unsigned int index) const {
	assert(index < 4 && index >= 0);
	return data[index];
}

gVector4& gMatrix4::operator[](unsigned int index) {
	assert(index < 4 && index >= 0);
	return data[index];
}

gVector4 gMatrix4::getColumn(unsigned int index) const {
	assert(index < 4 && index >= 0);
	return gVector4(data[0][index], data[1][index], data[2][index], data[2][index]);
}

void gMatrix4::print() {
	data[0].print();
	data[1].print();
	data[2].print();
	data[3].print();
}

gMatrix4 gMatrix4::transpose() const {
	return gMatrix4(getColumn(0), getColumn(1), getColumn(2), getColumn(3));
}

gMatrix4 gMatrix4::rotation3D(gVector4 axis, float angle) {
	angle = (angle * PI) / 180.0f;
	float cosine = std::cos(angle);
	float sine = std::sin(angle);
	float t = 1.f - cosine;
	
	axis = axis.normalize();
	
	return gMatrix4(gVector4(t * axis[0] * axis[0] + cosine,
		t * axis[0] * axis[1] - sine * axis[2],
		t * axis[0] * axis[2] + sine * axis[1],
		     0.0),
			 gVector4(t * axis[0] * axis[1] + sine * axis[2],
		t * axis[1] * axis[1] + cosine,
		t * axis[1] * axis[2] - sine * axis[0],
		     0.0),
			 gVector4(t * axis[0] * axis[2] - sine * axis[1],
		t * axis[1] * axis[2] + sine * axis[0],
			 t * axis[2] * axis[2] + cosine,
		     0.0),
		gVector4(0.0, 0.0, 0.0, 1.0));
}

gMatrix4 gMatrix4::translation3D(float x, float y, float z) {
	return gMatrix4(gVector4(1.0f, 0.0f, 0.0f, x),
		gVector4(0.0f, 1.0f, 0.0f, y),
		gVector4(0.0f, 0.0f, 1.0f, z),
		gVector4(0.0f, 0.0f, 0.0f, 1.0f));
}

gMatrix4 gMatrix4::scale3D(float x, float y, float z){
	return gMatrix4(gVector4(x, 0.0f, 0.0f, 0.0f),
		gVector4(0.0f, y, 0.0f, 0.0f),
		gVector4(0.0f, 0.0f, z, 0.0f),
		gVector4(0.0f, 0.0f, 0.0f, 1.0f));
}

gMatrix4 gMatrix4::identity() {
	return gMatrix4(gVector4(1.0f, 0.0f, 0.0f, 0.0f),
		gVector4(0.0f, 1.0f, 0.0f, 0.0f),
		gVector4(0.0f, 0.0f, 1.0f, 0.0f),
		gVector4(0.0f, 0.0f, 0.0f, 1.0f));
}

bool operator==(const gMatrix4& m1, const gMatrix4& m2) {
	return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]);
}

bool operator!=(const gMatrix4& m1, const gMatrix4& m2) {
	return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]);
}

gMatrix4 operator+ (const gMatrix4& m1, const gMatrix4& m2) {
	return gMatrix4(m1[0] + m2[0], m1[1] + m2[1], m1[2] + m2[2], m1[3] + m2[3]);
}

gMatrix4 operator- (const gMatrix4& m1, const gMatrix4& m2) {
	return gMatrix4(m1[0] - m2[0], m1[1] - m2[1], m1[2] - m2[2], m1[3] - m2[3]);
}

gMatrix4 operator* (const gMatrix4& m, float c) {
	return gMatrix4(m[0] * c, m[1] * c, m[2] * c, m[3] * c);
}

gMatrix4 operator* (float c, const gMatrix4& m) {
	return gMatrix4(c * m[0], c * m[1], c * m[2], c * m[3]);
}

gMatrix4 operator/ (const gMatrix4& m, float c) {
	assert(std::abs(c) > EPSILON);
	return gMatrix4(m[0] / c, m[1] / c, m[2] / c, m[3] / c);
}

gMatrix4 operator* (const gMatrix4& m1, const gMatrix4& m2) {
	return gMatrix4(gVector4(m1[0] * m2.getColumn(0), m1[0] * m2.getColumn(1), m1[0] * m2.getColumn(2), m1[0] * m2.getColumn(3)),
		gVector4(m1[1] * m2.getColumn(0), m1[1] * m2.getColumn(1), m1[1] * m2.getColumn(2), m1[1] * m2.getColumn(3)),
		gVector4(m1[2] * m2.getColumn(0), m1[2] * m2.getColumn(1), m1[2] * m2.getColumn(2), m1[2] * m2.getColumn(3)),
		gVector4(m1[3] * m2.getColumn(0), m1[3] * m2.getColumn(1), m1[3] * m2.getColumn(2), m1[3] * m2.getColumn(3)));
}

gVector4 operator* (const gMatrix4& m, const gVector4& v) {
	return gVector4(m[0] * v, m[1] * v, m[2] * v, m[3] * v);
}

gVector4 operator* (const gVector4& v, const gMatrix4& m) {
	return gVector4(v * m.getColumn(0), v * m.getColumn(1), v * m.getColumn(2), v * m.getColumn(3));
}