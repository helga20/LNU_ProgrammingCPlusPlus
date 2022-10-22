#include "equaltriangle.h"
#include <cmath>
using namespace std;

EqualTriangle::EqualTriangle() : Triangle()
{}

EqualTriangle::EqualTriangle(double a) : Triangle(a, a, a)
{}

EqualTriangle::EqualTriangle(const EqualTriangle& ET) : Triangle(ET)
{}

EqualTriangle::~EqualTriangle()
{}

Triangle* EqualTriangle::clone() const
{
	return new EqualTriangle(*this);
}

char EqualTriangle::getType() const
{
	return 'E';
}

double EqualTriangle::perimeter() const
{
	return sideA * 3.0;
}

double EqualTriangle::square() const
{
	double s = sideA * sideA * sqrt(3.0) * 0.25;
	return s;
}

void EqualTriangle::readFrom(std::istream& in)
{
	in >> sideA;
	sideB = sideA;
	sideC = sideA;
}

void EqualTriangle::writeTo(std::ostream& out) const
{
	out << sideA;
}