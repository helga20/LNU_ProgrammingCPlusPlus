#include "prism.h"
#include "equaltriangle.h"
using namespace std;

Prism::Prism()
	: base(nullptr), height(0.0)
{}

Prism::Prism(Triangle* prismBase, double prismH)
	: base(prismBase->clone()), height(prismH)
{}

Prism::Prism(const Prism& P)
	: base(P.base->clone()), height(P.height)
{}

Prism::~Prism()
{
	delete base;
}

double Prism::sideSquare() const
{
	if (base == nullptr)
		throw "Invalid prism.";

	double s = base->perimeter() * height;
	return s;
}

double Prism::fullSquare() const
{
	if (base == nullptr)
		throw "Invalid prism.";

	double sBase = base->square();
	double sTotal = 2.0 * sBase + sideSquare();
	return sTotal;
}

double Prism::volume() const
{
	if (base == nullptr)
		throw "Invalid prism.";

	double v = base->square() * height;
	return v;
}

void Prism::readFrom(std::istream& in)
{
	in >> height;
	char type; in >> type;
	if (type == 'T')
	{
		base = new Triangle();
		in >> *base;
	}
	else if (type == 'E')
	{
		base = new EqualTriangle();
		in >> *base;
	}
	else
	{
		base = nullptr;
		throw "Invalid data.";
	}
}

void Prism::writeTo(std::ostream& out) const
{
	if (base == nullptr)
		throw "Invalid prism.";

	out << height << ' ' << base->getType() << ' ' << *base;
}

std::istream& operator>>(std::istream& in, Prism& P)
{
	P.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Prism& P)
{
	P.writeTo(out);
	return out;
}