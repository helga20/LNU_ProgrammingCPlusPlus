#include "train.h"
#include <iostream>
using namespace std;
Train::Train()
	: Transportation(), van(0){}
Train::Train(const std::string& dp, const std::string& arrv, int nm, double prc, int vn)
	: Transportation(dp, arrv, num, prc), van(vn){}
Train::Train(const Train& V)
	: Transportation(V), van(V.van){}
Train::~Train(){}

double Train::getPrice() const
{
	if (van > 10)
	{double cheaper = (price / 100) * 10;
	return price - cheaper;}
	else
	{return price;}
}
void Train::readFrom(std::istream& in)
{
	Transportation::readFrom(in); in >> van;
}
void Train::writeTo(std::ostream& out) const
{
	Transportation::writeTo(out); out << ' ' << van;
}
double totalPrice(Train* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{sum += arr[i].getPrice();}
	return sum;
}


