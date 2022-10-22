#include "holiday.h"
#include <iostream>
using namespace std;

Holiday::Holiday()
	: Date(), holidayName("New Year")
{}

Holiday::Holiday(const std::string& name, const Date& D)
	: Date(D), holidayName(name)
{}

Holiday::Holiday(const std::string& name, int day, int month, int year)
	: Date(day, month, year), holidayName(name)
{}

Holiday::Holiday(const Holiday& H)
	: Date(H), holidayName(H.holidayName)
{}

Holiday::~Holiday()
{}

void Holiday::printHoliday() const
{
	// print in format: Easter (02/05/2021)
	cout << holidayName << " (";
	printDate();
	//cout << day << " " << month << " " << year;
	cout << ")\n";
}

void Holiday::readHoliday()
{
	cout << "Enter holiday info:\n";
	cout << "holiday name: "; cin >> holidayName;
	readDate();
}