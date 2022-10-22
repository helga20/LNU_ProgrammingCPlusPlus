#pragma once
#include "triangle.h"
#include "shape.h"

class Prism : public Shape
{
private:
	Triangle* base;
	double height;

public:
	Prism();
	Prism(Triangle* prismBase, double prismH);
	Prism(const Prism& P);
	~Prism();

	virtual double sideSquare() const override;
	virtual double fullSquare() const override;
	virtual double volume() const override;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Prism& P);
std::ostream& operator<<(std::ostream& out, const Prism& P);

