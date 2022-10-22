#include "prof.h"
#include <iostream>
using namespace std;

Prof::Prof() : Person()
{}

Prof::Prof(const std::string& nm, const std::string& snm) : Person(nm, snm)
{}

Prof::Prof(const Prof& P) : Person(P)
{}

Prof::~Prof()
{}

void Prof::workInfo() const
{
	cout << "Professor of university course\n";
}

void Prof::printPersonInfo() const
{
	cout << "Prof Info\n";
	Person::printPersonInfo();
}

char Prof::getType() const
{
	return 'P';
}

//const std::string& Prof::getName() const
//{
//	return name;
//}
//
//const std::string& Prof::getSurname() const
//{
//	return surname;
//}