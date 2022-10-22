#pragma once
#include "chocolate.h"
#include <string>

class Snickers : private Chocolate
{
private: 
	double weight;
public:
	Snickers();
	Snickers(double wght, const Chocolate& C);
	Snickers(double wght, const std::string& choc, double cc);
	Snickers(const Snickers& S);
	~Snickers();

	virtual void printChocolate() const override;
	virtual void readChocolate() override;

	void printSnickers() const;
	void readSnickers();
};