#include "apricot.h"
#include <iostream>
using namespace std;

ApricotTree::ApricotTree()
	: FruitTree(), freeze(false)
{}

ApricotTree::ApricotTree(const std::string& nm, int ag, double h, int w, bool snow)
	: FruitTree(nm, ag, h, w), freeze(snow)
{}

ApricotTree::ApricotTree(const ApricotTree& A)
	: FruitTree(A), freeze(A.freeze)
{}

ApricotTree::~ApricotTree()
{}

int ApricotTree::getWeight() const
{
	if (age >= 3)
	{
		if (freeze) // freeze == true
		{
			return weight * 0.2; // only 20%
		}
		return weight; // freeze == false
	}
	return 0; // age < 3
}

void ApricotTree::setFreeze(bool snow)
{
	freeze = snow;
}

void ApricotTree::readFrom(std::istream& in)
{
	FruitTree::readFrom(in);
	in >> freeze;
}

void ApricotTree::writeTo(std::ostream& out) const
{
	FruitTree::writeTo(out);
	out << ' ' << freeze;
}