#include "sportsman.h"
#include <iostream>
using namespace std;

Sportsman::Sportsman()
	: surname("no surname")
{}

Sportsman::Sportsman(const std::string& snm)
	: surname(snm)
{}

Sportsman::Sportsman(const Sportsman& S)
	: surname(S.surname)
{}

Sportsman::~Sportsman()
{}

void Sportsman::printSportsmanInfo() const
{
	cout << "Surname: " << surname << "\n";
}

void Sportsman::readFrom(std::istream& in)
{
	in >> surname;
}

void Sportsman::writeTo(std::ostream& out) const
{
	out << surname << ' ';
}

std::istream& operator >> (std::istream& in, Sportsman& S)
{
	S.readFrom(in);
	return in;
}

std::ostream& operator << (std::ostream& out, const Sportsman& S)
{
	S.writeTo(out);
	return out;
}

