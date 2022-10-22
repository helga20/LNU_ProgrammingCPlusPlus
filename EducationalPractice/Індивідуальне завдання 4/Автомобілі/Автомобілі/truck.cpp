#include "truck.h"
#include <iostream>

using namespace std;

Truck::Truck()
	:Car(), maxLift()
{}

Truck::Truck(const std::string& brnd, double prc, int lift)
	: Car(brnd, prc), maxLift(lift)
{}

Truck::Truck(const Truck& T)
	: Car(T), maxLift(T.maxLift)
{}

Truck::~Truck()
{}

Car* Truck::clone() const
{
	return new Truck(*this);
}

double Truck::getPrice() const
{
	if (maxLift > 250)
	{
		double bigger = (price / 100) * 5;
		double result = bigger + price;
		return result;
	}
	else
	{
		return price;
	}
}

void Truck::printCarInfo() const
{
	cout << "Truck Info\n";
	Car::printCarInfo();
	cout << "Max lifting: " << maxLift << "\n";
}

char Truck::getType() const
{
	return 'T';
}

void Truck::readFrom(std::istream& in)
{
	Car::readFrom(in);
	in >> maxLift;
}

void Truck::writeTo(std::ostream& out) const
{
	Car::writeTo(out);
	out << " " << maxLift;
}