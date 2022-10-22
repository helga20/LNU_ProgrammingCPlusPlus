#pragma once
#include <string>
#include <iostream>
#include "Human.h"

class Robot
{
private:
	std::string model;
	std::string powerType;
	int serialNo;
	static int SerialNumber;
public:
	Robot();
	Robot(const char* mod, const char* pow);
	virtual ~Robot() {}
	virtual void printOn(std::ostream& os) const;
	Robot& doWork(std::string aWork)
	{
		std::cout << model << " #" << serialNo << " did work [" << aWork << "]\n";
		return *this;
	}
};
std::ostream& operator<<(std::ostream& os, const Robot& robot);

// множинне наслідування від різних класів
class Robocop :
	public Human,
	public Robot
{
private:
	Date releaseDate;
public:
	Robocop() :Human(), Robot(), releaseDate() {}
	Robocop(const char* n, unsigned d, unsigned m, unsigned y)
		:Human(n, d, m, y), Robot("Police", "Nuclear"), releaseDate(d, m, y + 30) {}
	virtual void printOn(std::ostream& os) const
	{
		os << (Human)*this << " & " << (Robot)*this << " manufactured on " << releaseDate;
	}
	virtual ~Robocop() {}
};
// перевизначення оператора виведення - обов'язкове
std::ostream& operator<<(std::ostream& os, const Robocop& robocop);

