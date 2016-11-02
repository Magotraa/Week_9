
#include<iostream>

#include"Vector3D.h"
#include"Matrix3x3.h"


#include"VectorND.h"
#include"MatrixMXN.h"



#include"Header_Matrixmxn.h"




//operator overloading

//overload streaming operator




int main()
{
	Vector3D v0(1, 2, 3);
	Vector3D v1 = Vector3D(4, 5, 6);
	Vector3D v2;
	v2 = v0 + v1;




	//
	//std::cout << v0  << std::endl;
	//std::cout << v1 << std::endl;
	//std::cout << v2 << std::endl;
	//std::cout<< "   " <<  std::endl;
	//std::cout << "             "<< std::endl;

	//// dot product
	//std::cout << v0 * v1 << std::endl;
	//std::cout << "   " << std::endl;
	//
	//std::cout << v1 * v0 << std::endl;

	//std::cout << "   " << std::endl;
	//std::cout << "             " << std::endl;


	//Matrix3x3 m(Vector3D(1, 2, 3), Vector3D(4, 5, 6), Vector3D(7, 8, 9));

	//Vector3D y = m * v0;


	//std::cout << y << std::endl;



	VectorND<int> Vec(4), result(5);

	Vec.values_[0] = 1;
	Vec.values_[1] = 2;
	Vec.values_[2] = 3;
	Vec.values_[3] = 4;




	std::cout << "Displaying the vector for Matrix mxn multiplication:" << std::endl;

	std::cout << Vec << std::endl;
	std::cout << "             " << std::endl;


//MatrixMN<int> M(5, 4);
//M.initialize(5, 4);
////M.assignAll(0);

////assigning values to the matrix MXN, here M5x4
//const int num_all = 5 * 4;
//for (int i = 00; i <= num_all; i++)
//	M.values_[i] = i + 1;


//std::cout << "Displaying the  Matrix mxn for multiplication:" << std::endl;
//M.cout();

//M.multiply(Vec, result);


//std::cout << "             " << std::endl;
//std::cout << " The output of the matrix and vector multipication is:" << std::endl;
//std::cout << "             " << std::endl;
//std::cout << "         " << result << "    " << std::endl;

//for (int i = 0; i< 3; i++)std::cout << "             " << std::endl;


	Matrixmxn_<VectorND<int>> M(5, 4);


	//Assigning the values tot he matrix
	for (int i = 0, x = 1; i < 5; i++)
		for (int j = 0 ; j < 4; j++,x++)
			M.row_list[i]->values_[j] = x ;



	std::cout << "Displaying the  Matrix mxn for multiplication:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
	
	for (int j = 0; j < 4; j++)
	{
		std::cout << "  "   << M.row_list[i]->values_[j] <<" " ;
	}

	std::cout<< " " << std::endl;
}
	
	

	VectorND<int> y(5);
	
	y.operator=(  M * Vec);



	

	//std::cout << y << std::endl;






	//VectorND<int> v(5);

	



	return 0;
};

