#include "pch.h"
#include "Human.h"


Human::Human()
{
	name = "Unknown";
	birthday = Date::DateToday();
}


Human::~Human()
{
}

std::ostream & operator<<(std::ostream & os, const Human & human)
{
	human.printOn(os);
	return os;
}
