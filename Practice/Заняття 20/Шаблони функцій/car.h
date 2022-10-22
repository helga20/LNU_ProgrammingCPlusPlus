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

	bool operator< (const Car& C) const;
};
