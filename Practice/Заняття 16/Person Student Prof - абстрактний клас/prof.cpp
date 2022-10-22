#include "prof.h"
#include <iostream>
using namespace std;

Prof::Prof()
	: Person(), courseName("no course")
{}

Prof::Prof(const std::string& nm, const std::string& snm, int ag, const std::string& course)
	: Person(nm, snm, ag), courseName(course)
{}

Prof::Prof(const Prof& P)
	: Person(P), courseName(P.courseName)
{}

Prof::~Prof()
{}

void Prof::workInfo() const
{
	cout << "Professor of course: " << courseName << "\n";
}

void Prof::printPersonInfo() const
{
	cout << "Prof Info\n";
	Person::printPersonInfo();
	cout << "Course name: " << courseName << "\n";
}

void Prof::readFrom(std::istream& in)
{
	Person::readFrom(in);
	in >> courseName;
}

void Prof::writeTo(std::ostream& out) const
{
	Person::writeTo(out);
	out << ' ' << courseName;
}