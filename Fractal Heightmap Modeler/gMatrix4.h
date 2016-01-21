/*
 *  gMatrix4.h
 */
 
#pragma once

#include "gVector4.h"

class gMatrix4{
private:
	gVector4 data[4];
public:
	///----------------------------------------------------------------------
	/// Constructors
	///----------------------------------------------------------------------
	/// Default Constructor.  Initialize to matrix of all 0s.
	gMatrix4();

	/// Initializes matrix with each vector representing a row in the matrix
	gMatrix4(const gVector4& row1, const gVector4& row2, const gVector4& row3, const gVector4& row4);

	///----------------------------------------------------------------------
	/// Getters
	///----------------------------------------------------------------------	
	/// Returns the values of the row at the index
	gVector4 operator[](unsigned int index) const;
	
	/// Returns a reference to the row at the index
	gVector4& operator[](unsigned int index);
	
	/// Returns a column of the matrix
	gVector4 getColumn(unsigned int index) const;

	/// Prints the matrix to standard output in a nice format
	void print();

	///----------------------------------------------------------------------
	/// Matrix Operations
	///----------------------------------------------------------------------	
	/// Returns the transpose of the matrix (v_ij == v_ji)
	gMatrix4 transpose() const;

	///----------------------------------------------------------------------
	/// Static Initializers
	///----------------------------------------------------------------------	
	/// Creates a 3-D rotation matrix.
	/// Takes an angle in degrees and outputs a 4x4 rotation matrix
	static gMatrix4 rotation3D(gVector4 axis, float angle);
	
	/// Takes an x, y, and z displacement and outputs a 4x4 translation matrix
	static gMatrix4 translation3D(float x, float y, float z);
	
	/// Takes an x, y, and z scale and outputs a 4x4 scale matrix
	static gMatrix4 scale3D(float x, float y, float z);
	
	/// Generates a 4x4 identity matrix
	static gMatrix4 identity();	
	
	
	///----------------------------------------------------------------------
	/// Friend Functions
	///----------------------------------------------------------------------
	/// Checks if m1 == m2
 	friend bool operator==(const gMatrix4& m1, const gMatrix4& m2);
	
	/// Checks if m1 != m2
	friend bool operator!=(const gMatrix4& m1, const gMatrix4& m2);
	
	/// Matrix addition (m1 + m2)
	friend gMatrix4 operator+ (const gMatrix4& m1, const gMatrix4& m2);
	
	/// Matrix subtraction (m1 - m2)
	friend gMatrix4 operator- (const gMatrix4& m1, const gMatrix4& m2);
	
	/// Scalar multiplication (m * c)
	friend gMatrix4 operator* (const gMatrix4& m, float c);
	
	/// Scalar multiplication (c * m)
	friend gMatrix4 operator* (float c, const gMatrix4& m);
	
	/// Scalar division (m / c)
	friend gMatrix4 operator/ (const gMatrix4& m, float c);
	
	/// Matrix multiplication (m1 * m2)
	friend gMatrix4 operator* (const gMatrix4& m1, const gMatrix4& m2);
	
	/// Matrix/vector multiplication (m * v)
	/// Assume v is a column vector (ie. a 4x1 matrix)
	friend gVector4 operator* (const gMatrix4& m, const gVector4& v);
	
	/// Vector/matrix multiplication (v * m)
	/// Assume v is a row vector (ie. a 1x4 matrix)
	friend gVector4 operator* (const gVector4& v, const gMatrix4& m);
};