#pragma once
#include <string>
#include <iostream>

class Sportsman
{
protected:
	std::string surname;
public:
	Sportsman();
	Sportsman(const std::string& snm);
	Sportsman(const Sportsman& S);
	virtual~Sportsman();

	virtual void printSportsmanInfo() const;
	virtual double incomeInfo() const abstract;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

std::istream& operator >> (std::istream& in, Sportsman& S);
std::ostream& operator << (std::ostream& out, const Sportsman& S);
