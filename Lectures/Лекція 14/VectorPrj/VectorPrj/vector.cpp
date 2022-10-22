#include <cmath>
#include "vector.h"
using std::cout;
namespace VECTOR
{
	const double rad_to_deg = 57.2957795130823;
	void Vector::set_mag()
	{
		mag = sqrt(x*x+y*y);
	}
	void Vector::set_ang()
	{
		if ( x==0 && y==0 ) ang = 0.0;
		else ang = atan2(y,x);
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = 'r';
	}
	Vector::Vector(double a, double b, char form)
	{
		set(a,b,form);
	}
	Vector::Vector(double m)
	{
		x = mag = m;
		y = ang = 0.0;
		mode = 'p';
	}
	Vector::~Vector(){}
	void Vector::set(double a, double b, char form)
	{
		mode = form;
		if (form=='r') {
			x = a; y = b; set_mag(); set_ang();
		} else if (form=='p') {
			mag = a; ang = b; set_x(); set_y();
		} else {
			cout << "Incorrect third argument to Vector(). A vector set to 0.\n";
			x = y = mag = ang = 0.0; mode = 'r';
		}
	}
	Vector Vector::operator+(const Vector& b) const
	{
		return Vector( x + b.x, y + b.y );
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector( x - b.x, y - b.y );
	}
	Vector Vector::operator-() const
	{
		return Vector( -x, -y );
	}
	Vector Vector::operator*(double n) const
	{
		return Vector( n * x, n * y );
	}
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	ostream& operator<<(ostream& os, const Vector& a)
	{
		if (a.mode=='r')
			os<<" (x,y) = ( "<<a.x<<", "<<a.y<<" )";
		else if (a.mode=='p')
			os<<" (m,a) = ( "<<a.mag<<", "<<a.ang*rad_to_deg<<" )";
		else os<<"ERROR: Vector object mode is invalid!";
		return os;
	}
}