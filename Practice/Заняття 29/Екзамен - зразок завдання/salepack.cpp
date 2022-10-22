#include "salepack.h"
using namespace std;

SalePack::SalePack(std::map<std::string, int>* prices)
	: CoffeePack(prices), m_discount(0)
{}

SalePack::SalePack(const std::string& producer, int weigth, int discount, std::map<std::string, int>& prices)
	: CoffeePack(producer, weigth, prices), m_discount(discount)
{}

SalePack::SalePack(const SalePack& S)
	: CoffeePack(S), m_discount(S.m_discount)
{}

SalePack::~SalePack()
{}

void SalePack::readFrom(std::istream& in)
{
	CoffeePack::readFrom(in);
	in >> m_discount;
}

void SalePack::writeTo(std::ostream& out) const
{
	CoffeePack::writeTo(out);
	out << ' ' << m_discount;
}

double SalePack::getPrice() const
{
	try
	{
		double basePrice = CoffeePack::getPrice();
		double discountValue = (basePrice / 100.0) * (double)m_discount;
		return basePrice - discountValue;
	}
	catch (const CoffeePriceException& E)
	{
		throw E;
	}
}

char SalePack::getType() const
{
	return 'S';
}

void SalePack::initialize()
{
	CoffeePack::initialize();
	cout << "Enter discount: "; cin >> m_discount;
}

int SalePack::getDiscount() const
{
	return m_discount;
}