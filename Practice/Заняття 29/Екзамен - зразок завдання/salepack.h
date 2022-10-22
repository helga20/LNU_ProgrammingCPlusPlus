#pragma once
#include "coffeepack.h"

class SalePack : public CoffeePack
{
private:
	int m_discount;

public:
	SalePack(std::map<std::string, int>* prices = nullptr);
	SalePack(const std::string& producer, int weigth, int discount, std::map<std::string, int>& prices);
	SalePack(const SalePack& S);
	virtual ~SalePack();

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
	virtual double getPrice() const override;
	virtual char getType() const override;
	virtual void initialize() override;

	int getDiscount() const;
};