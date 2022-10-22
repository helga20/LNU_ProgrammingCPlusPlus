#include "time.h"
#include <iostream>
using namespace std;

Time::Time() : hour(0), minute(0)
{}

Time::Time(int h, int m) : hour(h), minute(m)
{}

Time::Time(const Time& T) : hour(T.hour),minute(T.minute)
{}

Time::~Time()
{}

void Time::printTime() const
{
	// print in format 11:35, 08:00, 08:01
	// print hour
	if (hour < 10)
		cout << "0";
	cout << hour << ":";
	// print minute
	if (minute < 10)
		cout << "0";
	cout << minute;
}

void Time::readTime()
{
	cout << "Enter time info:\n";
	cout << "hour (00-23): "; cin >> hour;
	cout << "minute (00-59): "; cin >> minute;
}