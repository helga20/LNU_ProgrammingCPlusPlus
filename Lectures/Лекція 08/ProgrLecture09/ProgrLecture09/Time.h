#pragma once
#include <iostream>

// ��� ������� ��������� � ������� � ��������
struct Time
{
	unsigned hours;
	unsigned minutes;

	Time() :hours(0), minutes(0) {} // **����������� �� �������������
	Time(unsigned h, unsigned m);   // **����������� � �����������
	Time(unsigned t);			    // **����������� � ����� ���������� ���������� ���� �� Time
};

bool operator>(const Time & a, const Time & b);	// ��������� ����� ����������
Time operator+(const Time & a, const Time & b); // ��������� ����� ��������
Time operator*(const Time & t, unsigned n);     // ��� ����� ������� �� �����
std::ostream & operator<<(std::ostream & os, const Time & t);
