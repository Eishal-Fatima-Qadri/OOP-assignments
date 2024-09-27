#pragma once

#include<iostream>
using namespace std;

class Sparse_Matrix {

private :
	int rows;
	int columns;
	int** sparse_matrix;


public:

	//constructors
	Sparse_Matrix(); //default
	Sparse_Matrix(const string& filename); //parameterized
	Sparse_Matrix(const Sparse_Matrix& other); //copy

	void display();
	

	//destructor
    ~Sparse_Matrix(); 


	//assignment operator
	Sparse_Matrix& operator=(const Sparse_Matrix& other);


	//overloaded operators
	Sparse_Matrix& operator+(const Sparse_Matrix& other)const; // (+)
	Sparse_Matrix& operator-(const Sparse_Matrix& other)const; // (-)
	Sparse_Matrix& operator*(const Sparse_Matrix& other)const; // (*)


	//bool operators
	bool operator==(const Sparse_Matrix& other)const; // (==)
	bool operator<=(const Sparse_Matrix& other)const; // (<=)
	bool operator>=(const Sparse_Matrix& other)const; // (>=)

	// function to compress a sparse matrix
	Sparse_Matrix& compress(const Sparse_Matrix &arr );

	void input();

	void transpose();

	//overload [] operator
	int* operator[](int index);

	//input output overload
	friend istream& operator>>(istream& input, Sparse_Matrix& matrix);
	friend ostream& operator<<(ostream& output, const Sparse_Matrix& matrix);
	
};

