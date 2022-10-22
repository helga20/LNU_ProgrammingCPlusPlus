#pragma once
#include "Shape.h"

/* Циліндр - це круг, у якого є висота!
*/
class DerivCylinder: public Circle
{
private:
	double h;
public:
	DerivCylinder() :Circle(), h(1.){}
	DerivCylinder(double radius, double height) :Circle(radius), h(height){}
	double baseArea() const;
	double sideArea() const;
	double totalArea() const { return this->baseArea()*2. + this->sideArea(); }
	double volume() const;
	virtual void printOn(std::ostream& os) const override;
};

/* Циліндр містить круг і висоту
*/
class ComposedCylinder
{
private:
	Circle base;
	double h;
public:
	ComposedCylinder() :/*base(Circle()),*/ h(1.){}
	ComposedCylinder(double radius, double height) :base(radius), h(height){}
	double baseArea() const { return base.area(); }
	double sideArea() const { return base.perim() * h; }
	double totalArea() const { return this->baseArea()*2. + this->sideArea(); }
	double volume() const { return base.area() * h; }
	void printOn(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const ComposedCylinder& C);