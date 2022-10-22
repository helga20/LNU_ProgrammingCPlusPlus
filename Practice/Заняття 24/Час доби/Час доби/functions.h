#pragma once
#include <iostream>
#include "exactTimeOfDay.h"
#include "timeOfDay.h"
using namespace std;

void printTime(const ExactTimeOfDay& time)
{
	cout << time << '\n';
}

class TimePrinterClass
{
public:
	void operator() (const ExactTimeOfDay& time)
	{
		time.printTimeOfDay();
	}
};

class TimeExactPrinterClass
{
public:
	void operator() (const ExactTimeOfDay& time)
	{
		time.printTimeOfDay();
	}
};
