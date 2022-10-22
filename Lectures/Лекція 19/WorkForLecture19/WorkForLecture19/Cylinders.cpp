#include "Cylinders.h"

double DerivCylinder::baseArea() const 
{ 
	return /*M_PI * r * r*/ area(); 
}

double DerivCylinder::sideArea() const
{
	return /*2. * M_PI * r * h*/ length() * h;
}

double DerivCylinder::volume() const
{
	return area() * h;
}

void DerivCylinder::printOn(std::ostream& os) const
{
	os << "Cylinder of " << h << " high with ";
	Circle::printOn(os);
	os << " as base";
}

void ComposedCylinder::printOn(std::ostream& os) const
{
	os << "Cylinder of " << h << " high with " << base << " as base";
}
std::ostream& operator<<(std::ostream& os, const ComposedCylinder& C)
{
	C.printOn(os);
	return os;
}