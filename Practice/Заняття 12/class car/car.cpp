#include "car.h"

CarEmptyFieldException::CarEmptyFieldException(const string& field) : fieldName(field) {}
void CarEmptyFieldException::report()const
{
	cout << "Car Exception. The field " << fieldName << " cannot be empty!\n";
}

CarPriceException::CarPriceException(double price) : priceValue(price) {}
void CarPriceException::report()const
{
	cout << "Car Exception. Price value: " << priceValue << " is invalid!\n";
}

Car::Car(const string& brnd, const string& mdl, double prc) : brand(brnd), model(mdl), price(prc) {}

void Car::printInfo() const
{
	cout << "Car info: ";
	cout << brand << " " << model << " " << price << " \n";
}

void Car::setBrand(const string& brandValue) /*throw (CarEmptyFieldException)*/
{
	if (brandValue.empty())
	{
		throw CarEmptyFieldException("Brand");
	}
	brand = brandValue;
}

void Car::setModel(const string& modelValue)/* throw (CarEmptyFieldException)*/
{
	if (modelValue.empty())
	{
		throw CarEmptyFieldException("Model");
	}
	model = modelValue;
}

void Car::setPrice(double priceValue)/* throw (CarPriceException)*/
{
	if (priceValue <= 0)
	{
		throw CarPriceException(priceValue);
	}
	price = priceValue;
}

void Car::readFrom(istream& in)
{
	in >> brand >> model >> price;
}

void Car::writeTo(ostream& out) const
{
	out << brand << ' ' << model << ' ' << price;
}

istream& operator>>(istream& in, Car& C)
{
	C.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const Car& C)
{
	C.writeTo(out);
	return out;
}
