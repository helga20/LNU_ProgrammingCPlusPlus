#include "pch.h"
#include "Person.h"


Person::Person(): Date(), name("Unknown")
{
}


Person::~Person()
{
}

std::ostream & operator<<(std::ostream & os, const Person & person)
{
	person.printOn(os);
	return os;
}
