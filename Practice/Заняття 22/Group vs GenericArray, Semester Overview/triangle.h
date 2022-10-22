#pragma once
#include <iostream>

class Triangle
{
protected:
	double sideA;
	double sideB;
	double sideC;

public:
	Triangle();
	Triangle(double a, double b, double c);
	Triangle(const Triangle& T);
	virtual ~Triangle();

	virtual Triangle* clone() const;
	virtual char getType() const;

	virtual double perimeter() const;
	virtual double square() const;

	bool operator< (const Triangle& T) const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
}; 

std::istream& operator>>(std::istream& in, Triangle& T);
std::ostream& operator<<(std::ostream& out, const Triangle& T);