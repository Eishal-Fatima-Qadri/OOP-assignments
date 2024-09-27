#pragma once

//header file

class Date {  //creating a class by the name "Date"
private:
	
	//private data members
	int Day;
	int Month;
	int Year;

public:

	Date();  //default constructor

	Date(int day, int month, int year);  //parameterized constructor

	~Date();  //destructor

	//setters

	void set_day(int day);
	

	void set_month(int month);
	

	void set_year(int year);
	

	//getters

	int get_day();
	int get_month();
	int get_year();
	
	//print member function to print details of the current object
	void print();

	//input member function to take input from the user 
	void input();

	static int Compare(const Date& obj1, const Date& obj2); //made static to associate the function 
	                                                       //directly with the class rather than any
	                                                      //individual instance (created object)

	Date increment_month();  //member function to increment the date (month)
	
};
