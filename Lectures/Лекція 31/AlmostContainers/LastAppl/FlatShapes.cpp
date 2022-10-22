#include "FlatShapes.h"
#include <cstring>

ostream& operator<<(ostream& os, const Shape& s)
{
	s.printOn(os);
	return os;
}

//-----------------------------------------------------------

double Rectangle::square() const
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
	fout << a << ' ' << b;
}

char * Rectangle::toStr() const
{
	char aChar[10] = {0};
	_gcvt(this->a,8,aChar);
	char bChar[10] = {0};
	_gcvt(this->b,8,bChar);
	char * result = new char[21+strlen(aChar)+strlen(bChar)];
	char * ptr = strcpy(result, "Rectangle of size ");
	ptr = strcat(ptr, aChar);
	ptr = strcat(ptr, " x ");
	strcat(ptr, bChar);
	return result;
}

//-----------------------------------------------------------

double Circle::square() const
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
	fout << r;
}

char * Circle::toStr() const
{
	char rChar[10] = {0};
	_gcvt(this->r,8,rChar);
	char * result = new char[17+strlen(rChar)];
	char * ptr = strcpy(result, "Circle of radius ");
	strcat(ptr, rChar);
	return result;
}

//-----------------------------------------------------------

double Triangle::square() const
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
	fout << a << ' ' << b << ' ' << y;
}

char * Triangle::toStr() const
{
	char aChar[10] = {0};
	_gcvt(this->a,8,aChar);
	char bChar[10] = {0};
	_gcvt(this->b,8,bChar);
	char yChar[5] = {0};
	_itoa(this->y,yChar,10);
	char * result = new char[39+strlen(aChar)+strlen(bChar)+strlen(yChar)];
	char * ptr = strcpy(result, "Triangle of side ");
	ptr = strcat(ptr, aChar);
	ptr = strcat(ptr, ", ");
	ptr = strcat(ptr, bChar);
	ptr = strcat(ptr, " with angle ");
	ptr = strcat(ptr, yChar);
	strcat(ptr, " degrees");
	return result;
}

//-----------------------------------------------------------

void Square::printOn(ostream& os) const
{
	os  << "Square of side " << std::fixed << std::setprecision(1)
		<< a << ';';
}

void Square::storeOn(ofstream& fout) const
{
	fout << a;
}

char * Square::toStr() const
{
	char aChar[10] = {0};
	_gcvt(this->a,8,aChar);
	char * result = new char[15+strlen(aChar)];
	char * ptr = strcpy(result, "Square of side ");
	strcat(ptr, aChar);
	return result;
}