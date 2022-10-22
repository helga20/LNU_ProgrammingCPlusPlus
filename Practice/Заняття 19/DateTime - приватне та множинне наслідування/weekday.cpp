#include "weekday.h"
#include <iostream>
using namespace std;

WeekDay::WeekDay() : dayName("Friday"), dayDate()
{}

WeekDay::WeekDay(const std::string& name, const Date& D) : dayName(name), dayDate(D)
{}

WeekDay::WeekDay(const std::string& name, int day, int month, int year)
	: dayName(name), dayDate(day, month, year)
{}

WeekDay::WeekDay(const WeekDay& WD) : dayName(WD.dayName), dayDate(WD.dayDate)
{}

WeekDay::~WeekDay()
{}

void WeekDay::printWeekDay() const
{
	// print in format "Thursday, 18/03/2021"
	cout << "Day of the week: ";
	cout << dayName << ", ";
	dayDate.printDate();
	cout << "\n";
}

void WeekDay::readWeekDay()
{
	cout << "Enter info about day of the week:\n";
	cout << "day name: "; cin >> dayName;
	dayDate.readDate();
}