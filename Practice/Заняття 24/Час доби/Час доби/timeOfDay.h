#pragma once
#include <iostream>
#include <vector>
class TimeOfDay
{
protected:
	double hour;
	double minute;
public:
	TimeOfDay();
	TimeOfDay(double hr, double mnt);
	TimeOfDay(const TimeOfDay& T);
	virtual ~TimeOfDay();

	double getMinute() const;
	virtual void printTimeOfDay() const;
	void readTimeOfDay();

	bool operator< (const TimeOfDay& T) const;
	bool operator> (const TimeOfDay& T) const;
	bool compare(const TimeOfDay& left, const TimeOfDay& right);

	/*bool operator+ (const TimeOfDay& T) const;
	bool operator- (const TimeOfDay& T) const;*/

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, TimeOfDay& T);
std::ostream& operator<<(std::ostream& out, const TimeOfDay& T);

void readTimeFromFile(std::vector<TimeOfDay>& hm, const std::string& fileName);
