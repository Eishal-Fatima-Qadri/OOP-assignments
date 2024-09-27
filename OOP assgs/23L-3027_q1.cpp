
 ///name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;


void removezeros(int* arr[], int rows, int cols)  // function to find and remove zeros
{
	int** ptrr = new int* [rows];    // double pointer pointing to a pointer array(vertical 1D) that stores addresses 
	cout << "new array : " << endl;

	for (int i = 0; i < rows; i++)   //loop to control the row number
	{
		*(ptrr + i) = new int[cols];  // creating 1D arrays to store the elements in each row (after one row is completed)

		int k = 0;

		for (int j = 0; j < cols; j++)  //loop to control the column number
		{
		
			if (*(*(arr + i) + j) != 0)   
			{
				*(*(ptrr + i) + k) = *(*(arr + i) + j);   //copy elements from the passed array to our new array

				k++;    // k keeps track of the number of non zero elements
			}
		}

		for (int j = 0; j < k; j++)   //print the non zero elements uptil an index < k
		{

			cout << *(*(ptrr + i) + j) << " ";

		}
		cout << endl;
	}

	//deallocate the memory

	for (int i = 0; i < rows; i++)
	{
		delete ptrr[i];
	}

	delete[]ptrr;


}


    void inputarray(int** ptr, int R, int C)  //function to input array elements
    {

		for (int i = 0; i < R; i++)
		{
			*(ptr + i) = new int[C];   // creating 1D arrays for each row

			for (int j = 0; j < C; j++)
			{
				cout << " index [" << i << "][" << j << "]" << endl;

				cin >> *(*(ptr + i) + j);  //i controls the row number, j controls the column number.
				                          // +1 in i moves the address ahead by 8 bytes in the vertical 1D arr  
										 // +1 in j moves the address ahead by 4 bytes in each horizontal 1D arr
			}
		}

    }

	void outputarray(int** ptr, int R, int C)  // function to display the original array 
	{
		cout << "original array : " << endl;

		for (int i = 0; i < R; i++)
		{

			for (int j = 0; j < C; j++)
			{

				cout << *(*(ptr + i) + j) << " ";

			}
			cout << endl;
		}
	}


int main()
{
	int R = 0, C = 0;

	cout << "enter the rows : "; 
	cin >> R;   // rows of the 2D array

	cout << "enter the columns : ";
	cin >> C;  //columns of the 2D array


	int** ptr = nullptr;  // initializing a double pointer 
	ptr = new int* [R];  // Dynamic allocation of an array of pointers 'ptr' to represent rows in a 2D array.
                      //  Each pointer points to an array of integers representing columns in the 2D array.
	
	// calling the functions : 

	inputarray(ptr, R, C);    

	outputarray(ptr, R, C);

	removezeros(ptr, R, C);
	
	//deallocate memory

	for (int i = 0; i < R; i++)
	{
		delete ptr[i];
	}

	delete[]ptr;

	system("pause");

	return 0;

}












