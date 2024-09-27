
#include<iostream>
#include<fstream>
#include"Q2.h"

using namespace std;

Sparse_Matrix::Sparse_Matrix()  // default constructor implementation 
{
	cout << "default constructor called" << endl;
	rows = 0;
	columns = 0;
	sparse_matrix = nullptr;
}

Sparse_Matrix::Sparse_Matrix(const string& filename) // parameterized constructor implementation 
{
	cout << "parameterized constructor called" << endl;
	ifstream input(filename);
	input >> rows >> columns;  // input the first 2 lines for row no. and col no.

	sparse_matrix = new int* [rows];  // allocate space for the matrix (not compressed)

	for (int i = 0; i < rows; i++)
	{
		*(sparse_matrix + i) = new int[columns];  // allocate space for each row

		for (int j = 0; j < columns; j++)
		{
			input >> *(*(sparse_matrix + i) + j);  // read and input the elements into the array

		}
	}

}

void Sparse_Matrix::display()  // function to display a matrix 
{
	cout << "sparse matrix : " << endl;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this-> columns; j++)
		{
			cout << *(*(sparse_matrix + i) + j) << " ";
		}

		cout << endl;
	}
}


 Sparse_Matrix::~Sparse_Matrix()  // destructor implementation 
 {
	 for (int i = 0; i < rows; i++)
	 {
		 delete[]sparse_matrix[i];  // deallocate memory
	 }
		 delete[]sparse_matrix;
	 
	 cout << "memory deallocated successfully" << endl;

	 sparse_matrix = nullptr; 

	 cout << "destructror called" << endl;
 }

 Sparse_Matrix::Sparse_Matrix(const Sparse_Matrix& other)  // copy constructor implementation 
 {
	
	 this->rows = other.rows;
	 this->columns = other.columns;

	 cout << "copy constructor called" << endl;

	 // allocate memory for the new sparse_matrix
     this->sparse_matrix = new int* [other.rows];

	 for (int i = 0; i < other.rows; i++)
	 {
		 this->sparse_matrix[i] = new int[other.columns];

		 for (int j = 0; j < other.columns; j++)
		 {
			 this->sparse_matrix[i][j] = other.sparse_matrix[i][j];  // copy the elements from the passed obj to the current obj
		 }
	 }

 }


 Sparse_Matrix& Sparse_Matrix::operator=(const Sparse_Matrix& other)
 {
	 cout << "'=' overloader called" << endl;

	 this->rows = other.rows;
	 this->columns = other.columns;

	 if (this != &other)
	 {
		 if (this->sparse_matrix != nullptr)
		 {
			 //deallocate memory (if any memory was already allocated)
			 for (int i = 0; i < rows; i++)
			 {
				 delete this->sparse_matrix[i];
			 }
			 delete[] this->sparse_matrix;
		 }

		 this->sparse_matrix = new int* [rows];

		 for (int i = 0; i <rows; i++)
		 {
			 this->sparse_matrix[i] = new int[columns];

			 for (int j = 0; j < columns; j++)
			 {
				 this->sparse_matrix[i][j] = other.sparse_matrix[i][j];
 			 }
		 }
	 }

	
	 return *this;
 }


 Sparse_Matrix& Sparse_Matrix::compress(const Sparse_Matrix&arr)  //function to compress the current sparse matrix
 {
	 this->rows = 3;
	 int non_zero = 0;
	
	 for (int i = 0; i < arr.rows; i++)   //traverse the passed matrix and look for non zero elements
	 {
		 for (int j = 0; j < arr.columns; j++)
		 {
			 if (arr.sparse_matrix[i][j] != 0)
			 {
				 non_zero++;
			 }
		 }
	 }

	 //allocate memory for the row, col and val 1D arrays
	 int* row = new int[non_zero];
	 int* col = new int[non_zero];
	 int* val = new int[non_zero];

	 this->columns = non_zero;

	 int index = 0;

	 for (int i = 0; i < arr.rows; i++)
	 {
		 for (int j = 0; j < arr.columns; j++)
		 {
			if (arr.sparse_matrix[i][j] != 0)
			{
				//set the respective values
				val[index] = arr.sparse_matrix[i][j];
				row[index] = i;
				col[index] = j;

				index++;
			}
		 } 
	 }

     this->sparse_matrix = new int* [rows];  //allocate space for the new compressed form

	 for (int i = 0; i < rows; i++)
	 {
		 this->sparse_matrix[i] = new int[columns];

		 for (int j = 0; j < this->columns; j++)
		 {
			 if (i == 0)
			 {
				 this->sparse_matrix[i][j] = row[j]; //row indices at i=0
			 }
			 else if (i == 1)
			 {
				 this->sparse_matrix[i][j] = col[j]; //column indices at i=1
			 }
			 else if (i == 2)
			 {
				 this->sparse_matrix[i][j] = val[j]; //values at i=2
			 }
		 }
	 }

	 //display
	 cout << "compressed matrix :" << endl;
	 for (int i = 0; i < rows; i++)
	 {
		 if (i == 0) { cout << "row ptr : "; }
		 if (i == 1) { cout << "column : "; }
		 if (i == 2) { cout << "value : "; }

         for (int j = 0; j < columns; j++)
		 {
			 cout << this->sparse_matrix[i][j] << " ";
		 }
		 cout << endl;
	 }

	 //deallocate memory space
	 delete[]row;
	 delete[]col;
	 delete[]val;

	 row = nullptr;
	 col = nullptr;
	 val = nullptr;

	 return*this;
 }

 
 void Sparse_Matrix::input() //function to prompt the user for input
 {
	 cout << "input no. of rows of the sparse matrix : ";
	 for (int i = 0; i < 1; i++)  //check for invalid input
	 {
		 cin >> this->rows;
		 if (this->rows < 0)
		 {
			 cout << "invalid input. try again :" << endl;
			 i--;
		 }
		 else
			 break;
	 }

	 cout << "input no. of columns of the sparse matrix : ";
	 for (int i = 0; i < 1; i++) //check for invalid input
	 {
		 cin >> this->columns;
		 if (this->columns < 0)
		 {
			 cout << "invalid input. try again :" << endl;
			 i--;
		 }
		 else
			 break;
	 }

	 this->sparse_matrix = new int* [this->rows]; //allocate space

	 cout << "enter the elements of the sparse matrix :" << endl;

	 for (int i = 0; i < this->rows; i++)
	 {
		 this->sparse_matrix[i] = new int[this->columns];

		 for (int j = 0; j < this->columns; j++)
		 {
			 cout << "element at index [" << i << "][" << j << "] " << ": " << endl;
			 cin >> this->sparse_matrix[i][j];
		 }
	 }

 }
 
 Sparse_Matrix& Sparse_Matrix:: operator+(const Sparse_Matrix& other)const  // function to overload the '+' operator
 {
	static Sparse_Matrix New;

	 if (this->rows == other.rows && this->columns == other.columns)  //check if both matrices have the same order
	 {
		 New.sparse_matrix = new int* [other.rows];

		 for (int i = 0; i < other.rows; i++)
		 {
			 New.sparse_matrix[i] = new int[other.columns];

			 for (int j = 0; j < other.columns; j++)
			 {

				 New.sparse_matrix[i][j] = this->sparse_matrix[i][j] + other.sparse_matrix[i][j]; //current object + passed object
			 }
         }


		 cout << "after addition :" << endl;
		 
		 //set the rows and columns
		 New.rows = other.rows;
		 New.columns = other.columns;
	 }


	 else
		 cout << "operation cannot be performed as both the matrices differ in order" << endl;


	 return New;
 }

 
 Sparse_Matrix& Sparse_Matrix:: operator-(const Sparse_Matrix& other)const  // function to overload the '-' operator
 {
	 static Sparse_Matrix New;

	 if (this->rows == other.rows && this->columns == other.columns)  //check if both matrices have the same order
	 {
		 New.sparse_matrix = new int* [other.rows];

		 for (int i = 0; i < other.rows; i++)
		 {
			 New.sparse_matrix[i] = new int[other.columns];

			 for (int j = 0; j < other.columns; j++)
			 {

				 New.sparse_matrix[i][j] = this->sparse_matrix[i][j] - other.sparse_matrix[i][j];  //current object - passed object
			 }
		 }


		 cout << "after subtraction :" << endl;

		 //set the rows and columns
		 New.rows = other.rows;
		 New.columns = other.columns;
	 }


	 else
		 cout << "operation cannot be performed as both the matrices differ in order" << endl;


	 return New;
 }

 Sparse_Matrix& Sparse_Matrix::operator*(const Sparse_Matrix& other)const  // function to overload the '*' operator
 {
	 static Sparse_Matrix New;

	 if (this->columns != other.rows) // check if no. of columns of the current object is equal to no. rows of the passed object 
	 {
		 cout << " error. column no. of first matrix is not equal to the row no. of second matrix." << endl;
	 }

	 else if (this->columns == other.rows)
	 {
		 New.sparse_matrix = new int* [this->rows];

		 //performing multiplication :

		 for (int i = 0; i < this->rows; i++)
		 {
			 New.sparse_matrix[i] = new int[other.columns];

			 for (int j = 0; j < other.columns; j++)
			 {
				 New.sparse_matrix[i][j] = 0;

				 for (int k = 0; k < this->columns; k++)
				 {
					 New.sparse_matrix[i][j] = New.sparse_matrix[i][j] + this->sparse_matrix[i][k] * other.sparse_matrix[k][j];
				 }
			 }
		 }
	 }

	 cout << "after multiplication :" << endl;

	 //set the rows and columns
	 New.rows = this->rows;
	 New.columns = other.columns;

	 return New;
 }

 bool Sparse_Matrix:: operator==(const Sparse_Matrix& other)const
 {
	 int count = 0;
	cout << "checking the two matrices for equality...." << endl;

	if (this->rows == other.rows && this->columns == other.columns)
	{
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.columns; j++)
			{
				if (this->sparse_matrix[i][j] == other.sparse_matrix[i][j])
				{
					count++;
				}
			}
		}

		if (count == (other.rows * other.columns))
		{
			cout << "the two matrices are equal." << endl;
			return true;
		}
		else
		{
			cout<< "the two matrices are not equal. they have different elements." << endl;
			return false;
		}
			
	}
	else
	{
		cout << "the two matrices are not equal. they differ in order." << endl;
		return false;
	}
		
 }

 bool Sparse_Matrix:: operator<=(const Sparse_Matrix& other)const
 {
	 int sum1 = 0;
	 int sum2 = 0;

	 cout << "<= overloader called" << endl;

	 for (int i = 0; i < this->rows; i++)
	 {
		 for (int j = 0; j < this->columns; j++)
		 {
			 sum1 = sum1 + this->sparse_matrix[i][j];
		 }
	 }

	 for (int i = 0; i < other.rows; i++)
	 {
		 for (int j = 0; j < other.columns; j++)
		 {
			 sum2 = sum2 + other.sparse_matrix[i][j];
		 }
	 }

	 if (sum1 < sum2)
	 {
		 cout << "matrix 1 is smaller" << endl;
		 return true;
	 }

	 if (sum1 > sum2)
	 {
		 cout << "matrix 2 is smaller" << endl;
		 return false;
	 }

	 else if (sum1 == sum2)
	 {
		 cout << "both matrices have the same size." << endl;
		 return true;
	 }
		 
 }

 bool Sparse_Matrix:: operator>=(const Sparse_Matrix& other)const
 {
	 int sum1 = 0;
	 int sum2 = 0;

	 cout << ">= overloader called" << endl;

	 for (int i = 0; i < this->rows; i++)
	 {
		 for (int j = 0; j < this->columns; j++)
		 {
			 sum1 = sum1 + this->sparse_matrix[i][j];
		 }
	 }

	 for (int i = 0; i < other.rows; i++)
	 {
		 for (int j = 0; j < other.columns; j++)
		 {
			 sum2 = sum2 + other.sparse_matrix[i][j];
		 }
	 }

	 if (sum1 > sum2)
	 {
		 cout << "matrix 1 is greater." << endl;
		 return true;
	 }

	 if (sum1 < sum2)
	 {
		 cout << "matrix 2 is greater." << endl;
		 return false;
	 }

	 else if (sum1 == sum2)
	 {
		 cout << "both matrices have the same size." << endl;
		 return true;
	 }
 }
	
 void Sparse_Matrix::transpose()
 {
	 Sparse_Matrix temp;
	 temp.sparse_matrix = new int* [this->columns];

	 cout << "transposed matrix :" << endl;

	 for (int i = 0; i < this->rows; i++)
	 {
		 temp.sparse_matrix[i] = new int[this->rows];

		 for (int j = 0; j < this->columns; j++)
		 {
			 temp.sparse_matrix[i][j] = this->sparse_matrix[j][i];
		 }
	 }

	 //deallocate space for the current object

	 for (int i = 0; i < this->rows; i++)
	 {
		 delete[]this->sparse_matrix[i];
	 }
	 delete[]this->sparse_matrix;
	 this->sparse_matrix = nullptr;


	 this->sparse_matrix = new int* [this->columns];

	 for (int i = 0; i < this->columns; i++)
	 {
		 this->sparse_matrix[i] = new int[this->rows];

		 for (int j = 0; j < this->rows; j++)
		 {
			 this->sparse_matrix[i][j] = temp.sparse_matrix[i][j];
		 }
	 }

	 //display
	 for (int i = 0; i < this->columns; i++)
	 {
		 for (int j = 0; j < this->rows; j++)
		 {
			 cout << this->sparse_matrix[i][j] << " ";
		 }
		 cout << endl;
	 }

	
	 for (int i = 0; i < this->columns; i++)
	 {
		 delete[]temp.sparse_matrix[i];
	 }
	 delete[]temp.sparse_matrix;
	 temp.sparse_matrix = nullptr;


 }

 int* Sparse_Matrix:: operator[](int index)
 {
	 return this->sparse_matrix[index];
 }

 istream& operator>>(istream& input, Sparse_Matrix& matrix)
 {
	 cout << "enter no. of rows :" << endl;
	 cin >> matrix.rows;
	 cout << "enter no. of columns :" << endl;
	 cin >> matrix.columns;

	 matrix.sparse_matrix = new int* [matrix.rows];

	 cout << "enter elements :" << endl;

	 for (int i = 0; i < matrix.rows; i++)
	 {
		 matrix.sparse_matrix[i] = new int[matrix.columns];

		 for (int j = 0; j < matrix.columns; j++)
		 {
			 input >> matrix.sparse_matrix[i][j];
		 }
	 }

	 return input;
 }

 ostream& operator<<(ostream& output, const Sparse_Matrix& matrix)
 {
	 output << "output through ostream overload :" << endl;

	 for (int i = 0; i < matrix.rows; i++)
	 {
		 for (int j = 0; j < matrix.columns; j++)
		 {
			 output << matrix.sparse_matrix[i][j] << " ";
		 }
		 output << endl;
	 }

	 return output;
 }