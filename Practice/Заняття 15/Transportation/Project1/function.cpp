#include "function.h"
#include <iostream>
using namespace std;
Transportation::Transportation()
	: depart(), arriv(), num(0), price(0.){}
Transportation::Transportation(const std::string& dp, const std::string& arrv, int nm, double prc)
	: depart(dp), arriv(arrv), num(nm), price(prc){}
Transportation::Transportation(const Transportation& T)
	: depart(T.depart), arriv(T.arriv), num(T.num), price(T.price){}
Transportation::~Transportation(){}

double Transportation::getPrice() const
{
	if (num >= 1 && num <=10)
	{double moreExpensive = (price / 100) * 10;
	return  moreExpensive + price;}
	else
	{return price;}
}
void Transportation::readFrom(std::istream& in)
{
	in >> depart >> arriv >> num >> price;
}
void Transportation::writeTo(std::ostream& out) const
{
	out << depart << ' ' << arriv << ' ' << num << ' ' << price;
}
std::istream& operator>>(std::istream& in, Transportation& T)
{
	T.readFrom(in); return in;
}
std::ostream& operator<<(std::ostream& out, const Transportation& T)
{
	T.writeTo(out); return out;
}
