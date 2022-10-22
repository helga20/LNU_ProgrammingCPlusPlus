#pragma once
#include "chocolate.h"
#include "filling.h"
#include <string>

class BarWithFilling : public Chocolate, public Filling
{
private:
	std::string makerName;
public:
	BarWithFilling();
	BarWithFilling(const std::string& maker, const Chocolate& choc, const Filling& fil);
	BarWithFilling(const std::string& maker, const std::string& choc, double cac, const std::string& kindOf);
	BarWithFilling(const BarWithFilling& BF);
	virtual ~BarWithFilling();

	void printBarWithFilling() const;
	void readBarWithFilling();

	virtual void printChocolate() const override;
	virtual void printFilling() const override;
};