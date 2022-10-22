#include "person.h"
using namespace std;

Person::Person()
	: name("no name"), surname("no surname"), age(0)
{}

Person::Person(const string& nm, const string& snm, int ag)
	: name(nm), surname(snm), age(ag)
{}

Person::Person(const Person& P)
	: name(P.name), surname(P.surname), age(P.age)
{}

Person::~Person()
{}

void Person::printPersonInfo() const
{
	cout << "Name: " << name << ". Surname: " << surname << ". Age: " << age << "\n";
}

void Person::readFrom(istream& in)
{
	in >> name >> surname >> age;
}

void Person::writeTo(ostream& out) const
{
	out << name << ' ' << surname << ' ' << age;
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