#include "capital.h"
using namespace std;

Capital::Capital()
	: name("no name"), population(0.0)
{}

Capital::Capital(const std::string& nm, double pp)
	: name(nm), population(pp)
{}

Capital::Capital(const Capital& C)
	: name(C.name), population(C.population)
{}

Capital::~Capital() 
{}

void Capital::readCapital()
{
	cout << "Enter information about the capital:\n";
	cout << "Name: "; cin >> name;
	cout << "Population: "; cin >> population;
}

const std::string& Capital::getName()
{
	return name;
}

double Capital::getPopulation() const
{
	return population;
}

void Capital::printCapitalInfo() const
{
	cout << "Name: " << name << ". Population: " << population << "\n";
}

void Capital::readFrom(std::istream& in)
{
	in >> name >> population;
}

void Capital::writeTo(std::ostream& out) const
{
	out << name << " " << population;
}

std::istream& operator>>(std::istream& in, Capital& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Capital& C)
{
	C.writeTo(out);
	return out;
}

