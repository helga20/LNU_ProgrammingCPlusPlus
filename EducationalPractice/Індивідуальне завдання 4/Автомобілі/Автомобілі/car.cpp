#include "car.h"
#include <iostream>

using namespace std;

Car::Car()
	:brand(), price(0.0)
{}

Car::Car(const std::string& brnd, double prc)
	: brand(brnd), price(prc)
{}

Car::Car(const Car& C)
	: brand(C.brand), price(C.price)
{}

Car::~Car()
{}

void Car::printCarInfo() const
{
	cout << "Brand:" << brand << ". Price: " << price << " hrn." << "\n";
}

double Car::getPrice() const
{
	return price;
}

void Car::readFrom(std::istream& in)
{
	in >> brand >> price;
}

void Car::writeTo(std::ostream& out) const
{
	out << brand << " " << price;
}

std::istream& operator>>(std::istream& in, Car& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Car& C)
{
	C.writeTo(out);
	return out;
}