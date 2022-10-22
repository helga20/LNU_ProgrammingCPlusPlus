#include "exactTimeOfDay.h"
#include <iostream>
#include <fstream>
using namespace std;

ExactTimeOfDay::ExactTimeOfDay()
	: TimeOfDay(), seconds(0.0)
{}

ExactTimeOfDay::ExactTimeOfDay(const TimeOfDay& hm, double scnds)
	: TimeOfDay(hm), seconds(scnds)
{}

ExactTimeOfDay::ExactTimeOfDay(double hValue, double mValue, double scnds)
	: TimeOfDay (hValue, mValue), seconds(scnds)
{}

ExactTimeOfDay::ExactTimeOfDay(const ExactTimeOfDay& ET)
	: TimeOfDay(ET), seconds(ET.seconds)
{}
ExactTimeOfDay::~ExactTimeOfDay()
{}

void ExactTimeOfDay::printTimeOfDay() const
{
	cout << hour << ":" << minute << ":";
}

void ExactTimeOfDay::printExactTimeOfDay() const
{
	printTimeOfDay();
	cout << seconds;
	cout << "\n";
}

void ExactTimeOfDay::readExactTimeOfDay()
{
	cout << "Enter time info:\n";
	readTimeOfDay();
	cout << "Seconds: "; cin >> seconds;	
}

void readExactTimeFromFile(std::vector<ExactTimeOfDay>& time, const std::string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		ExactTimeOfDay t; iFile >> t;
		time.push_back(t);
	}
	iFile.close();
}

