#include "studIncl.h"

double Student::average() const
{
	return scores.average();
}
double& Student::operator[](int i)
{
	return scores[i];
}
const double& Student::operator[](int i) const
{
	return scores[i];
}
ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Student's " << stu.name << " scores are:\n" << stu.scores;
	return os;
}
istream& operator>>(istream& is, Student& stu)
{
	is >> stu.name;
	return is;
}