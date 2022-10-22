#include "square.h"
#include <iostream>
#include <cmath>
using namespace std;

Square::Square() : side(0.0)
{}

Square::Square(double a) : side(a)
{}

Square::Square(const Square& S) : side(S.side)
{}

Square::~Square()
{}

void Square::printInfo() const
{
	cout << "Square info: ";
	cout << "\nSide = " << side << "\n";
}

double Square::getPerimeter() const
{
	double p;
	p = 4 * side;
	cout << "Perimeter = " << p << "\n";
	return p;
}
 
double Square::getSquare() const
{
	double s;
	s = side * side;
	cout << "Square = " << s << "\n";
	return s;
}

char Square::getType() const
{
	return 'S';
}

void Square::readFrom(std::istream& in)
{
	in >> side;
}

void Square::writeTo(std::ostream& out) const
{
	out << side;
}

std::istream& operator>>(std::istream& in, Square& S)
{
	S.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Square& S)
{
	S.writeTo(out);
	return out;
}
