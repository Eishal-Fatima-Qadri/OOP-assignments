
 /// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;

int string_length(char arr[]) //function to find the length of a string
{
	int k = 0;
	while ((*arr+k) != '\0')
	{
		k++;
	}
	return k;
}

int main()
{
	int rows = 0;

	// input string containing words separated by '#' symbol

	char words[200] = { "abandon discontinue vacate#absent missing unavailable#cable wire#calculate compute determine measure#safety security refuge"};

	for (int i = 0; *(words+i) != '\0'; i++)  //loop to find no. of rows (that is determined by no. of '#' +1)
	{
		if (*(words + i) == '#')
		{
			rows++;
		}
	}
	rows = rows + 1;  // +1 for the last row after the last #


	string** ptr1 = new string * [rows];  // Dynamic allocation of an array of pointers 'ptr1' (of string type)
//                                      // Each pointer points to a string stored in a different row
	  
	int* size = new int[rows];   //size 1D array to store the length of each string

	int k = 0, p = 0;


	// loop to travserse the input string and assign substrings to the dynamic array of pointers

	for (int i = 0; *(words + i) != '\0'; i++)
	{
		if (p == 0) 
		{
			*(ptr1 + k) = new string;  //allocate memory for each string in the array
		}

		if (*(words + i) != '#' && *(words + i) != ' ')
		{
			**(ptr1 + k) = **(ptr1 + k) + *(words + i);  // concatenate characters to form each word
			p++;
		}

		if (*(words + i) == '#' || *(words + (i+1)) == '\0')
		{
			*(size+k) = p; // store the length of each word
			k++;
			p = 0;
		}
	}


	cout << "array : " << endl;

	for (int i = 0; i < rows; i++) 
	{
		cout << "ptr " << i << ": " << *(*(ptr1+i)) << endl;  // output each string stored in the array of pointers

	}

	//deallocate memory

	for (int i = 0; i < rows; i++)
	{
		delete ptr1[i];
	}

	delete[] ptr1;
    ptr1 = nullptr;

	delete[]size;
	size = nullptr;


	return 0;
}



