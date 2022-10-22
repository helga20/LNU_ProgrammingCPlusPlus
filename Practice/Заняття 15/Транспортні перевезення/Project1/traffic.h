#pragma once
#include <string>
#include <iostream>

class Traffic
{
protected:
	std::string departure;
	std::string  arrival;
	int number;
	double price;
public:
	Traffic();
	Traffic(const std::string& dp, const std::string& arr, int num, double prc);
	Traffic(const Traffic& T);
	~Traffic();

	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Traffic& T);
std::ostream& operator<<(std::ostream& out, const Traffic& T);