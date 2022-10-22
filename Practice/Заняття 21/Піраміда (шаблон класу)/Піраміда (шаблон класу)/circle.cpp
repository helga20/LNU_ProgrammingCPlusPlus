#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle() : radius(0.0)
{}

Circle::Circle(double r) : radius(r)
{}

Circle::Circle(const Circle& C) : radius(C.radius)
{}

Circle::~Circle()
{}

void Circle::printInfo() const
{
	cout << "Circle info: ";
	cout << "\nRadius = " << radius << "\n";
}

double Circle::getPerimeter() const
{
	double p;
	p = 2. * M_PI * radius;
	cout << "Perimeter = " << p << "\n";
	return p;
}

double Circle::getSquare() const
{
	double s;
	s = M_PI * radius * radius;
	cout << "Square = " << s << "\n";
	return s;
}

char Circle::getType() const
{
	return 'C';
}

void Circle::readFrom(std::istream& in)
{
	in >> radius;
}

void Circle::writeTo(std::ostream& out) const
{
	out << radius;
}

std::istream& operator>>(std::istream& in, Circle& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Circle& C)
{
	C.writeTo(out);
	return out;
}


