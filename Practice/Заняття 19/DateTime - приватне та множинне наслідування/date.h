#pragma once

class Date
{
protected:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int d, int m, int y);
	Date(const Date& D);
	virtual ~Date();

	virtual void printDate() const;
	void readDate();
	
};
