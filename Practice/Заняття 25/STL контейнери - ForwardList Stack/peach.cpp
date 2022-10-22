#include "peach.h"
using namespace std;

const string Peach::PEACH_TYPE = "Peach";

Peach::Peach()
	: Fruit(), m_weight(0)
{}

Peach::Peach(const string& variety, const string& country, int weight)
	: Fruit(variety, country), m_weight(weight)
{}

Peach::Peach(const Peach& P)
	: Fruit(P), m_weight(P.m_weight)
{}

Peach::~Peach()
{}

string Peach::getType() const
{
	return Peach::PEACH_TYPE;
}

Fruit* Peach::clone() const
{
	return new Peach(*this);
}

void Peach::print() const
{
	cout << "Peach fruit. ";
	Fruit::print();
	cout << ". Weight: " << m_weight << " gr.";
}

void Peach::readFrom(istream& in)
{
	Fruit::readFrom(in);
	in >> m_weight;
}

bool Peach::operator<(const Peach& P) const
{
	return m_weight < P.m_weight;
}