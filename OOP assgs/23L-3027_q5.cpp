
/// name : eishal fatima    section : BSSE-2A   roll no.:23L-3027

#include<iostream>
using namespace std;

int string_length(char* arr) {  //function to find the length of a string
    int k = 0;
    while (*(arr + k) != '\0') {
        k++;
    }
    return k;
}

void string_copy(char* arr2, char* arr1) {  //function to copy the contents of a string array into another array
    int k = 0;
    int p = 0;
    while (*(arr1 + k) != '\0') {
        if (*(arr1 + k) != 'A' && *(arr1 + k) != ' ')
        {
            *(arr2 + p) = *(arr1 + k);
            
            p++;
        }
        k++;
    }
    *(arr2 + p) = '\0'; // null-terminate the string
}


  //function to find the messages starting with A

char** Find_As(char** arr, int &count_A)
{

    // count the number of messages starting with A
  
    for (int i = 0; i < 5; i++) {
        if (*(*(arr + i)) == 'A') {
            count_A++;  // counting the number of rows for the final array
        }
    }

    // allocate memory for ptr1
    static char** ptr1 = new char* [count_A];

    // process the messages starting with 'A'
    int k = 0;
    for (int i = 0; i < 5; i++) {

        if (*(*(arr + i)) == 'A') {

            // allocate memory for the message

            ptr1[k] = new char[string_length(*(arr + i)) + 1]; // +1 for the null terminator '\0'

            // copy the entire message

            string_copy(*(ptr1 + k), *(arr + i));
            k++;
        }
    }
    return ptr1;
}

//function to display the final array

void display_array(char** ptr1, int count_A)
{

    // print the messages stored in ptr1

    cout << "final array with messages starting with A :" << endl;

    for (int i = 0; i < count_A; i++) {
        cout << *(ptr1 + i) << endl;
    }

}


int main() {

    // allocate memory for an array of pointers 

    char** arr = new char* [5];

    // allocate memory and initialize each row separately

    *(arr + 0) = new char[50] {"A hello"};
    *(arr + 1) = new char[50] {"B hi"};
    *(arr + 2) = new char[50] {"A how are you"};
    *(arr + 3) = new char[50] {"B im good"};
    *(arr + 4) = new char[50] {"A you seem busy"};

    
    int size = 0;

    //calling the functions

    Find_As(arr, size);
     
    char** ptrA = Find_As(arr, size);

    display_array(ptrA, size);

    // free memory allocated for arr and ptrA

    for (int i = 0; i < 5; i++) {
        delete[] * (arr + i);
    }
    delete[] arr;

    for (int i = 0; i < size; i++) {
        delete[] * (ptrA + i);
    }
    delete[] ptrA;

    return 0;
}






