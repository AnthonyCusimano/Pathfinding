#include "A_Matrix4x4.h"

A_Matrix4x4::A_Matrix4x4() {

	for (int i = 0; i < 16; ++i) {

		this->demensions[i] = 0.0f;

	}

}

A_Matrix4x4::A_Matrix4x4(float const _f) {

	if (_f == 0) {

		for (char i = 0; i < 16; ++i) {

			if (i == 0 || i == 5 || i == 10 || i == 15) {

				this->demensions[i] = 1.0f;

			}

			else demensions[i] = 0.0f;

		}

	}

	else {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _f;

		}

	}

}

A_Matrix4x4::A_Matrix4x4(A_Matrix4x4 const *_AM) {

	for (char i = 0; i < 16; ++i) {

		this->demensions[i] = _AM->demensions[i];

	}

}

A_Matrix4x4::A_Matrix4x4(A_Quaternion *_AQ1, A_Quaternion *_AQ2, A_Quaternion *_AQ3, A_Quaternion *_AQ4) {
	
	this->demensions[0] = _AQ1->getX();
	this->demensions[1] = _AQ1->getY();
	this->demensions[2] = _AQ1->getZ();
	this->demensions[3] = _AQ1->getW();

	this->demensions[4] = _AQ2->getX();
	this->demensions[5] = _AQ2->getY();
	this->demensions[6] = _AQ2->getZ();
	this->demensions[7] = _AQ2->getW();

	this->demensions[8] = _AQ3->getX();
	this->demensions[9] = _AQ3->getY();
	this->demensions[10] = _AQ3->getZ();
	this->demensions[11] = _AQ3->getW();

	this->demensions[12] = _AQ4->getX();
	this->demensions[13] = _AQ4->getY();
	this->demensions[14] = _AQ4->getZ();
	this->demensions[15] = _AQ4->getW();

}

A_Matrix4x4::A_Matrix4x4(float const _f[]) {

	for (char i = 0; i < 16; ++i) {

		this->demensions[i] = _f[i];

	}

}

const A_Quaternion A_Matrix4x4::GetColumnAtAddress(int const _ad) {

	//could error check _ad
	char i = (_ad * 4);
	A_Quaternion T_Result;

	T_Result.setX(this->demensions[i]);
	T_Result.setY(this->demensions[i + 1]);
	T_Result.setZ(this->demensions[i + 2]);
	T_Result.setW(this->demensions[i + 3]);

	return T_Result;

}

void A_Matrix4x4::SetColumnAtAddress(int const _ad, A_Quaternion *_AQ) {

	char i = (_ad * 4);

	this->demensions[i] = _AQ->getX();
	this->demensions[i + 1] = _AQ->getY();
	this->demensions[i + 2] = _AQ->getZ();
	this->demensions[i + 3] = _AQ->getW();

}

const A_Quaternion A_Matrix4x4::GetRowAtAddress(int const _ad) {

	A_Quaternion T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[_ad + 4]);
	T_Result.setZ(this->demensions[_ad + 8]);
	T_Result.setW(this->demensions[_ad + 12]);

	return T_Result;

}

void A_Matrix4x4::SetRowAtAddress(int const _ad, A_Quaternion *_AQ) {

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 4] = _AQ->getY();
	this->demensions[_ad + 8] = _AQ->getZ();
	this->demensions[_ad + 12] = _AQ->getW();

}

void A_Matrix4x4::setIdentity() {

	for (char i = 0; i < 16; ++i) {

		if (i == 0 || i == 5 || i == 10 || i == 15) {

			this->demensions[i] = 1.0f;

		}

		else demensions[i] = 0.0f;

	}

}

const A_Matrix4x4 A_Matrix4x4::GetRotationXAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	T_Result.demensions[5] = ::cosf(_f);
	T_Result.demensions[6] = -::cosf(_f);
	T_Result.demensions[9] = ::sinf(_f);
	T_Result.demensions[10] = ::cosf(_f);

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetRotationYAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	T_Result.demensions[0] = ::cosf(_f);
	T_Result.demensions[2] = ::sinf(_f);
	T_Result.demensions[8] = -::sinf(_f);
	T_Result.demensions[10] = ::cosf(_f);

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetRotationZAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	T_Result.demensions[0] = ::cosf(_f);
	T_Result.demensions[1] = -::sinf(_f);
	T_Result.demensions[4] = ::sinf(_f);
	T_Result.demensions[5] = ::cosf(_f);

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetTranslate(float const _x, float const _y, float const _z) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	this->demensions[3] = _x;
	this->demensions[7] = _y;
	this->demensions[11] = _z;

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetTranslate(A_Vector3 const *_AV) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	this->demensions[3] = _AV->getX();
	this->demensions[7] = _AV->getY();
	this->demensions[11] = _AV->getZ();

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetScale(float const _x, float const _y, float const _z) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	T_Result.demensions[0] = _x;
	T_Result.demensions[5] = _y;
	T_Result.demensions[10] = _z;

	return T_Result;

}

