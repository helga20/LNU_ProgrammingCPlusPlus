#include "plane.h"
#include <iostream>
using namespace std;
Plane::Plane()
	: Transportation(), food(false){}
Plane::Plane(const std::string& dp, const std::string& arrv, int nm, double prc, int fd)
	: Transportation(dp,arrv, num, prc),food (fd){}
Plane::Plane(const Plane& P)
	: Transportation(P), food(P.food){}
Plane::~Plane(){}

double Plane::getPrice() const
{
	if (food) {return price + 80;}
	else {return price;}
}
void Plane::readFrom(std::istream& in)
{
	Transportation::readFrom(in); in >> food;
}
void Plane::writeTo(std::ostream& out) const
{
	Transportation::writeTo(out); out << ' ' << food;
}
double totalPrice(Plane* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{sum += arr[i].getPrice();}
	return sum;
}


