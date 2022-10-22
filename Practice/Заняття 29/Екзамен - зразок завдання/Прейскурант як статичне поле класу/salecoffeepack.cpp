#include "salecoffeepack.h"
using namespace std;

SaleCoffeePack::SaleCoffeePack()
	: CoffeePack(), m_sale(0)
{}

SaleCoffeePack::SaleCoffeePack(const std::string& producer, int weight, int sale)
	: CoffeePack(producer, weight), m_sale(sale)
{}

SaleCoffeePack::SaleCoffeePack(const SaleCoffeePack& S)
	: CoffeePack(S), m_sale(S.m_sale)
{}

SaleCoffeePack::~SaleCoffeePack()
{}

void SaleCoffeePack::readFrom(std::istream& in)
{
	CoffeePack::readFrom(in);
	in >> m_sale;
}

void SaleCoffeePack::writeTo(std::ostream& out) const
{
	CoffeePack::writeTo(out);
	out << ' ' << m_sale;
}

double SaleCoffeePack::getPrice() const
{
	double basePrice = 0.0;
	try
	{
		basePrice = CoffeePack::getPrice();
		double discountPrice = (basePrice / 100.0) * (double) m_sale;
		return basePrice - discountPrice;
	}
	catch (const PriceException& error)
	{
		throw error;
	}
}

int SaleCoffeePack::getSale() const
{
	return m_sale;
}