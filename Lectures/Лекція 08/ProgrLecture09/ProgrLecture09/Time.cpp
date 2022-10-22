#include "Time.h"

Time::Time(unsigned h, unsigned m)
{
	hours = h + m / 60;
	minutes = m % 60;
}
Time::Time(unsigned n)
{
	hours = n / 60;
	minutes = n % 60;
}

bool operator>(const Time & a, const Time & b)
{
	return a.hours > b.hours || a.hours == b.hours && a.minutes > b.minutes;
}
Time operator+(const Time & a, const Time & b)
{
	return Time(a.hours + b.hours, a.minutes + b.minutes);
}
Time operator*(const Time & t, unsigned n)
{
	return Time(t.hours*n, t.minutes*n);
}
std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << (t.minutes > 9 ? ":" : ":0") << t.minutes;
	return os;
}
