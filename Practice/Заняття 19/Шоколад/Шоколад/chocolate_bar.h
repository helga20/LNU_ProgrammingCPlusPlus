#pragma once
#include "chocolate.h"
#include <string>

class ChocolateBar
{
private:
	double weight;
	Chocolate choccy;
public:
	ChocolateBar();
	ChocolateBar(double wght, const Chocolate& C);
	ChocolateBar(double wght, const std::string& choc, double cc);
	ChocolateBar(const ChocolateBar& B);
	~ChocolateBar();

	void printChocolateBar() const;
	void readChocolateBar();
};


