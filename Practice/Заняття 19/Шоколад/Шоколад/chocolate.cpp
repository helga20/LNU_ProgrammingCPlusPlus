#include "chocolate.h"
#include <iostream>

using namespace std;

Chocolate::Chocolate()
	: chocolate(), cacao(0.0)
{}

Chocolate::Chocolate(const std::string choc, double cc)
	: chocolate(choc), cacao(cc)
{}

Chocolate::Chocolate(const Chocolate& C)
	: chocolate(C.chocolate), cacao(C.cacao)
{}

Chocolate::~Chocolate()
{}

void Chocolate::printChocolate() const
{
	cout << "\nChocolate\n";
	cout << "Kind of chocolate: " << chocolate << "\n";
	cout << "Cacao content: " << cacao << " %" << "\n";
}

void Chocolate::readChocolate()
{
	cout << "Enter kind of chocolate:\n";
	cout << "Chocolate: "; cin >> chocolate;
	cout << "Cacao content: "; cin >> cacao;
}
