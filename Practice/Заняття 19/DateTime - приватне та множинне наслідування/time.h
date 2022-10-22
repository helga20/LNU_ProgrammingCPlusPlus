#pragma once

class Time
{
protected:
	int hour;
	int minute;

public:
	Time();
	Time(int h, int m);
	Time(const Time& T);
	virtual ~Time();

	virtual void printTime() const;
	void readTime();
};