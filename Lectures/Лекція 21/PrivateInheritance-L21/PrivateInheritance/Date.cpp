#include "pch.h"
#include "Date.h"
#include <time.h>

int Date::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int days)
{
	year = 1;
	while (days > DaysInYear(year))
	{
		days -= DaysInYear(year);
		++year;
	}
	month = 1;
	while (days > DaysInMonth(month, year))
	{
		days -= DaysInMonth(month, year);
		++month;
	}
	day = days;
}

Date::Date(unsigned d, unsigned m, unsigned y)
{
	day = d == 0 ? 1 : d;
	month = m == 0 ? 1 : m;
	year = y == 0 ? 1 : y;
	year += (month - 1) / 12;
	month = (month - 1) % 12 + 1;
	while (day > DaysInMonth(month, year))
	{
		day -= DaysInMonth(month, year);
		++month;
		if (month > 12)
		{
			month = 1; ++year;
		}
	}
}

Date Date::DateToday()
{
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	return Date(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}

int Date::DaysFromStart() const
{
	int result = this->day + (this->year - 1) * 365;
	for (int i = 1; i < this->month; ++i) result += DaysInMonth(i, year);
	result += (year - 1) / 4;
	result -= (year - 1) / 100;
	result += (year - 1) / 400;
	return result;
}

std::ostream & operator<<(std::ostream & os, const Date & date)
{
	date.printOn(os);
	return os;
}