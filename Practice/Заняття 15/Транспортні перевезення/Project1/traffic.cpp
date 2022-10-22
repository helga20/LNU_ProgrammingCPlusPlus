#include "traffic.h"
#include <iostream>

using namespace std;

Traffic::Traffic() 
	: departure(), arrival(), number(0), price(0.) 
{}

Traffic::Traffic(const std::string& dp, const std::string& arr, int num, double prc) 
	: departure(dp), arrival(arr), number(num), price(prc) 
{}

Traffic::Traffic(const Traffic& T) 
	: departure(T.departure), arrival(T.arrival), number(T.number), price(T.price)
{}

Traffic::~Traffic()
{}

double Traffic::getPrice() const
{
	if (number >= 1 && number <=10)
	{
		double vip = (price / 100) * 10;
		double result = vip + price;
		return result;
	}
	else
	{
		return price;
	}
}

void Traffic::readFrom(std::istream& in)
{
	in >> departure >> arrival >> number >> price;
}

void Traffic::writeTo(std::ostream& out) const
{
	out << departure << " " << arrival << " " << number << " " << price;
}

std::istream& operator>>(std::istream& in, Traffic& T)
{
	T.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Traffic& T)
{
	T.writeTo(out);
	return out;
}
