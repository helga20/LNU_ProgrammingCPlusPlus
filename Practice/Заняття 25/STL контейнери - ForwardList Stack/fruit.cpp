#include "fruit.h"
using namespace std;

Fruit::Fruit()
	: m_variety(), m_country()
{}

Fruit::Fruit(const string& variety, const string& country)
	: m_variety(variety), m_country(country)
{}

Fruit::Fruit(const Fruit& F)
	: m_variety(F.m_variety), m_country(F.m_country)
{}

Fruit::~Fruit()
{}

void Fruit::print() const
{
	cout << "Variety: " << m_variety << ". Country: " << m_country;
}

void Fruit::readFrom(std::istream& in)
{
	in >> m_variety >> m_country;
}

std::istream& operator>>(std::istream& in, Fruit& F)
{
	F.readFrom(in);
	return in;
}