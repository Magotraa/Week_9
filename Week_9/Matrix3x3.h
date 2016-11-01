#pragma once
#include"Vector3D.h"


class Matrix3x3 {
public:
	Vector3D row0_, row1_, row2_;

	Matrix3x3(const Vector3D& _r0, const Vector3D& _r1, const Vector3D& _r2)
		:row0_(_r0), row1_(_r1), row2_(_r2)
	{

	}



//multiplication of matrix383  and a vector3d 
	Vector3D operator*(const Vector3D& rhs)
	{
		Vector3D ans;

		ans.x_ = row0_ * rhs;
		ans.y_ = row1_ * rhs;
		ans.z_ = row2_ * rhs;

		return ans;

	}

//Vector3D 


};
