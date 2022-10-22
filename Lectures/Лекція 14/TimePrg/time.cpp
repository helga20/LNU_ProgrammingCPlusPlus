#include "time.h"

Time::Time()
{
	hours = minutes = 0;
	cout << "Default\n";
}
Time::Time(int h, int m)
{
	hours = h + m / 60;
	minutes = m % 60;
}
Time::Time(const Time& t)
{
	this->hours = t.hours;
	this->minutes = t.minutes;
	cout << "Copying " << t << '\n';
}
Time& Time::operator=(const Time& t)
{
	if (this != &t)
	{
		this->hours = t.hours;
		this->minutes = t.minutes;
	}
	return *this;
}
Time& Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
	return *this;
}
Time& Time::AddHr(int h)
{
	hours += h;
	return *this;
}
void Time::Reset(int h, int m)
{
	hours = h + m / 60;
	minutes = m % 60;
}
Time Time::Sum(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator+(const Time & t) const
{
	return Time(this->hours + t.hours, this->minutes + t.minutes);
}
bool Time::operator>(const Time& t) const
{
	return hours > t.hours ||
		hours == t.hours && minutes > t.minutes;
}
Time Time::operator*(double n) const
{
	long long totalmin = (hours * 60 + minutes) * n;
	return Time(totalmin / 60, totalmin % 60);
}
void Time::Show(std:: ostream& os) const
{
	os << hours << " hours, " << minutes << " minutes\n";
}
std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << (t.minutes < 10 ? ":0" : ":") << t.minutes;
	//t.Show(os);
	return os;
}

Time operator*(double n, const Time & t) { return t*n; }

Time::Time(int t)
{
	hours = t / 60; minutes = t % 60;
}
Time::operator int() const
{
	return hours * 60 + minutes;
}