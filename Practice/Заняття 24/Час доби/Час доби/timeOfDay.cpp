#include <iostream>
#include "timeOfDay.h"
#include <fstream>
using namespace std;

TimeOfDay::TimeOfDay()
	: hour(0.0), minute(0.0)
{}

TimeOfDay::TimeOfDay(double hr, double mnt)
	: hour(hr), minute(mnt)
{}
TimeOfDay::TimeOfDay(const TimeOfDay& T)
	: hour(T.hour), minute(T.minute)
{}

	TimeOfDay::~TimeOfDay()
{}

void TimeOfDay::printTimeOfDay () const
{ 
	if (hour <= 0)
		cout << "Error";
	cout << hour << ":";
	if (minute <= 0)
		cout << "Error";
	cout << minute;
}

void TimeOfDay::readTimeOfDay()
{
	cout << "Enter time info:\n";
	cout << "hour (00-23): "; cin >> hour;
	cout << "minute (00-59): "; cin >> minute;
}

double TimeOfDay::getMinute() const
{
	return minute;
}

bool TimeOfDay::operator< (const TimeOfDay& T) const
{
	return hour < T.getMinute();
}

bool TimeOfDay::operator> (const TimeOfDay& T) const
{
	return hour > T.getMinute();
}

bool TimeOfDay::compare(const TimeOfDay& left, const TimeOfDay& right)
{
	return left.getMinute() < right.getMinute();
}

//bool TimeOfDay::operator+ (const TimeOfDay& T) const
//{
//	
//}
//
//bool TimeOfDay::operator- (const TimeOfDay& T) const
//{
//
//}

void TimeOfDay::readFrom(std::istream& in)
{
	in >> hour >> minute;
}

void TimeOfDay::writeTo(std::ostream& out) const
{
	out << hour << " " << minute;
}

std::istream& operator>>(std::istream& in, TimeOfDay& T)
{
	T.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const TimeOfDay& T)
{
	T.writeTo(out);
	return out;
}

void readTimeFromFile(std::vector<TimeOfDay>& hm, const std::string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		TimeOfDay t1; iFile >> t1;
		hm.push_back(t1);
	}
	iFile.close();
}
