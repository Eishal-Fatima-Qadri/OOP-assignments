
/// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;

// function to fill the 2D array with user input

void FillArray(int* arr[], int r, int pt[])  
{
	cout << "--> enter the elements of your array (0s and 1s) : " << endl;   
	int input = 0;
	for (int i = 0; i < r; i++)        // iterates through the indexes of the address array
	{
		for (int j = 0; j < *(pt + i); j++)     //iterates through the columns in each row (pt holds the column number in each row)
		{
			// prompt the user for input at each index

			cout << " at index [" << i << "][" << j << "] : " << endl;
			cin >> input;

			if (input != 0 && input != 1)  // check if the input is valid (0 or 1)
			{
				cout << "invalid input. try again :" << endl;   // if not valid, ask the user to enter a valid input for the same index
				j--;
			}
			else
				*(*(arr + i) + j) = input;  // store the valid input in the array
		}
	}

	cout << endl;
	cout << "original array : " << endl;

	for (int i = 0; i < r; i++)   // display the user's original array
	{

		for (int j = 0; j < *(pt + i); j++)   
		{

			cout << *(*(arr + i) + j) << " ";

		}
		cout << endl;
	}

}

// function to compress the 2D array based on a given value (0 or 1)
                  
int** compress(int* image[], int rows, int columns, int value)
{
	// dynamic memory allocation for compressed array and supporting arrays

	static int** ptr1 = new int*[rows];
    int* count = new int[rows];
    int* ptr2 = new int[columns];

	int k = 0;
	int p = 0;

	// compression for value 0

	if (value == 0)
	{
		for (int i = 0; i < rows; i++)
		{
			
			int track = 0;

			for (int j = 0; j < columns; j++)
			{
				if (*(*(image+i)+ j) == 0)  // check if the element is 0 and compress accordingly
				{
					*(ptr2 + p) = j;
					track++;
					p++;
	
				}
			}

			// store the count of 0s and their indices

			*(count + i) = track;   
            *(ptr1 + i) = new int[track + 1];
            *(*(ptr1 + i) + 0) = track;

			for (int p = 1; p <= *(count + i); p++)
			{

				*(*(ptr1 + i) + p) = *(ptr2 + k);  // store the indices of 0s in the compressed array
			
			     k++;
			}
		}

		cout << "compressed array : " << endl;   // display the compressed array for value 0

		for (int i = 0; i < rows; i++)  
		{
			for (int j = 0; j < *(count + i)+1; j++)
			{
				cout << *(*(ptr1 + i) + j) << " ";
			}
			
			cout << endl;
		}
		
		return ptr1;
	}


	// compression for value 1

	if (value == 1)
	{
		for (int i = 0; i < rows; i++)
		{

			int track = 0;

			for (int j = 0; j < columns; j++)
			{
				if (*(*(image + i) + j) == 1)
				{
					*(ptr2 + p) = j;
					track++;
					p++;

				}
			}

			*(count + i) = track;
			*(ptr1 + i) = new int[track + 1];
			*(*(ptr1 + i) + 0) = track;

			for (int p = 1; p <= *(count + i); p++)
			{

				*(*(ptr1 + i) + p) = *(ptr2 + k);

				k++;
			}
		}

		cout << "compressed array " << endl;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < *(count + i) + 1; j++)
			{
				cout << *(*(ptr1 + i) + j) << " ";
			}

			cout << endl;
		}

		return ptr1;
	}

}


int main()
{  
	int C = 0;
	int R = 0;
	cout << "--> enter the number of rows : " << endl;  // input the no. of rows
	cin >> R;

	int* pt = new int[R];      //dynamic allocation of an integer array to store no . of columns in each row

	cout << "--> enter the number of columns : " << endl;   //input no. of columns using a loop

	for (int i = 0; i < R; i++)
	{
		cout << "--> enter the no. of columns in row " << i << ": " << endl;
		cin >> C;

		if (C >= 0)   //check for negative numbers
		{
			*(pt + i) = C;
		}

		else
		{
			cout << "invalid input. try again : " << endl;
			i--;
		}

    }

	int** ptr = new int* [R];    // Dynamic allocation of an array of pointers 'ptr' to represent rows in a 2D array. (0s and 1s)
                                // Each pointer points to an array of integers representing columns in the 2D array.

	for (int i = 0; i < R; i++)
	{

		*(ptr + i) = new int[*(pt + i)];   // accessing the size of each column through the column array

	}
    

	// call function to fill the array with user input

	FillArray(ptr, R, pt);

	int opt = 0;

	cout << "what value would you like to use for compression? (1 or 0)" << endl;  // input the value for compression (0 or 1)
	cin >> opt;  // value

	cout << endl;

	// call function to compress the array based on the specified value

	int** compressedarr = compress(ptr, R, C, opt);


	// Clean up dynamically allocated memory

	delete[]pt;
	pt = nullptr;

	for (int i = 0; i < R; i++)
	{
		delete[] ptr[i];
		delete[] compressedarr[i];
	}

	delete[] ptr;
	delete[] compressedarr;

	ptr = nullptr;
	compressedarr = nullptr;


	return 0;
}

