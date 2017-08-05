#ifndef A_MATRIX_4X4
#define A_MATRIX_4X4

#include "A_Quaternion.h"

class A_Matrix4x4 {

public:

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************Constructors, destructor******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	initializes all values to 0
	*/
	A_Matrix4x4();

	/**
	initializes all values to _f
	0 for identity matrix
	*/
	A_Matrix4x4(float const _f);

	/**
	copy constructor
	*/
	A_Matrix4x4(A_Matrix4x4 const *_AM);

	/**
	uses the four quaternions as the ROWS for this matrix
	*/
	A_Matrix4x4(A_Quaternion *_AQ1, A_Quaternion *_AQ2, A_Quaternion *_AQ3, A_Quaternion *_AQ4);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	*/
	A_Matrix4x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix4x4();

	const float getDemensionAtAddress(int const _f) const {

		return this->demensions[_f];

	}

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*******************Member access*************************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	returns the selected column
	the columns are 0, 1, 2, and 3
	*/
	//TODO: CREATE A_VECTOR4 AND FIX RETURN TYPE
	const A_Quaternion GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AQ
	the columns are 0, 1, 2, and 3
	*/
	//TODO: CREATE A_VECTOR4 AND FIX RETURN TYPE
	void SetColumnAtAddress(int const _ad, A_Quaternion * _AQ);

	/**
	returns the selected row
	the row are 0, 1, 2, and 3
	*/
	//TODO: CREATE A_VECTOR4 AND FIX RETURN TYPE
	const A_Quaternion GetRowAtAddress(int const _ad);

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1, 2, and 3
	*/
	//TODO: CREATE A_VECTOR4 AND FIX RETURN TYPE
	void SetRowAtAddress(int const _ad, A_Quaternion * _AQ);

	/**
	turns this matrix into an identity matrix
	*/
	void setIdentity();

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*****************matrix operations***********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	returns this matrix rotated about the X axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationXAxis(float _f);

	/**
	returns this matrix rotated about the Y axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationYAxis(float _f);

	/**
	returns this matrix rotated about the Z axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationZAxis(float _f);

	/**
	tests to make sure the matrix can be inverted, and inverts it if it can (then returns true) if not, method returns false
	*/
	const bool Invert();

	/**
	returns the transposed version of this matrix
	*/
	const A_Matrix4x4 GetTransposed();

	/**
	assings to this matrix, the transposed version of itself
	*/
	void SetTranposed();

	/**
	
	*/


	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*********addition  & subtraction operators***************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	adds to this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix4x4 operator +(A_Matrix4x4 const *_AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] + _AM->demensions[i];

		}

		return T_Result;

	}

	/**
	adds to this matrix another 4x4 matrix
	*/
	void operator +=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] += _AM->demensions[i];

		}

	}

	/**
	subtracts from this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix4x4 operator -(A_Matrix4x4 const *_AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] - _AM->demensions[i];

		}

		return T_Result;

	}

	/**
	subtracts from this matrix another 4x4 matrix
	*/
	void operator -=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] -= _AM->demensions[i];

		}

	}
	
	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************multiplication operators******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/*
	
	TODO: ADD SUPPORT FOR OTHER x4 SIZE MATRICIES & VECTOR MULTIPLICATION
	
	*/

	/**
	multiplying this matrix by a scalar and returning the result
	*/
	A_Matrix4x4 operator *(float const _f) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] * _f;

		}
		
		return T_Result;

	}

	/**
	multiplies this matrix by another 4x4 matrix, resulting in a new 4x4 matrix
	*/
	A_Matrix4x4 operator *(A_Matrix4x4 const *_AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] * _AM->demensions[i];

		}

		return T_Result;

	}

	/**
	multiplying this matrix by a scalar
	*/
	void operator *=(float const _f) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] *= _f;

		}

	}

	/**
	multiplies this matrix by another 4x4 matrix, and applies the result to this matrix
	*/
	void operator *=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] *= _AM->demensions[i];

		}

	}

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************assignment operators**********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	assigns to each value of this matrix _f
	*/
	void operator =(float const _f) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _f;

		}

	}

	/**
	assigns to this matrix the values of another matrix
	*/
	void operator =(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _AM->demensions[i];

		}

	}
	

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	//C D E F
	float demensions[16];

};

#endif