#pragma once
#include "function.h"
class Plane : public Transportation
{
private:
	bool food;
public:
	Plane();
	Plane(const std::string& dp, const std::string& arrv, int nm, double prc, int fd);
	Plane(const Plane& P);
	~Plane();
	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};
double totalPrice(Plane* arr, const int n);
