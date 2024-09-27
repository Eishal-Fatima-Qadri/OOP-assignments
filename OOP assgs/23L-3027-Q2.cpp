
#include<iostream>
using namespace std;

//function to take input from the user for array elements

void populate(int** arr, int rows, int columns)
{
	cout << "enter the elements of the array : " << endl;
	for (int i = 0; i < rows; i++)
	{
		*(arr + i) = new int[columns];

		for (int j = 0; j < columns; j++)
		{
			cout << "enter the element at index [" << i << "][" << j << "] :" << endl;
			cin >> *(*(arr + i) + j);
		}
	}

	//display the filled array :
	cout << endl;
	cout << "original array : " << endl;

	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < columns; j++)
		{
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
}

//function to find the transpose 

int** Find_Transpose(int** arr, int rows, int cols)
{
	int** ptr2 = new int* [cols];

	for (int i = 0; i < cols; i++)
	{
		*(ptr2 + i) = new int[rows];

		for (int j = 0; j < rows; j++)
		{
			*(*(ptr2 + i) + j) = *(*(arr + j) + i);
		}
	}

	return ptr2;
}

int main()
{
	int R = 0, C = 0;

	for (int i = 0; i < 1; i++)
	{
		cout << "enter the number of rows :" << endl;  //input number of rows
		cin >> R;
		if (R < 0)  //check for an invalid input
		{
			cout << "invalid input" << endl;
			i--;
		}

	}

	for (int i = 0; i < 1; i++)
	{
		cout << "enter the number of columns : " << endl;  //input number of columns
		cin >> C;
		if (C < 0)  //check for an invalid input
		{
			cout << "invalid input" << endl;
			i--;
		}
	}


	int** ptr1 = new int* [R]; //dynamically allocate space for a 2D pointer array

	populate(ptr1, R, C);

	int** transposed = Find_Transpose(ptr1, R, C);


	cout << "transpose of the given array : " << endl;  //display the transpose

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j <R; j++)
		{
			cout << *(*(transposed + i) + j) << " ";
		}
		cout << endl;
	}

	//DEALLICATE MEMORY TO AVOID MEMORY LEAKS

	for (int i = 0; i < R; i++)
	{
		delete[] *(ptr1+i);
	}
	delete[]ptr1;
	ptr1 = nullptr;


	for (int i = 0; i < C; i++)
	{
		delete[] *(transposed + i);
	}
	delete[]transposed;
	transposed= nullptr;

	return 0;
}