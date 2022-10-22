#include "tree.h"
#include <iostream>
using namespace std;

FruitTree::FruitTree()
	: name(), age(0), height(0.), weight(0)
{
//	cout << "FruitTree - default\n";
}

FruitTree::FruitTree(const std::string& nm, int ag, double h, int w)
	: name(nm), age(ag), height(h), weight(w)
{
//	cout << "FruitTree - parameter\n";
}

FruitTree::FruitTree(const FruitTree& F)
	: name(F.name), age(F.age), height(F.height), weight(F.weight)
{
//	cout << "FruitTree - copy\n";
}

FruitTree::~FruitTree()
{
//	cout << "FruitTree - destructor\n";
}

int FruitTree::getWeight() const
{
	if (age >= 3)
	{
		return weight;
	}
	return 0;
}

void FruitTree::addOneYear()
{
	if (age >= 3)
	{
		weight += 2;
	}	

	age += 1;
	height += 0.2;
}

void FruitTree::readFrom(std::istream& in)
{
	in >> name >> age >> height >> weight;
}

void FruitTree::writeTo(std::ostream& out) const
{
	out << name << ' ' << age << ' ' << height << ' ' << weight;
}

std::istream& operator >>(std::istream& in, FruitTree& F)
{
	F.readFrom(in);
	return in;
}

std::ostream& operator <<(std::ostream& out, const FruitTree& F)
{
	F.writeTo(out);
	return out;
}