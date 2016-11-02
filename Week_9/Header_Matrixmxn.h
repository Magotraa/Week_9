#pragma once

#include<iostream>
#include "VectorND.h"
#include<vector>


template<class T>
class Matrixmxn_ 
{
	public:

	int num_rows_;
	int num_cols_;
	T *values_;
	std::vector<VectorND<int>* > row_list;

	Matrixmxn_()
		: values_(nullptr), num_rows_(0), num_cols_(0)
	{};
	Matrixmxn_(const int& _m, const int& _n)
		: values_(nullptr), num_rows_(_m), num_cols_(_n)
	{
	
		initialize(num_rows_, num_cols_);

	}


	~Matrixmxn_(void)
	{
		if (values_ != 0) delete[] values_;
		
	}



	//initialize the matrix
	void initialize(const int& _m, const int& _n)
	{
		num_rows_ = _m;
		num_cols_ = _n;

		delete(values_);



		{
			//first array 

			for(int i=0; i<num_rows_;i++)
			row_list.push_back(new VectorND<int>);
			
			for (int i = 0; i < num_rows_; i++)				
				row_list[i] = new VectorND<int>(num_cols_);

			//second array
			
			//values_ = new T[num_rows_];
			//values_[i] =T(num_cols_);

			/*values_ = new VectorND<int>[num_rows_ ];
			
			for (int i = 0; i < num_rows_; i++)
				values_[i] =     VectorND<int>(num_cols_);*/

		}
	}



	VectorND<int>& operator*(const VectorND<int>& rhs) {
		VectorND<int> ans(num_rows_);

		for (int i = 0; i < num_rows_; i++)
		{			
			ans.values_[i] = row_list[i]->operator*(rhs);
		}


		std::cout << "  "  << std::endl;

		std::cout << ans << std::endl;

 		return ans;
	}









};