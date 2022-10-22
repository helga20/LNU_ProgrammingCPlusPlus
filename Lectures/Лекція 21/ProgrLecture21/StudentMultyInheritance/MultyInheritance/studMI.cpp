#include "studMI.h"

double Student::average() const
{
	return ArrayDb::average();
}
double& Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}
const double& Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}
ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Student's " << (const NewStr&) stu
		<< " scores are:\n" << (const ArrayDb&) stu;
	return os;
}
istream& operator>>(istream& is, Student& stu)
{
	is >> (NewStr&) stu;
	return is;
}