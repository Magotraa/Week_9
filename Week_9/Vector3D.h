#pragma once
class Vector3D {


public:
	int x_;
	int y_;
	int z_;

	Vector3D()
		:x_(0), y_(0), z_(0)

	{}

	Vector3D(const int& x, const int& y, const int& z)
		:x_(x), y_(y), z_(z)
	{}

	//overloading plus additive operation
	Vector3D& operator+(const Vector3D& input)
	{
		Vector3D vec;
	vec.x_ = 	this->x_ + input.x_;
	vec.y_ =  this->y_ + input.y_;
	vec.z_ =  this->z_ + input.z_;
		return  	vec;
	}


	// dot product 
	int operator*(const Vector3D& input) {

		int ans;
		ans = this->x_ * input.x_;
		ans += this->y_ * input.y_;
		ans += this->z_ * input.z_;
		return ans;
	}

};

std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {

	os << vec.x_ << "  " << vec.y_ << "  " << vec.z_ << std::endl;
	return os;

}




