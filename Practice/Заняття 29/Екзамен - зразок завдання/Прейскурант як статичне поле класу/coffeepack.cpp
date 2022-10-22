#include "coffeepack.h"
#include <algorithm>
using namespace std;

std::map<std::string, int> CoffeePack::s_prices = {};

CoffeePack::CoffeePack()
	: m_producer(), m_weight(0)
{}

CoffeePack::CoffeePack(const string& producer, int weight)
	: m_producer(producer), m_weight(weight)
{}

CoffeePack::CoffeePack(const CoffeePack& C)
	: m_producer(C.m_producer), m_weight(C.m_weight)
{}

CoffeePack::~CoffeePack()
{}

void CoffeePack::readFrom(istream& in)
{
	in >> m_producer >> m_weight;
}

void CoffeePack::writeTo(ostream& out) const
{
	out << m_producer << ' ' << m_weight;
}

double CoffeePack::getPrice() const
{
	map<string, int>::iterator findIt = s_prices.find(m_producer);
	if (findIt == s_prices.end())
		throw PriceException(m_producer);
	
	double gramPrice = (double)findIt->second / 1000.0;
	return gramPrice * (m_weight);
}

bool CoffeePack::operator<(const CoffeePack& C) const
{
	return getPrice() < C.getPrice();
}

CoffeePack& CoffeePack::operator+(int weight)
{
	m_weight += weight;
	return *this;
}

void CoffeePack::increaseWeigh(int weight)
{
	m_weight += weight;
}

std::istream& operator>>(std::istream& in, CoffeePack& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const CoffeePack& C)
{
	C.writeTo(out);
	return out;
}