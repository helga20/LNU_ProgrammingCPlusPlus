#include "apple.h"
using namespace std;

const string Apple::APPLE_TYPE = "Apple";

Apple::Apple()
	: Fruit(), m_season()
{}

Apple::Apple(const string& variety, const string& country, const string& season)
	: Fruit(variety, country), m_season(season)
{}

Apple::Apple(const Apple& A)
	: Fruit(A), m_season(A.m_season)
{}

Apple::~Apple()
{}

string Apple::getType() const
{
	return Apple::APPLE_TYPE;
}

Fruit* Apple::clone() const
{
	return new Apple(*this);
}

void Apple::print() const
{
	cout << "Apple fruit. ";
	Fruit::print();
	cout << ". Season: " << m_season << ".";
}

void Apple::readFrom(istream& in)
{
	Fruit::readFrom(in);
	in >> m_season;
}

bool Apple::operator<(const Apple& A) const
{
	return m_season < A.m_season;
}


