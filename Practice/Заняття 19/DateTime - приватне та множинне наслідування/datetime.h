#pragma once
#include "date.h"
#include "time.h"
#include <string>

class DateTime : public Date, public Time
{
private:
	std::string dayName;

public:
	DateTime();
	DateTime(const std::string& day, const Date& date, const Time& time);
	DateTime(const std::string& day, int dNumber, int mNumber, int yNumber, int hValue, int mValue);
	DateTime(const DateTime& DT);
	virtual ~DateTime();

	virtual void printDate() const override;
	virtual void printTime() const override;

	void printDateTime() const;
	void readDateTime();
};