#include "datetime.h"
#include <iostream>
using namespace std;

DateTime::DateTime()
	: Date(), Time(), dayName("Friday")
{}

DateTime::DateTime(const std::string& day, const Date& date, const Time& time)
	: Date(date), Time(time), dayName(day)
{}

DateTime::DateTime(const std::string& day, int dNumber, int mNumber, int yNumber, int hValue, int mValue)
	: Date(dNumber, mNumber, yNumber), Time(hValue, mValue), dayName(day)
{}

DateTime::DateTime(const DateTime& DT)
	: Date(DT), Time(DT), dayName(DT.dayName)
{}

DateTime::~DateTime()
{}

void DateTime::printTime() const
{
	cout << hour << "h " << minute << "m";
}

void DateTime::printDate() const
{
	// print in format 18.03.2021, 01.03.2021
	// print day
	if (day < 10)
		cout << "0";
	cout << day << ".";
	// print month
	if (month < 10)
		cout << "0";
	cout << month << ".";
	cout << year;
}

void DateTime::printDateTime() const
{
	// print in format Thursday, 18.03.2021, 11h 50m
	cout << dayName << ", ";
	printDate(); cout << ", ";
	printTime();
	cout << "  (";
	Time::printTime();
	cout << ")";
	cout << "\n";
}

void DateTime::readDateTime()
{
	cout << "Enter calendar day info:\n";
	cout << "name: "; cin >> dayName;
	readDate();
	readTime();
}