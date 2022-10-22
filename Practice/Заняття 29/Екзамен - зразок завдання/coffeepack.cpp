#include "coffeepack.h"
using namespace std;

CoffeePack::CoffeePack(std::map<std::string, int>* prices)
	: m_producer(), m_weight(0), m_prices(prices)
{}

CoffeePack::CoffeePack(const std::string& producer, int weigth, std::map<std::string, int>& prices)
	: m_producer(producer), m_weight(weigth), m_prices(&prices)
{}

CoffeePack::CoffeePack(const CoffeePack& C)
	: m_producer(C.m_producer), m_weight(C.m_weight), m_prices(C.m_prices)
{}

CoffeePack::~CoffeePack()
{}

void CoffeePack::readFrom(std::istream& in)
{
	in >> m_producer >> m_weight;
}

void CoffeePack::writeTo(std::ostream& out) const
{
	out << m_producer << ' ' << m_weight;
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

double CoffeePack::getPrice() const
{
	map<string, int>::const_iterator itFind = m_prices->find(m_producer);
	if (itFind == m_prices->cend())
	{
		throw CoffeePriceException(m_producer);
	}

	int kgPrice = itFind->second;
	double price = ((double)kgPrice / 1000.0) * (double)m_weight;
	return price;
}

CoffeePack& CoffeePack::operator=(const CoffeePack& C)
{
	m_producer = C.m_producer;
	m_weight = C.m_weight;
	m_prices = C.m_prices;
	return *this;
}

bool CoffeePack::operator<(const CoffeePack& P) const
{
	try
	{
		return getPrice() < P.getPrice();
	}
	catch (const CoffeePriceException& E)
	{
		cout << "Comparison failed. ";
		E.printInfo();
		return false;
	}
}

void CoffeePack::increaseWeight(int weight)
{
	m_weight += weight;
}

char CoffeePack::getType() const
{
	return 'C';
}

const std::string& CoffeePack::getProducer() const
{
	return m_producer;
}

void CoffeePack::initialize()
{
	cout << "Enter producer: "; cin >> m_producer;
	cout << "Enter weight (gr): "; cin >> m_weight;
}

int CoffeePack::getWeight() const
{
	return m_weight;
}

void CoffeePack::setPricesTable(std::map<std::string, int>& prices)
{
	m_prices = &prices;
}