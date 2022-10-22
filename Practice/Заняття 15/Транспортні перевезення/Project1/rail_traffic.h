#pragma once
#include "traffic.h"

class RailTraffic : public Traffic
{
private:
	int vahon;
public:
	RailTraffic();
	RailTraffic(const std::string& dp, const std::string& arr, int num, double prc, int vh);
	RailTraffic(const RailTraffic& R);
	~RailTraffic();

	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};
double totalPrice(RailTraffic* arr, const int n);
