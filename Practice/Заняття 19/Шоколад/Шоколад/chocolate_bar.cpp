#include "chocolate_bar.h"
#include <iostream>

using namespace std;

ChocolateBar::ChocolateBar()
	: weight(0.0), choccy()
{}

ChocolateBar::ChocolateBar(double wght, const Chocolate& C)
	: weight(wght), choccy(C)
{}

ChocolateBar::ChocolateBar(double wght, const std::string& choc, double cc)
	: weight(wght), choccy(choc, cc)
{}

ChocolateBar::ChocolateBar(const ChocolateBar& B)
	: weight(B.weight), choccy(B.choccy)
{}

ChocolateBar::~ChocolateBar()
{}

void ChocolateBar::printChocolateBar() const
{
	cout << "Weight of chocolate bar: ";
	cout << weight << " gr";
	choccy.printChocolate(); 
	cout << "\n";
}

void ChocolateBar::readChocolateBar()
{
	cout << "Enter info about weight of bar \n";
	cout << "Weight: "; cin >> weight;
	choccy.readChocolate();
}
