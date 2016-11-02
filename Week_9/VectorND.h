#pragma once
#include <assert.h>
#include <iostream>
#include <fstream>

template<class TT>
class VectorND {

	  
public:
	int n_dimension_;
	TT *values_;

	VectorND()
		:n_dimension_(0),  values_(nullptr)
	{};

	//VectorND(const int& x, const int& y, const int& z)
	//	:x_(x), y_(y), z_(z)
	//{}

	VectorND(const int& number)
	{
		values_ = nullptr;

		initialize(number);
	}

	void initialize(const int& number)
	{		

		assert(number >= 0);


		delete(values_);
		values_ = new TT[number];



         n_dimension_ = number;
		for (int i = 0; i < n_dimension_; i++)
			values_[i] = TT();
		}


	~VectorND(void)
	{
		if (values_ != 0) delete[] values_;
		n_dimension_ = 0;
	}



	//overloading plus additive operation
	//VectorND& operator+(const VectorND& input)
	//{
	//	VectorND vec;
	//	vec.x_ = this->x_ + input.x_;
	//	vec.y_ = this->y_ + input.y_;
	//	vec.z_ = this->z_ + input.z_;
	//	return  	vec;
	//}




	void operator=(const VectorND<TT> & vector) const
	{


		for (int i = 0; i<n_dimension_; i++)
			values_[i] = vector.values_[i];


	}

VectorND<TT> operator+(const VectorND & vector) const
{

	VectorND<TT> result(n_dimension_);

	for (int i = 0; i<n_dimension_; i++) 
		result[i] = values_[i] + vector.values_[i];

	return result;
}



	// dot product 
	//int operator*(const VectorND& input) {

	//	int ans;
	//	ans = this->x_ * input.x_;
	//	ans += this->y_ * input.y_;
	//	ans += this->z_ * input.z_;
	//	return ans;
	//}



	// dot product 
int operator*(const VectorND<TT>& input) {
	int result = 0;

	for (int i = 0; i < n_dimension_; i++)
	{
		result += values_[i] * input.values_[i];
	}

	return result;
}







};


//dot  product
template<class TT>
void dotProduct(const VectorND<TT>& v1, const VectorND<TT>& v2, TT& sum)
{
	assert(v1.num_dimension_ == v2.num_dimension_);

	sum = 0;

	for (int i = 0; i < v1.num_dimension_; i++)
		sum += v1.values_[i] * v2.values_[i];
}

//std::ostream& operator<<(std::ostream& os, const VectorND& vec) {
//
//	os << vec.x_ << "  " << vec.y_ << "  " << vec.z_ << std::endl;
//	return os;
//
//}


template<class TT>
std::ostream& operator<<(std::ostream& output, const VectorND<TT>& v)
{
	for (int i = 0; i<v.n_dimension_; i++) output << v.values_[i] << " ";
	output << std::flush;
	//	output << std::endl;
	return output;
}