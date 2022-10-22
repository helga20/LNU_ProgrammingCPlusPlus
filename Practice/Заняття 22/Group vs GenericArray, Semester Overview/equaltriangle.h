#pragma once
#include "triangle.h"

class EqualTriangle : public Triangle
{
public:
	EqualTriangle();
	EqualTriangle(double a);
	EqualTriangle(const EqualTriangle& ET);
	virtual ~EqualTriangle();

	virtual Triangle* clone() const override;
	virtual char getType() const override;
	virtual double perimeter() const override;
	virtual double square() const override;
	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;

};