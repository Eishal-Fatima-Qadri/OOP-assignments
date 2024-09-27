#include<iostream>
using namespace std;
#include"Q2.h"

int main()
{
	///file reading
	/*Sparse_Matrix matrix("sparse.txt");
	cout << "reading matrix from the file...." << endl;
	matrix.display();*/

	///assignment operator
	//Sparse_Matrix matrix3;
	//matrix3 = matrix;  // '=' overloader called

	//cout << "after assigment :" << endl;
	//matrix3.display();

	//Sparse_Matrix comp_matrix;
	//comp_matrix.compress(matrix);


	//Sparse_Matrix user_matrix;
	//user_matrix.input();
	//user_matrix.display();
	//Sparse_Matrix comp_user;
	//comp_user.compress(user_matrix);

	///addition
	//Sparse_Matrix add_res;
    //add_res = matrix + user_matrix;   /// addition
	//add_res.display(); // non compressed matrix


	//Sparse_Matrix comp_sum; 
	//comp_sum.compress(add_res);
    
 
    ///subtraction
	//Sparse_Matrix sub_res;
	//sub_res = matrix - user_matrix;  /// subtraction
	//sub_res.display();

	//Sparse_Matrix comp_diff;
	//comp_diff.compress(sub_res);

	///multiplication
    //Sparse_Matrix mult1;
	//mult1.input();
	//Sparse_Matrix mult2;
	//mult2.input();

    // Sparse_Matrix mult_res;

	//mult_res = mult1 * mult2;
	//mult_res.display();

	//Sparse_Matrix comp_prod;
	//comp_prod.compress(mult_res);*/

	//if (mult1 == mult2)
	//{
	//	cout << "result displayed." << endl;
	//}


	///transpose 
	/*Sparse_Matrix tran;
	tran.input();
	tran.transpose();
	Sparse_Matrix comp_tran;
	comp_tran.compress(tran);*/
	

	///overloaders >= <= 
	/*Sparse_Matrix mat1;
	mat1.input();
	Sparse_Matrix mat2;
	mat2.input();

	if (mat1 <= mat2)
	{
		cout << "result displayed for <= overloader." << endl;
	}

	if (mat1 >= mat2)
	{
		cout << "result displayed for >= overloader." << endl;
	}*/

	/// subsript operator
    /*matrix[0][0] = 10;
	matrix.display();

	cout << endl;

	cout << matrix[0][1] << endl;*/

	//Sparse_Matrix matrix2 = matrix; //copy cons called
	//matrix2.display();


	/// input and output overload
	/*Sparse_Matrix in_matrix;
	cin >> in_matrix;
    cout << in_matrix;*/

}