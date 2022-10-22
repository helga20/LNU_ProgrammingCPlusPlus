#include "FlatShapes.h"
#include <sstream>

ostream& operator<<(ostream& os, const Shape& s)
{
	s.printOn(os);
	return os;
}

string Shape::toStr() const
{
	std::ostringstream target;
	this->printOn(target);
	return target.str();
}

//-----------------------------------------------------------

double Rectangle::area() const
{
	return a * b;
}

double Rectangle::perim() const
{
	return (a + b) * 2.;
}

void Rectangle::printOn(ostream& os) const
{
	os  << "Rectangle of size " << std::fixed << std::setprecision(1)
		<< a <<" x "<< b << ';';
}

void Rectangle::storeOn(ofstream& fout) const
{
	fout << "R " << a << ' ' << b;
}

//-----------------------------------------------------------

double Circle::area() const
{
	return M_PI*r*r;
}

double Circle::perim() const
{
	return 2.*M_PI*r;
}

void Circle::printOn(ostream& os) const
{
	os  << "Circle of radius " << std::fixed << std::setprecision(1)
		<< r << ';';
}

void Circle::storeOn(ofstream& fout) const
{
	fout << "C " << r;
}

//-----------------------------------------------------------

double Triangle::area() const
{
	return 0.5*a*b*std::sin(angle());
}

double Triangle::perim() const
{
	return a+b+std::sqrt(a*a+b*b-2.*a*b*std::cos(angle()));
}

void Triangle::printOn(ostream& os) const
{
	os  << "Triangle of side " << std::fixed << std::setprecision(1)
		<< a << ',' << b << " with angle " << y << " degree;";
}

void Triangle::storeOn(ofstream& fout) const
{
	fout << "T " << a << ' ' << b << ' ' << y;
}

//-----------------------------------------------------------

void Square::printOn(ostream& os) const
{
	os  << "Square of side " << std::fixed << std::setprecision(1)
		<< a << ';';
}

void Square::storeOn(ofstream& fout) const
{
	fout << "S " << a;
}