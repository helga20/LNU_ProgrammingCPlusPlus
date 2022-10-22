#include "triangle.h"
#include <cmath>
using namespace std;

Triangle::Triangle()
	: sideA(0), sideB(0), sideC(0)
{}

Triangle::Triangle(double a, double b, double c)
	: sideA(a), sideB(b), sideC(c)
{}

Triangle::Triangle(const Triangle& T)
	: sideA(T.sideA), sideB(T.sideB), sideC(T.sideC)
{}

Triangle::~Triangle()
{}

Triangle* Triangle::clone() const
{
	return new Triangle(*this);
}

char Triangle::getType() const
{
	return 'T';
}

double Triangle::perimeter() const
{
	return sideA + sideB + sideC;
}

double Triangle::square() const
{
	double p = perimeter() * 0.5;
	double s = p * (p - sideA) * (p - sideB) * (p - sideC);
	return sqrt(s);
}

bool Triangle::operator< (const Triangle& T) const
{
	return square() < T.square();
}

void Triangle::readFrom(std::istream& in)
{
	in >> sideA >> sideB >> sideC;
}

void Triangle::writeTo(std::ostream& out) const
{
	out << sideA << ' ' << sideB << ' ' << sideC;
}

std::istream& operator>>(std::istream& in, Triangle& T)
{
	T.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Triangle& T)
{
	T.writeTo(out);
	return out;
}