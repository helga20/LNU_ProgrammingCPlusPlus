#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class CarEmptyFieldException
{
private:
	string  fieldName;
public:
	CarEmptyFieldException(const string& field);
	void report()const;
};

class CarPriceException
{
private:
	double  priceValue;
public:
	CarPriceException(double price);
	void report()const;
};

class Car
{
private: 

	string  brand;
	string model;
	double price;

public:

	Car(const string& brnd, const string& mdl, double prc);

	void printInfo() const;

	void setBrand(const string& brandValue) /*throw (CarEmptyFieldException)*/;
	void setModel(const string& modelValue) /*throw (CarEmptyFieldException)*/;
	void setPrice(double priceValue)/* throw (CarPriceException)*/;

	void readFrom(istream& in);
	void writeTo(ostream& out) const;

};

istream& operator>>(istream& in, Car& C);
ostream& operator<<(ostream& out, const Car& C);




