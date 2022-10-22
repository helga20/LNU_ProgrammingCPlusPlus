#pragma once
#include <iostream>

class Date
{
private:
	// дата збер≥гаЇ р≥к, м≥с€ць, день
	int year, month, day;
	// к≥льк≥сть дн≥в у м≥с€ц€х невисокосного року
	static int daysInMonth[12];
public:
	Date() :year(1), month(1), day(1) {}
	// ƒату можна створити за к≥льк≥стю дн≥в, що минула в≥д початку тис€чол≥тт€
	explicit Date(int);
	Date(unsigned d, unsigned m, unsigned y);
	//  лас може надавати послуги без створенн€ екземпл€р≥в:
	// - перев≥рка, чи Ї вказаний р≥к високосним
	static bool isLeapYear(int year)
	{
		return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	}
	// - пов≥домл€Ї к≥льк≥сть дн≥в у роц≥
	static int DaysInYear(int year)
	{
		return 365 + isLeapYear(year);
	}
	// - пов≥домл€Ї к≥льк≥сть дн≥в у вказаному м≥с€ц≥ вказаного року
	static int DaysInMonth(int month, int year = 2019)
	{
		if (month == 2 && isLeapYear(year)) return 29;
		else return daysInMonth[month - 1];
	}
	// - створюЇ екземпл€р, що зображаЇ поточну дату
	static Date DateToday();

	void printOn(std::ostream& os) const
	{
		os.width(2);
		os << day << (month < 10 ? ".0" : ".") << month << '.' << year;
	}
	// дати календар€ можна пор≥внювати
	bool operator>(const Date& date) const
	{
		return this->year > date.year ||
			this->year == date.year && (this->month > date.month ||
				this->month == date.month && this->day > date.day);
	}
	// "в≥дстань" м≥ж датами, обчислена в дн€х
	int operator-(const Date& date) const
	{
		return this->DaysFromStart() - date.DaysFromStart();
	}
	// дату можна зм≥нити на вказану к≥льк≥сть дн≥в
	Date operator+(int days) const
	{
		return Date(this->DaysFromStart() + days);
	}
	// серв≥сн≥ методи дл€ читанн€ пол≥в екземпл€ра
	int Year() const { return year; }
	int Month() const { return month; }
	int Day() const { return day; }
	// ск≥льки дн≥в минуло в≥д початку тис€чол≥тт€
	int DaysFromStart() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

