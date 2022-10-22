#include "air_traffic.h"
#include <iostream>

using namespace std;

AirTraffic::AirTraffic()
	: Traffic(), snack(false)
{}

AirTraffic::AirTraffic(const std::string& dp, const std::string& arr, int num, double prc, double sn)
	: Traffic(dp,arr, num, prc),snack (sn)
{}

AirTraffic::AirTraffic(const AirTraffic& A)
	: Traffic(A), snack(A.snack)
{}

AirTraffic::~AirTraffic()
{}

double AirTraffic::getPrice() const
{
	if (snack)
	{
		return price + 150;
	}
	else
	{
		return price;
	}
}

void AirTraffic::readFrom(std::istream& in)
{
	Traffic::readFrom(in);
	in >> snack;
}

void AirTraffic::writeTo(std::ostream& out) const
{
	Traffic::writeTo(out);
	out << " " << snack;
}

double totalPrice(AirTraffic* arr, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i].getPrice();
	}
	return sum;
}


