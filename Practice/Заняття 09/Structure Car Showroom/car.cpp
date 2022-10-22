#include "car.h"
#include <iostream>
using namespace std;


istream& operator>>(istream& in, Car& C)
{
	in >> C.brand >> C.model >> C.price;
	return in;
}

ostream& operator<<(ostream& out, const Car& C)
{
	out << C.brand << ' ' << C.model << ' ' << C.price;
	return out;
}

bool operator<(const Car& C1, const Car& C2)
{
	return C1.price < C2.price;
}
