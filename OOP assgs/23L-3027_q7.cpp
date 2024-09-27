

 /// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;

 function to find achievers based on a given array containing scores

int** find_Achievers(int** arr, int r, int c, int* &size)
{
	static int** achievers = new int* [r];  // dynamically allocate memory for achievers array
	

	for (int i = 0; i < r; i++)   // iterate through the scores of each country
	{
		*(achievers + i) = new int[c]; // allocate memory for each country's achievers list
		int k = 0;
		for (int j = 0; j < c; j++)
		{
			if (*(*(arr + i) + j) > 300) // if the score is greater than 300, consider it as an achiever
			{
				*(*(achievers + i) + k) = *(*(arr + i) + j);
				k++;
			}
		}
		*(size + i) = k + 1;  // 1D array to store the size of each row 
		*(*(achievers + i) + k) = -1;   // mark the end of each row with -1
	}
	return achievers;
}


int main()
{
	int R = 0, C = 0; 

	cout << "enter the total number of countries : " << endl;
	cin >> R;

	cout << "enter the total number of scores for each country : " << endl;
	cin >> C;

	char** countries = new char* [R];  //allocate memory for an array containing country names

	cin.ignore();

	for (int i = 0; i < R; i++)    
	{
		*(countries + i) = new char[50];

		cout << "enter the name of country " << i+1 << ": " << endl;

		cin.getline(*(countries+i), 50);   // input country names
    }


	int** scores = new int*[R];    //allocate memory for an array containing scores of each country

	cout << "enter the score list : " << endl;

	for (int i = 0; i < R; i++)
	{
		*(scores + i) = new int[C];

		cout << "enter the score list of " << *(countries + i) << " :" << endl;

		for (int j = 0; j < C; j++)
		{
			cin >> *(*(scores + i)+j);  // input scores for each country
		}
	}


	cout << endl;

	cout << "SCORE LIST : " << endl;  // display the initial score list

	for (int i = 0; i < R; i++)
	{
		cout << *(countries + i);
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << *(*(scores + i) + j) << " ";
		}
		cout << endl;
	}

	cout << endl;

	int* size = new int[R];
	int** achievers_arr = find_Achievers(scores, R, C,size);  // call the function to pick out the achievers

	cout << "ACHIEVERS LIST :" << endl;  // display the achievers list 

	for (int i = 0; i < R; i++)
	{
		cout << *(countries + i);
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < *(size+i); j++)
		{
			cout << *(*(achievers_arr + i) + j) << " ";
		}
		cout << endl;
	}

	 //free the memory allocated for countries,scores and achievers_arr

    for (int i = 0; i < R; i++)
	{
		delete[] * (countries + i);
		delete[] * (scores + i);
		delete[] * (achievers_arr + i);
	}

	delete[] countries;
	countries = nullptr;

	delete[] scores;
	scores = nullptr;

	delete[] achievers_arr;
	achievers_arr = nullptr;

	return 0;

}