#pragma once
#include <string>
#include <iostream>
#include <vector>

class Car
{
private:
	std::string m_model;
	double m_price;

public:
	Car();
	Car(const std::string& model, double price);
	Car(const Car& C);
	~Car();

	void print() const;
	double getPrice() const;
	const std::string& getModel() const;

	void setDiscount(int discount);
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

	bool operator==(const Car& C) const;
	bool operator<(const Car& C) const;

};

std::istream& operator>>(std::istream& in, Car& C);
std::ostream& operator<<(std::ostream& out, const Car& C);

void readCarsFromFile(std::vector<Car>& cars, const std::string& fileName);
