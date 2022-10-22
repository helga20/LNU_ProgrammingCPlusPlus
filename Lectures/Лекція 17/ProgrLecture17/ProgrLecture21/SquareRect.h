#pragma once
#include <iostream>

// квадрат зберігає сторону
class BaseSquare
{
protected:
	double a;
public:
	BaseSquare() :a(3.) {}
	BaseSquare(double x) { a = x > 0.1 ? x : 0.1; }
	virtual ~BaseSquare() {}
	virtual void printOn(std::ostream& os) const { os << "BaseSquare( " << a << " )"; }
	virtual double area() const { return a*a; }
	virtual double perim() const { return 4.*a; }
};

// прямокутникові порібно ще одну сторону
class RectSquare :public BaseSquare
{
private:
	double b;
public:
	RectSquare() :BaseSquare(), b(4.) {}
	RectSquare(double x, double y) :BaseSquare(x) { b = y > 0.1 ? y : 0.1; }
	virtual void printOn(std::ostream& os) const { BaseSquare::printOn(os); os << " x ( " << b << " )"; }
	virtual double area() const { return a*b; }
	virtual double perim() const { return 2.*(a + b); }
};