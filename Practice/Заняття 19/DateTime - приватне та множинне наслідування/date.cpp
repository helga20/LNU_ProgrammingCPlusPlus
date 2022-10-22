#include "date.h"
#include <iostream>
using namespace std;

Date::Date() : day(1), month(1), year(2021)
{}

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{}

Date::Date(const Date& D) : day(D.day), month(D.month), year(D.year)
{}

Date::~Date()
{}

void Date::printDate() const
{
	// print in format 18/03/2021, 01/03/2021, 22/12/2021
	// print day
	if (day < 10)
		cout << "0";
	cout << day << "/";
	// print month
	if (month < 10)
		cout << "0";
	cout << month << "/";
	cout << year;
}

void Date::readDate()
{
	cout << "Enter Date details:\n";
	cout << "day (01-31): "; cin >> day;
	cout << "month (01-12): "; cin >> month;
	cout << "year (01-inf): "; cin >> year;
}