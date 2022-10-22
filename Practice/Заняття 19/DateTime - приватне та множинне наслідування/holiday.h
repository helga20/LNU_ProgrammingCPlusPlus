#pragma once
#include "date.h"
#include <string>

class Holiday : private Date
{
private:
	std::string holidayName;

public:
	Holiday();
	Holiday(const std::string& name, const Date& D);
	Holiday(const std::string& name, int day, int month, int year);
	Holiday(const Holiday& H);
	~Holiday();

	void printHoliday() const;
	void readHoliday();
};
