/*
 *  gVector4.h
 */

#pragma once

#include <iostream>
#include <cassert>

#define EPSILON 0.001f
#define PI 3.141592f

class gVector4 {
private:
	float data[4];
public:
	///----------------------------------------------------------------------
	/// Constructors
	///----------------------------------------------------------------------
	gVector4();
	gVector4(float x, float y, float z, float w);
	
	///----------------------------------------------------------------------
	/// Getters/Setters
	///----------------------------------------------------------------------		
	/// Returns the value at index
	float operator[](unsigned int index) const;
	
	/// Returns a reference to the value at index
	float& operator[](unsigned int index);

	/// Prints the vector to standard output in a nice format
	void print();
	
	///----------------------------------------------------------------------
	/// Vector Operations
	///----------------------------------------------------------------------
	/// Returns the geometric length of the vector
	float length() const;
	gVector4 normalize() const;
		
	///----------------------------------------------------------------------
	/// Friend Functions
	///----------------------------------------------------------------------		
	/// Checks if v1 == v2
	friend bool operator==(const gVector4& v1, const gVector4& v2);
	
	/// Checks if v1 != v2
	friend bool operator!=(const gVector4& v1, const gVector4& v2);
	
	/// Vector Addition (v1 + v2)
	friend gVector4 operator+ (const gVector4& v1, const gVector4& v2);
	
	/// Vector Subtraction (v1 - v2)
	friend gVector4 operator- (const gVector4& v1, const gVector4& v2);
	
	/// Scalar Multiplication (v * c)
	friend gVector4 operator* (const gVector4& v, float c);	
	
	/// Scalar Multiplication (c * v)
	friend gVector4 operator* (float c, const gVector4& v);
	
	/// Scalar Division (v/c)
	friend gVector4 operator/ (const gVector4& v, float c);
	
	/// Dot Product (v1 * v2)
	friend float operator* (const gVector4& v1, const gVector4& v2);
	
	/// Cross Product (v1 % v2)
	friend gVector4 operator% (const gVector4& v1, const gVector4& v2);
};