const A_Matrix4x4 A_Matrix4x4::GetScale(A_Vector3* const _AV) {

	A_Matrix4x4 T_Result;
	T_Result.setIdentity();

	T_Result.demensions[0] = _AV->getX();
	T_Result.demensions[5] = _AV->getY();
	T_Result.demensions[10] = _AV->getZ();

	return T_Result;

}

const bool A_Matrix4x4::Invert() {
	
	//determinant of this
	float T_determinant;
	//temp floats needed to assist in finding the determinant, and later assist in finding the final inverse of the matrix
	//names reflect first opperations done to these variables between the underscores, the second is after the underscores
	float T_2736_051C, T_2B3A_0918, T_6B7A_4958, T_6F7E_4D5C, T_AFBE_8D9C, T_E3F2_C1D0;
	//don't need any matrix functions, just need to store info here
	float T_matrix[16];

	T_2736_051C = this->demensions[2] * this->demensions[7] - this->demensions[3] * this->demensions[6];
	T_2B3A_0918 = this->demensions[2] * this->demensions[11] - this->demensions[3] * this->demensions[10];
	T_6B7A_4958 = this->demensions[6] * this->demensions[11] - this->demensions[7] * this->demensions[10];
	T_6F7E_4D5C = this->demensions[6] * this->demensions[15] - this->demensions[7] * this->demensions[14];
	T_AFBE_8D9C = this->demensions[10] * this->demensions[15] - this->demensions[11] * this->demensions[14];
	T_E3F2_C1D0 = this->demensions[14] * this->demensions[3] - this->demensions[15] * this->demensions[2];

	T_matrix[0] = this->demensions[5] * T_AFBE_8D9C - this->demensions[9] * T_6F7E_4D5C + this->demensions[13] * T_6B7A_4958;
	T_matrix[1] = -(this->demensions[1] * T_AFBE_8D9C + this->demensions[9] * T_E3F2_C1D0 + this->demensions[13] * T_2B3A_0918);
	T_matrix[2] = this->demensions[1] * T_6F7E_4D5C + this->demensions[5] * T_E3F2_C1D0 + this->demensions[13] * T_2736_051C;
	T_matrix[3] = -(this->demensions[1] * T_6F7E_4D5C - this->demensions[5] * T_2B3A_0918 + this->demensions[9] * T_2736_051C);

	T_determinant = this->demensions[0] * T_matrix[0] + this->demensions[4] * T_matrix[1] + this->demensions[8] * T_matrix[2] + this->demensions[12] * T_matrix[3];

	if (T_determinant == 0.0f) {

		//this matrix cannot be inverted
		this->setIdentity();
		return false;

	}

	//inverse of this matrix's determinant
	float T_INVDeterminant = 1.0f / T_determinant;

	T_matrix[0] *= T_INVDeterminant;
	T_matrix[1] *= T_INVDeterminant;
	T_matrix[2] *= T_INVDeterminant;
	T_matrix[3] *= T_INVDeterminant;

	//continuing filling out the T_matrix
	T_matrix[4] = -(this->demensions[4] * T_AFBE_8D9C - this->demensions[8] * T_6F7E_4D5C + this->demensions[12] * T_6B7A_4958) * T_INVDeterminant;
	T_matrix[5] = this->demensions[0] * T_AFBE_8D9C + this->demensions[8] * T_E3F2_C1D0 + this->demensions[12] * T_2B3A_0918 * T_INVDeterminant;
	T_matrix[6] = -(this->demensions[0] * T_6F7E_4D5C + this->demensions[4] * T_E3F2_C1D0 + this->demensions[12] * T_2B3A_0918) * T_INVDeterminant;
	T_matrix[7] = this->demensions[0] * T_6B7A_4958 - this->demensions[4] * T_2B3A_0918 + this->demensions[8] * T_2736_051C * T_INVDeterminant;

	//reusing the temporary variables from above, use portion of the name after the second underscore from here
	T_2736_051C = this->demensions[0] * this->demensions[5] - this->demensions[1] * this->demensions[12];
	T_2B3A_0918 = this->demensions[0] * this->demensions[9] - this->demensions[1] * this->demensions[8];
	T_6B7A_4958 = this->demensions[4] * this->demensions[9] - this->demensions[5] * this->demensions[8];
	T_6F7E_4D5C = this->demensions[4] * this->demensions[13] - this->demensions[5] * this->demensions[12];
	T_AFBE_8D9C = this->demensions[8] * this->demensions[13] - this->demensions[9] * this->demensions[12];
	T_E3F2_C1D0 = this->demensions[12] * this->demensions[1] - this->demensions[13] * this->demensions[0];

	T_matrix[8] = this->demensions[7] * T_AFBE_8D9C - this->demensions[11] * T_6F7E_4D5C + this->demensions[15] * T_6B7A_4958 * T_INVDeterminant;
	T_matrix[9] = -(this->demensions[3] * T_AFBE_8D9C + this->demensions[11] * T_E3F2_C1D0 + this->demensions[15] * T_2B3A_0918) * T_INVDeterminant;
	T_matrix[10] = this->demensions[3] * T_6F7E_4D5C + this->demensions[7] * T_E3F2_C1D0 + this->demensions[15] * T_2736_051C * T_INVDeterminant;
	T_matrix[11] = -(this->demensions[3] * T_6B7A_4958 - this->demensions[7] * T_2B3A_0918 + this->demensions[11] * T_2736_051C) * T_INVDeterminant;
	T_matrix[12] = -(this->demensions[6] * T_AFBE_8D9C - this->demensions[10] * T_6F7E_4D5C + this->demensions[14] * T_6B7A_4958) * T_INVDeterminant;
	T_matrix[13] = this->demensions[2] * T_AFBE_8D9C + this->demensions[10] * T_E3F2_C1D0 + this->demensions[14] * T_2B3A_0918 * T_INVDeterminant;
	T_matrix[14] = -(this->demensions[2] * T_6F7E_4D5C + this->demensions[6] * T_E3F2_C1D0 + this->demensions[14] * T_2736_051C) * T_INVDeterminant;
	T_matrix[15] = this->demensions[2] * T_6B7A_4958 - this->demensions[6] * T_2B3A_0918 + this->demensions[10] * T_2736_051C * T_INVDeterminant;

	this->demensions[0] = T_matrix[0];
	this->demensions[1] = T_matrix[1];
	this->demensions[2] = T_matrix[2];
	this->demensions[3] = T_matrix[3];
	this->demensions[4] = T_matrix[4];
	this->demensions[5] = T_matrix[5];
	this->demensions[6] = T_matrix[6];
	this->demensions[7] = T_matrix[7];
	this->demensions[8] = T_matrix[8];
	this->demensions[9] = T_matrix[9];
	this->demensions[10] = T_matrix[10];
	this->demensions[11] = T_matrix[11];
	this->demensions[12] = T_matrix[12];
	this->demensions[13] = T_matrix[13];
	this->demensions[14] = T_matrix[14];
	this->demensions[15] = T_matrix[15];


	return true;

}

