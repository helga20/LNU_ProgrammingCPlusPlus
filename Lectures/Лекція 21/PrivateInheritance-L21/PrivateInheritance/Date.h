#pragma once
#include <iostream>

class Date
{
private:
	// ���� ������ ��, �����, ����
	int year, month, day;
	// ������� ��� � ������ ������������� ����
	static int daysInMonth[12];
public:
	Date() :year(1), month(1), day(1) {}
	// ���� ����� �������� �� ������� ���, �� ������ �� ������� ����������
	explicit Date(int);
	Date(unsigned d, unsigned m, unsigned y);
	// ���� ���� �������� ������� ��� ��������� ����������:
	// - ��������, �� � �������� �� ����������
	static bool isLeapYear(int year)
	{
		return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	}
	// - ��������� ������� ��� � ����
	static int DaysInYear(int year)
	{
		return 365 + isLeapYear(year);
	}
	// - ��������� ������� ��� � ��������� ����� ��������� ����
	static int DaysInMonth(int month, int year = 2019)
	{
		if (month == 2 && isLeapYear(year)) return 29;
		else return daysInMonth[month - 1];
	}
	// - ������� ���������, �� ������� ������� ����
	static Date DateToday();

	void printOn(std::ostream& os) const
	{
		os.width(2);
		os << day << (month < 10 ? ".0" : ".") << month << '.' << year;
	}
	// ���� ��������� ����� ����������
	bool operator>(const Date& date) const
	{
		return this->year > date.year ||
			this->year == date.year && (this->month > date.month ||
				this->month == date.month && this->day > date.day);
	}
	// "�������" �� ������, ��������� � ����
	int operator-(const Date& date) const
	{
		return this->DaysFromStart() - date.DaysFromStart();
	}
	// ���� ����� ������ �� ������� ������� ���
	Date operator+(int days) const
	{
		return Date(this->DaysFromStart() + days);
	}
	// ������ ������ ��� ������� ���� ����������
	int Year() const { return year; }
	int Month() const { return month; }
	int Day() const { return day; }
	// ������ ��� ������ �� ������� ����������
	int DaysFromStart() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

