
//implementation file

#include"Date.h"
using namespace std;
#include<iostream>

//all member functions have been implemented in this file 

Date::Date()
{

	cout << "default constructor called " << endl;
	
	Day = 1;
	Month = 1;
	Year = 1926;
}


Date::Date(int day, int month, int year)
{
	cout << "overloaded function called" << endl;
	Day = day;
	Month = month;
	Year = year;
}

int Date::get_day()
{
	return Day;
}

int Date::get_month()
{
	return Month;
}

int Date::get_year()
{
	return Year;
}

void Date::print()
{
	cout << "date : " << endl << Day << " / " <<  Month <<" / "  << Year << endl;
}

Date:: ~Date()
{
	cout << "destructor called" << endl;
}

void Date::input()
{
	cout << "enter a date : " << endl;

	cout << "Day :";
	for (int i = 0; i < 1; i++)
	{
		cin >> Day;
		if (Day < 0) {
			cout << "invalid day. retry : " << endl;
			i--;
		}
	}


	cout << "Month : ";
	for (int i = 0; i < 1; i++)
	{
		cin >> Month;
		if (Month < 0) {
			cout << "invalid month. retry : " << endl;
			i--;
		}
	}


	cout << "Year :";
	for (int i = 0; i < 1; i++)
	{
		cin >> Year;
		if (Year < 0) {
			cout << "invalid year. retry : " << endl;
			i--;
		}
	}
}

//setters

void Date::set_day(int day)
{
	Day = day;
}

void Date::set_month(int month)
{
	Month = month;
}

void Date::set_year(int year)
{
	Year = year;
}


int Date::Compare(const Date& obj1, const Date& obj2)
{
	if (obj1.Year > obj2.Year)
	{
		return 1;
	}
	else if (obj1.Year < obj2.Year)
	{
		return -1;
	}

	else if (obj1.Year == obj2.Year)
	{
		if (obj1.Month > obj2.Month)
		{
			return 1;
		}
		else if (obj1.Month < obj2.Month)
		{
			return -1;
		}
	}

	else if (obj1.Month == obj2.Month)
	{
		if (obj1.Day > obj2.Day)
		{
			return 1;
		}
		else if (obj1.Day < obj2.Day)
		{
			return -1;
		}
	}

	else
		return 0;
}

Date Date:: increment_month()
{
	Date obj2;
	obj2.Month = (this->Month) + 1;

	return obj2;
}

