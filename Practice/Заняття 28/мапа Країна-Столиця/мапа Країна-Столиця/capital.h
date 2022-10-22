#pragma once
#include <iostream>
#include <string>

class Capital
{
private:
	std::string name;
	double population;

public:
	Capital();
	Capital(const std::string& nm, double pp);
	Capital(const Capital& C);
	~Capital();

	void readCapital();

	const std::string& getName();
	double getPopulation() const;

	void printCapitalInfo() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Capital& C);
std::ostream& operator<<(std::ostream& out, const Capital& C);

