#include "rail_traffic.h"
#include <iostream>

using namespace std;

RailTraffic::RailTraffic()
	: Traffic(), vahon(0)
{}

RailTraffic::RailTraffic(const std::string& dp, const std::string& arr, int num, double prc, int vh)
	: Traffic(dp, arr, num, prc), vahon(vh)
{}

RailTraffic::RailTraffic(const RailTraffic& R)
	: Traffic(R), vahon(R.vahon)
{}

RailTraffic::~RailTraffic()
{}

double RailTraffic::getPrice() const
{
	if (vahon > 10)
	{
		double cheaper = (price / 100) * 10;
		double result = price - cheaper;
		return result;
	}
	else
	{
		return price;
	}
}
void RailTraffic::readFrom(std::istream& in)
{
	Traffic::readFrom(in);
	in >> vahon;
}
void RailTraffic::writeTo(std::ostream& out) const
{
	Traffic::writeTo(out);
	out << " " << vahon;
}

double totalPrice(RailTraffic* arr, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i].getPrice();
	}
	return sum;
}


