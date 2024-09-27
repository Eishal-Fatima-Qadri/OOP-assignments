
/// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;


// function to fill the 2D array with user input

void FillArray(int* arr[], int r, int pt[])  
{
	cout << "--> enter the elements of your array : " << endl;   

	for (int i = 0; i < r; i++)        // iterates through the indexes of the address array
	{
		for (int j = 0; j < *(pt + i); j++)     //iterates through the columns in each row (pt holds the column number in each row)
		{
			cout << " at index [" << i << "][" << j << "] : " << endl;
			cin >> *(*(arr + i) + j);
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

// Function to convert 2D array to 1D array and display the result

int* twoDim_to_oneDim(int* arr[], int R , int pt[] , int &size)
{
	int sum = 0;                 //variable to store the total numbers in the array(size)
	for (int i = 0; i < R; i++)                      
	{
		sum = sum + *(pt + i);  // add the number of columns in each row as, "no. of columns = no. of elements"
	}
	size = sum;      //stored in the size variable which was passed by reference. its value gets modified globally 

  	static int* ptr1 = new int[sum];  //value of ptr1 (pointer pointing to a newly allocated 1D array) is retained during function calls 

	int k = 0;
	for (int i = 0; i < R; i++)   // loop to create new 1D array for the elements
	{
		for (int j = 0; j < *(pt + i); j++)
		{
			*(ptr1 + k) = *(*(arr + i) + j);
			k++;                     // index of ptr1
		}
	}

	cout << " new 1D array : " << endl;

	for (int i = 0; i < sum; i++)
	{
		cout << *(ptr1 + i) << " ";   //displaying the new 1D arrray
	}
	cout << endl;

	return ptr1;  //returning the array


	delete[]ptr1;  //deallocating the memory space to avoid memory leaks 
	ptr1 = nullptr;  // setting the pointer to null to avoid dangling pointers
	
	
}


void SortArray(int arr[], int s)
{


	for (int i = 0; i < s; i++)       //sorting the array using BUBBLE SORT
	{
		for (int j = 0; j < (s -i-1); j++)
		{
			if (*(arr + j) > *(arr + (j + 1)))  // to arrange the elements in an ascending order
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + (j + 1));
				*(arr + (j + 1)) = temp;

			}
		}
	}

	cout << "sorted array : " << endl;   //displaying the sorted array
	
	for (int i = 0; i < s; i++)
	{
		cout << *(arr + i) << " ";
	}

}

int main()
{    
	int size = 0;
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

	int** ptr = new int* [R];    // Dynamic allocation of an array of pointers 'ptr' to represent rows in a 2D array.
                                // Each pointer points to an array of integers representing columns in the 2D array.

	for (int i = 0; i < R; i++)
	{

		*(ptr + i) = new int[*(pt + i)];   // accessing the size of each column through the column array

	}
  

	FillArray(ptr, R, pt);

	cout << endl;

	int* one_dim_arr = twoDim_to_oneDim(ptr, R, pt, size);

	cout << endl;

	SortArray(one_dim_arr, size);

	cout << endl;

	// Deallocate memory for the 2D array

	for (int i = 0; i < R; i++) 
	{
		delete[] ptr[i];
	}

	delete[]ptr;

	// Deallocate memory for the 1D column array 

	delete[]pt;
	pt = nullptr;

	// Deallocate memory for the 1D array

	delete[] one_dim_arr;
	one_dim_arr = nullptr;

	return 0;

}