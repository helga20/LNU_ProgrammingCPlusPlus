#include "RectangleSquare.h"

Rectangle::Rectangle(double x, double y)
{
	a = (x > 0.1) ? x : 0.1;
	b = (y > 0.1) ? y : 0.1;
	calculateArea();
}
void Rectangle::printOn(ostream& os) const
{
	os << "Rectangle ( " << a << " x " << b << " )";
}

void Square::printOn(ostream& os) const
{
	double side = getA();
	os << "Square ( " << side << " x " << side << " )";
}

ostream& operator<<(ostream& os, const Rectangle& R)
{
	R.printOn(os);
	return os;
}