#pragma once
#include <string>
#include <iostream>

class Car
{
protected:
	std::string brand;
	double price;
public:
	Car();
	Car(const std::string& brnd, double prc);
	Car(const Car& C);
	virtual~Car();

	virtual Car* clone() const abstract;

	virtual char getType() const abstract;
	virtual void printCarInfo() const;

	virtual double getPrice() const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Car& C);
std::ostream& operator<<(std::ostream& out, const Car& C);