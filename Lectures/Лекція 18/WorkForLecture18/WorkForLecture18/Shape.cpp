#include "Shape.h"

void Rect::printOn(std::ostream& os) const
{
	os << "Rectangle [ " << a << " x " << b << " ]";
}

void Square::printOn(std::ostream& os) const
{
	os << "Square [ " << a << " x " << b << " ]";
}

double Circle::area() const
{
	return M_PI * r * r;
}

double Circle::length() const
{
	return 2. * M_PI * r;
}

void Circle::printOn(std::ostream& os) const
{
	os << "Circle ( " << r << " )";
}


std::ostream& operator<<(std::ostream& os, const FlatShape& R)
{
	R.printOn(os);
	return os;
}