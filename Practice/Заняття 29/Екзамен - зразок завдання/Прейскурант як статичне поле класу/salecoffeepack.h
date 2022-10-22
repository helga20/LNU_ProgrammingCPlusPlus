#pragma once
#include "coffeepack.h"

class SaleCoffeePack : public CoffeePack
{
private:
	int m_sale;

public:
	SaleCoffeePack();
	SaleCoffeePack(const std::string& producer, int weight, int sale);
	SaleCoffeePack(const SaleCoffeePack& S);
	virtual ~SaleCoffeePack();

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
	virtual double getPrice() const override;

	int getSale() const;
};