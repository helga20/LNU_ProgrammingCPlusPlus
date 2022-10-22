#include "person.h"
using namespace std;

Person::Person() : name("no name"), surname("no surname")
{}

Person::Person(const string& nm, const string& snm) : name(nm), surname(snm)
{}

Person::Person(const Person& P)	: name(P.name), surname(P.surname)
{}

Person::~Person()
{}

void Person::printPersonInfo() const
{
	cout << "Name: " << name << ". Surname: " << surname << "\n";
}

void Person::readFrom(istream& in)
{
	in >> name >> surname;
}

void Person::writeTo(ostream& out) const
{
	out << name << ' ' << surname;
}

istream& operator >> (istream& in, Person& P)
{
	P.readFrom(in);
	return in;
}

ostream& operator << (ostream& out, const Person& P)
{
	P.writeTo(out);
	return out;
}

const std::string& Person::getName() const
{
	return name;
}

const std::string& Person::getSurname() const
{
	return surname;
}