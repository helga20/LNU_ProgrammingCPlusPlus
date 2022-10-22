#include "student.h"
#include <iostream>
using namespace std;

Student::Student()
	: Person(), groupName("no group")
{}

Student::Student(const std::string& nm, const std::string& snm, int ag, const std::string& group)
	: Person(nm, snm, ag), groupName(group)
{}

Student::Student(const Student& S)
	: Person(S), groupName(S.groupName)
{}

Student::~Student()
{}

void Student::workInfo() const
{
	cout << "Student in group: " << groupName << "\n";
}

void Student::printPersonInfo() const
{
	cout << "Student Info\n";
	Person::printPersonInfo();
	cout << "Group name: " << groupName << "\n";
}

void Student::readFrom(std::istream& in)
{
	Person::readFrom(in);
	in >> groupName;
}

void Student::writeTo(std::ostream& out) const
{
	Person::writeTo(out);
	out << ' ' << groupName;
}