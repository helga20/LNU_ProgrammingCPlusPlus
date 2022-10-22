#include "sportCar.h"
#include <iostream>

using namespace std;

sportCar::sportCar()
	: Car(), maxSpeed(0)
{}

sportCar::sportCar(const std::string& brnd, double prc, int speed)
	: Car(brnd, prc), maxSpeed(speed)
{}

sportCar::sportCar(const sportCar& S)
	: Car(S), maxSpeed(S.maxSpeed)
{}

sportCar::~sportCar()
{}

Car* sportCar::clone() const
{
	return new sportCar(*this);
}

double sportCar::getPrice() const
{
	if (maxSpeed > 180)
	{
		double more = (price / 100) * 10;
		double result = more + price;
		return result;
	}
	else
	{
		return price;
	}
}

void sportCar::printCarInfo() const
{
	cout << "Sport car Info\n";
	Car::printCarInfo();
	cout << "Max speed: " << maxSpeed << "\n";
}

char sportCar::getType() const
{
	return 'S';
}

void sportCar::readFrom(std::istream& in)
{
	Car::readFrom(in);
	in >> maxSpeed;
}

void sportCar::writeTo(std::ostream& out) const
{
	Car::writeTo(out);
	out << " " << maxSpeed;
}