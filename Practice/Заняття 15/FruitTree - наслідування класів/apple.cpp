#include "apple.h"
#include <iostream>
using namespace std;

AppleTree::AppleTree()
	: FruitTree(), color()
{
//	cout << "AppleTree - default\n";
}

AppleTree::AppleTree(const std::string& nm, int ag, double h, int w, const std::string& clr)
	: FruitTree(nm, ag, h, w), color(clr)
{
//	cout << "AppleTree - parameter\n";
}

AppleTree::AppleTree(const AppleTree& A)
	: FruitTree(A), color(A.color)
{
//	cout << "AppleTree - copy\n";
}

AppleTree::~AppleTree()
{
//	cout << "AppleTree - destructor\n";
}

int AppleTree::getWeight() const
{
	if (age >= 3 && age % 2 > 0)
	{
		return weight;
	}
	return 0;
}

const std::string& AppleTree::getColor() const
{
	return color;
}

void AppleTree::readFrom(std::istream& in)
{
	FruitTree::readFrom(in);
	in >> color;
}

void AppleTree::writeTo(std::ostream& out) const
{
	FruitTree::writeTo(out);
	out << ' ' << color;
}
