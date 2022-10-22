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