#pragma once
#include <string>
#include <iostream>
#include <vector>

class Car
{
protected:
	std::string m_model;
	double m_price;

public:
	Car();
	Car(const std::string& model, double price);
	Car(const Car& C);
	virtual ~Car();

	virtual void print() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;

	double getPrice() const;
	const std::string& getModel() const;
	void setDiscount(int discount);	

	bool operator==(const Car& C) const;
	bool operator<(const Car& C) const;

};

std::istream& operator>>(std::istream& in, Car& C);
std::ostream& operator<<(std::ostream& out, const Car& C);
