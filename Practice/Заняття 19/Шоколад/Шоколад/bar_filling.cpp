#include<string>
#include "bar_filling.h"
using namespace std;

BarWithFilling::BarWithFilling()
	: Chocolate(), Filling(), makerName()
{}

BarWithFilling::BarWithFilling(const std::string& maker, const Chocolate& choc, const Filling& fil)
	: Chocolate(choc), Filling(fil), makerName(maker)
{}

BarWithFilling::BarWithFilling(const std::string& maker, const std::string& choc, double cac, const std::string& kindOf)
	: Chocolate(choc, cac), Filling(kindOf), makerName(maker)
{}

BarWithFilling::BarWithFilling(const BarWithFilling& BF)
	: Chocolate(BF), Filling(BF), makerName(BF.makerName)
{}

BarWithFilling::~BarWithFilling()
{}

void BarWithFilling::printBarWithFilling() const
{
	cout << "Manufacturer: ";
	cout << makerName << " ";
	printChocolate(); 
	printFilling(); 
	cout << "\n";
}

void BarWithFilling::readBarWithFilling()
{
	cout << "Enter manufacturer info \n";
	cout << "Manufacturer: "; cin >> makerName;
	readChocolate();
	readFilling();
	cout << " * ";
	Chocolate::printChocolate();
	cout << " * ";
	cout << "\n";
	
}

void BarWithFilling::printChocolate() const
{
	cout << cacao << " %\n";
}

void BarWithFilling::printFilling() const
{
	cout << "Filling: " << kindFilling << "(gluten-free)\n";
}
