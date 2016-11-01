#pragma once
#include "VectorND.h"
#include <fstream>

template<class T>
class MatrixMN
{
public:
	int num_rows_;  
	int num_cols_;  
	T *values_;

	MatrixMN()
		: values_(nullptr), num_rows_(0), num_cols_(0)
	{};
	MatrixMN(const int& _m, const int& _n)
		: values_(nullptr), num_rows_(0), num_cols_(0)
	{}

	void initialize(const int& _m, const int& _n)
	{	
		num_rows_ = _m;
		num_cols_ = _n;

		delete(values_);

		const int num_all = num_rows_ * num_cols_;

		assert((double)num_rows_ * (double)num_cols_ <= (double)INT_MAX);


		
		
		{
			values_ = new T[num_all];
			
				for (int i = 0; i < num_all; i++)
					values_[i] = (T)0;
		}
	}


	



	int get1DIndex(const int& row, const int& column) const
	{
		assert(row >= 0);
		assert(column >= 0);
		assert(row <= num_rows_);
		assert(row <= num_cols_);

		// column = i, row = j
		return column + row * num_cols_;      
	}

	T& getValue(const int& row, const int& column) const
	{
		return values_[get1DIndex(row, column)];
	}


	void cout()
	{
		for (int row = 0; row < num_rows_; row++)
		{
			for (int col = 0; col < num_cols_; col++)
			{
				std::cout << getValue(row, col) << "         ";
			}

			std::cout << std::endl;
		}
	}






	void multiply(const VectorND<T>& vector, VectorND<T>& result) const
	{

#pragma omp parallel for
		for (int row = 0; row < num_rows_; row++)
		{
			result.values_[row] = (T)0;

			int ix = row*num_cols_;
			T temp;

			for (int col = 0; col < num_cols_; col++, ix++)
			{
				temp = values_[ix];
				temp *= vector.values_[col];

				result.values_[row] += temp;
			}
		}
	}





};
