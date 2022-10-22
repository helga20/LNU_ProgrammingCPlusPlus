#include "footballer.h"
#include <iostream>
using namespace std;

Footballer::Footballer()
	: Sportsman(), goals(0)
{}

Footballer::Footballer(const std::string& snm, int gls)
	: Sportsman(snm), goals(gls)
{}

Footballer::Footballer(const Footballer& F)
	: Sportsman(F), goals(F.goals)
{}

Footballer::~Footballer()
{}

void Footballer::printSportsmanInfo() const
{
	cout << "Footballer Info\n";
	Sportsman::printSportsmanInfo();
	cout << "Goals: " << goals << "\n";
}

double Footballer::incomeInfo() const
{
	return goals * 100.0;
}

void Footballer::setGoals(int gls)
{
	if (gls < 0)
	{
		cout << "Error! The number of goals cannot be negative\n";
	}
	else
	{
		goals = gls;
	}
}

void Footballer::readFrom(std::istream& in)
{
	Sportsman::readFrom(in);
	in >> goals;
}

void Footballer::writeTo(std::ostream& out) const
{
	Sportsman::writeTo(out);
	out << ' ' << goals;
}
