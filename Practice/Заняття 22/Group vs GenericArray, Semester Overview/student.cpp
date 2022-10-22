#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : Person(), mark(0.)
{}

Student::Student(const std::string& nm, const std::string& snm, double m) : Person(nm, snm), mark(m)
{}

Student::Student(const Student& S) : Person(S), mark(S.mark)
{}

Student::~Student()
{}

void Student::workInfo() const
{
	cout << "Student with average mark: " << mark << "\n";
}

void Student::printPersonInfo() const
{
	cout << "Student Info\n";
	Person::printPersonInfo();
	cout << "Average mark: " << mark << "\n";
}

void Student::readFrom(std::istream& in)
{
	Person::readFrom(in);
	in >> mark;
}

void Student::writeTo(std::ostream& out) const
{
	Person::writeTo(out);
	out << ' ' << mark;
}

char Student::getType() const
{
	return 'S';
}

double Student::getMark() const
{
	return mark;
}

Person* Student::clone() const
{
	return new Student(*this);
}

bool Student::operator==(const Student& S) const
{
	return surname == S.getSurname();
}