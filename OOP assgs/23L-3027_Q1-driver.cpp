
//testing cpp file

#include"Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date date1;   //default constructor called
	date1.print();

	Date independence_day(14, 8, 2018);  //parameterized constructor
	independence_day.print();
	
	date1.input();
	date1.print();

	Date xmasDay;  //default constructor called
	xmasDay.print();

	//setting the values using setters

	xmasDay.set_day(25);
	xmasDay.set_month(12);
	xmasDay.set_year(2018);

	//printing the date using getters 

	cout << "xmas day : " << xmasDay.get_day()<<" / " << xmasDay.get_month()<<" / " << xmasDay.get_year() << endl;

	int result = Date::Compare(independence_day, xmasDay);  //storing comparison result 

	cout << "result of comparison : " << result << endl;

	Date date2 = date1.increment_month();  //storing returned object in a newly created object "date2" (creates a copy constructor)
	date2.print();

	return 0;

}