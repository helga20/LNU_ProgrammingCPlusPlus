#include "car.h"
using namespace std;

Car::Car() : model(""), price(0.0)
{}

Car::Car(const std::string& mdl, double prc) : model(mdl), price(prc)
{}

Car::Car(const Car& C) : model(C.model), price(C.price)
{}

Car::~Car()
{}

void Car::print() const
{
	cout << "Car: " << model << ". " << price << " euro\n";
}

double Car::getPrice() const
{
	return price;
}

bool Car::operator< (const Car& C) const
{
	return price < C.getPrice();
}

void Car::setDiscount(int discount)
{
	double discountValue = price * (double)discount / 100.0;
	price -= discountValue;
}

void Car::readFrom(std::istream& in)
{
	in >> model >> price;
}

void Car::writeTo(std::ostream& out) const
{
	out << model << ' ' << price;
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