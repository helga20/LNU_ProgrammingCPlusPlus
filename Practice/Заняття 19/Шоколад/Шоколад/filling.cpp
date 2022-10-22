#include "filling.h"
#include <iostream>
using namespace std;

Filling::Filling()
	: kindFilling()
{}

Filling::Filling(const std::string& kind)
	: kindFilling(kind)
{}

Filling::Filling(const Filling& F)
	: kindFilling(F.kindFilling)
{}

Filling::~Filling()
{}

void Filling::printFilling() const
{
	cout << "Filling: ";
	cout << kindFilling << " ";
	cout << "\n";
}

void Filling::readFilling()
{
	cout << "Enter filling info \n";
	cout << "Filling: "; cin >> kindFilling;
}