const A_Matrix4x4 A_Matrix4x4::GetTransposed() {

	A_Matrix4x4 T_Result;

	//this->demensions[0] stays the same
	T_Result.demensions[1] = this->demensions[4];
	T_Result.demensions[2] = this->demensions[8];
	T_Result.demensions[3] = this->demensions[12];
	T_Result.demensions[4] = this->demensions[1];
	//this->demensions[5] stays the same
	T_Result.demensions[6] = this->demensions[9];
	T_Result.demensions[7] = this->demensions[13];
	T_Result.demensions[8] = this->demensions[2];
	T_Result.demensions[9] = this->demensions[6];
	//this->demensions[10] stays the same
	T_Result.demensions[11] = this->demensions[14];
	T_Result.demensions[12] = this->demensions[3];
	T_Result.demensions[13] = this->demensions[7];
	T_Result.demensions[14] = this->demensions[11];
	//this->demensions[15] stays the same

	return T_Result;

}

void A_Matrix4x4::SetTranposed() {

	A_Matrix4x4 T_Placehold;

	//this->demensions[0] stays the same

	//need to preserve this->demensions[1] for later
	T_Placehold.demensions[1] = this->demensions[1];
	this->demensions[1] = this->demensions[4];

	//need to preserve this->demensions[2] for later
	T_Placehold.demensions[2] = this->demensions[2];
	this->demensions[2] = this->demensions[8];

	//need to preserve this->demensions[3] for later
	T_Placehold.demensions[3] = this->demensions[3];
	this->demensions[3] = this->demensions[12];

	//held the old demensions[1] in T_Placehold
	this->demensions[4] = T_Placehold.demensions[1];

	//this->demensions[5] stays the same

	//need to preserve this->demensions[6] for later
	T_Placehold.demensions[6] = this->demensions[6];
	this->demensions[6] = this->demensions[9];

	//need to preserve this->demensions[7] for later
	T_Placehold.demensions[7] = this->demensions[7];
	this->demensions[7] = this->demensions[13];

	//held the old demensions[2] in T_Placehold
	this->demensions[8] = T_Placehold.demensions[2];

	//held the old demensions[6] in T_Placehold
	this->demensions[9] = T_Placehold.demensions[6];

	//this0->demensions[10] stays the same

	//need to preserve this->demensions[11] until later
	T_Placehold.demensions[11] = this->demensions[11];
	this->demensions[11] = this->demensions[14];

	//held the old this->demensions[3] in T_Placehold
	this->demensions[12] = T_Placehold.demensions[3];

	//held the old this->demensions[7] in T_Placehold
	this->demensions[13] = T_Placehold.demensions[7];

	//held the old this->demensions[11] in T_Placehold
	this->demensions[14] = T_Placehold.demensions[11];

	//this->demensions[15] stays the same

}

A_Matrix4x4::~A_Matrix4x4() {



}