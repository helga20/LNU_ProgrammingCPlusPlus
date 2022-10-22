#pragma once
#include "date.h"
#include <string>

class WeekDay
{
private:
	std::string dayName;
	Date dayDate;

public:
	WeekDay();
	WeekDay(const std::string& name, const Date& D);
	WeekDay(const std::string& name, int day, int month, int year);
	WeekDay(const WeekDay& WD);
	~WeekDay();

	void printWeekDay() const;
	void readWeekDay();
};
