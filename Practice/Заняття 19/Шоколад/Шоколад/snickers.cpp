#include "snickers.h"
#include <iostream>

using namespace std;

Snickers::Snickers()
	: Chocolate(), weight(0.0)
{}

Snickers::Snickers(double wght, const Chocolate& C)
	: Chocolate(C), weight(wght)
{}

Snickers::Snickers(double wght, const std::string& choc, double cc)
	: Chocolate(choc, cc), weight(wght)
{}

Snickers::Snickers(const Snickers& S)
	: Chocolate(S), weight(S.weight)
{}

Snickers::~Snickers()
{}


void Snickers::printChocolate() const
{
	//cout << chocolate << " " << cacao << " %";
	//cout << cacao << " %\n";
	cout << chocolate << "\n";
	cout << cacao << " %\n";


}

void Snickers::readChocolate()
{
	cout << "Chocolate: "; cin >> chocolate;
	cout << "Cacao: "; cin >> cacao;
	cout << " * ";
	Chocolate::printChocolate();
	cout << " * ";
	cout << "\n";
}

void Snickers::printSnickers() const
{
	cout << "Weight of chocolate bar: ";
	cout << weight << " gr";
	printChocolate();
	cout << "\n";
}

void Snickers::readSnickers()
{
	cout << "Enter info about weight of snickers \n";
	cout << "Weight: "; cin >> weight;
	readChocolate();
}

