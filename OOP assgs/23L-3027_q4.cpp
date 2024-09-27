
/// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;

// function to take user input for an array of integers

void input_ele(int* ptr, int size)
{
	cout << "enter the integers : (note : integers should be positive) " << endl;
	cout << endl;

	int input = 0;

	// loop to input elements into the array

	for (int i = 0; i < size; i++)
	{
		cout << "enter the element at index " << i << " : " << endl;
		cin >> input;

		if (input < 0) // check if the input is negative and prompt the user to try again
		{
			cout << "invalid input. try again : " << endl;
			i--;
		}

		else
			*(ptr + i) = input;  // assign valid input to the array
	}
}

// function to display the array of integers

void display_arr(int* ptr, int size)
{
	cout << "array of integers : " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << " ";
	}
}

// function to get divisors for each element in the array

int** GetDivisors(int* arr, int size)
{
    static int** ptr2 = new int* [size];  // static 2D array to store divisors
	int* count = new int[size];   //1D array to store the total divisors in each row

	for (int i = 0; i < size; i++)  // loop through each element in the array
	{

		*(ptr2 + i) = new int[size];  // allocate memory for each row of the 2D array

        int k = 0;

		for (int div = 2; div < *(arr + i); div++)    // loop to find divisors of the current element
		{

			if (*(arr + i) % div == 0)  // check if 'div' is a divisor
			{

				*(*(ptr2 + i) + k) = div;  // store the divisor in the row of the 2D array
				k++;
			}
		}

		*(*(ptr2 + i) + k) = -1;  // mark the end of the row with -1

		*(count + i) = k + 1;    // store the no. of divisors in the count array
	}

	cout << endl;

	// display the array containing divisors

	cout << "array containing divisors : " << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < *(count + i); j++)
		{
			cout << *(*(ptr2 + i) + j) << " ";
		}
		cout << endl;
	}

	return ptr2;

	// deallocate memory for the array of pointers
	for (int i = 0; i < size; i++)
	{
		delete[] ptr2[i];
	}
	delete[] ptr2;

	// deallocate memory for the count array
	delete[] count;

}

int main()
{
	int size = 0;
	cout << "enter the total number of integers :  " << endl;
	cin >> size;

	int* ptr1 = new int[size];  // dynamic memory allocation for the array of integers

	input_ele(ptr1, size);   // call function to input elements into the array
	cout << endl;

	display_arr(ptr1, size);   // call function to display the array of integers
	cout << endl;

	int** div_arr = GetDivisors(ptr1, size);  // call function to get divisors for each element in the array
	cout << endl;


	// clean up dynamically allocated memory

	delete[] ptr1;
	ptr1 = nullptr;

	for (int i = 0; i < size; i++)
	{
		delete[] div_arr[i];
	}
	delete[] div_arr;
	div_arr = nullptr;

	return 0;

}