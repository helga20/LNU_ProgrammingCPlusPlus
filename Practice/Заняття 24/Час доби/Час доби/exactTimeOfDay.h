#pragma once
#include "timeOfDay.h"
#include <vector>
class ExactTimeOfDay : public TimeOfDay
{
private:
	double seconds;

public:
	ExactTimeOfDay();
	ExactTimeOfDay(const TimeOfDay& hm, double scnds);
	ExactTimeOfDay(double hValue, double mValue, double scnds);
	ExactTimeOfDay(const ExactTimeOfDay& ET);
	virtual ~ExactTimeOfDay();

	virtual void printTimeOfDay() const override;

	void printExactTimeOfDay() const;
	void readExactTimeOfDay();
};

void readExactTimeFromFile(std::vector<ExactTimeOfDay>& time, const std::string& fileName);
