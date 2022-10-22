#pragma once
#include "traffic.h"

class AirTraffic : public Traffic
{
private:
	bool snack;
public:
	AirTraffic();
	AirTraffic(const std::string& dp, const std::string& arr, int num, double prc, double sn);
	AirTraffic(const AirTraffic& A);
	virtual ~AirTraffic();

	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};
double totalPrice(AirTraffic* arr, const int n);
