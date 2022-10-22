#pragma once
#include <string>
#include <iostream>

class Car
{
private:
	std::string model;
	double price;

public:
	Car();
	Car(const std::string& mdl, double prc);
	Car(const Car& C);
	~Car();

	void print() const;
	double getPrice() const;

	void setDiscount(int discount);
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

	bool operator< (const Car& C) const;
};

std::istream& operator>>(std::istream& in, Car& C);
std::ostream& operator<<(std::ostream& out, const Car& C);
