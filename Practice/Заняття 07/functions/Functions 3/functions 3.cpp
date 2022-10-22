#include "functions 3.h"
#include <iostream>
using namespace std;
void printInfo(int day, int month, int year)
{
	cout << "Enter day: "; cin >> day;
	cout << "Enter month: "; cin >> month;
	cout << "Enter year: "; cin >> year;

	if (day < 0 )
	{
		cout << "Sorry, " << day << " is wrong!\n"; return;

	}
	if (month < 0 )
	{
		cout << "Sorry, " << month << " is wrong!\n"; return;
	}
	if (year < 0)
	{
		cout << "Sorry, " << year << " is wrong!\n"; return;
	}

	cout << "Day: " << day << "\n";
	cout << "Month: " << month << "\n";
	cout << "Year: " << year << "\n";
}
