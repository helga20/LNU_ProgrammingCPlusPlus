#ifndef _StudIncl_H_
#define _StudIncl_H_

#include <iostream>
#include "arraydb.h"
#include "str.h"
using std::ostream;
using std::istream;

class Student
{
private:
	NewStr name;
	ArrayDb scores;
public:
	Student(): name("Nobody"), scores() {}
	Student(const NewStr& s): name(s), scores() {}
	Student(int n): name("Anybody"), scores(n) {}
	Student(const NewStr& s, int n): name(s), scores(n) {}
	Student(const NewStr& s, const ArrayDb& a): name(s), scores(a) {}
	Student(const char* str, const double* pd, int n): name(str), scores(pd,n) {}
	~Student() {}
	double& operator[](int i);
	const double& operator[](int i) const;
	double average() const;
	friend ostream& operator<<(ostream& os, const Student& stu);
	friend istream& operator>>(istream& is, Student& stu);
};
#endif