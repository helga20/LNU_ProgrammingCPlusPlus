#include "Human.h"

void Human::printOn(std::ostream & os) const
{
	os << name << " (" << sex << ')';
}

std::ostream & operator<<(std::ostream & os, Gender gender)
{
	switch (gender)
	{
	case Male: os << "Male";
		break;
	case Female: os << "Female";
		break;
	default: os << "Unknown gender";
		break;
	}
	return os;
}

std::ostream & operator<<(std::ostream & os, const Human & human)
{
	human.printOn(os);
	return os;
}

std::ostream & operator<<(std::ostream & os, const Point & p)
{
	os << '<' << p.num << ',' << p.letter << ',' << p.word << '>';
	return os;
}

Point::Point(int point)
{
	num = point < 0 ? -point : point;
	if (num > 100) num = 100;
	if (num < 51)
	{
		letter = 'F';
		word = "unsatisfied";
	}
	else if (num < 61)
	{
		letter = 'E';
		word = "satisfied";
	}
	else if (num < 71)
	{
		letter = 'D';
		word = "satisfied";
	}
	else if (num < 81)
	{
		letter = 'C';
		word = "good";
	}
	else if (num < 90)
	{
		letter = 'B';
		word = "good";
	}
	else
	{
		letter = 'A';
		word = "excellent";
	}
}
