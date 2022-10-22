#ifndef _TIME_H_1
#define _TIME_H_1

#include <iostream>
using std::cout;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();		// **����������� �� ������������� - ��������� ����������� ������ �����������
	Time(int h, int m);		// **����������� � �����������
	Time(const Time& t);	// **����������� ���������
	Time& operator=(const Time&);	// �������� ��������� � ��� � ������������� ���������
	Time& AddMin(int m);		// ������ ������ �������� ���� ���������� - ���������� ���� ��
	Time& AddHr(int h);
	void Reset(int h = 0, int m = 0);//***
	Time Sum(const Time& t) const;	// ��������� ����� ���������� ��������� �������
	Time operator+(const Time & t) const;	// ��� ����������
	bool operator>(const Time& t) const;	// ��'���� ����� ����������
	Time operator*(double n) const;	// ��� ����� ������� �� ����� � ...
	
	void Show(std::ostream&) const;		// **��'��� �쳺 ���� ��������� � ����
	// ������� ���� ��������� ��'��� �������� �������� �������.
	// ���� �� ������� ������ �� ���� (���. ���������), ������� ����� ��������� ��������
	friend std::ostream & operator<<(std::ostream & os, const Time & t);

	// ����� ������������ ��� - �����
	Time (int t);			// **����������� � ����� ���������� ���������� int �� Time
	operator int() const;	// ����������� �������� ������������ Time �� int
};

Time operator*(double n, const Time & t); // ... ����� ������� �� ���

#endif