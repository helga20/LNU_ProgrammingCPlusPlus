#ifndef Stud_MI_H_
#define Stud_MI_H_

#include <iostream>
#include "arraydb.h"
#include "str.h"
using std::ostream;
using std::istream;

class Student: private NewStr, private ArrayDb
{
public:
	Student(): NewStr("Nobody"), ArrayDb() {}
	Student(const NewStr& s): NewStr(s), ArrayDb() {}
	Student(int n): NewStr("Anybody"), ArrayDb(n) {}
	Student(const NewStr& s, int n): NewStr(s), ArrayDb(n) {}
	Student(const NewStr& s, const ArrayDb& a): NewStr(s), ArrayDb(a) {}
	Student(const char* str, const double* pd, int n): NewStr(str), ArrayDb(pd,n) {}
	~Student() {}
	double& operator[](int i);
	const double& operator[](int i) const;
	double average() const;
	friend ostream& operator<<(ostream& os, const Student& stu);
	friend istream& operator>>(istream& is, Student& stu);
};
#endif