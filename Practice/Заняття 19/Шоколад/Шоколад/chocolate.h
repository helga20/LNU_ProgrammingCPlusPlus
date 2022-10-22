#pragma once
#include <string>
#include <iostream>

class Chocolate
{
protected:
	std::string chocolate;
	double cacao;
public:
	Chocolate();
	Chocolate(const std::string choc, double cc);
	Chocolate(const Chocolate& C);
	virtual ~Chocolate();

	virtual void printChocolate() const;
	virtual void readChocolate();
}; 
