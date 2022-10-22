#pragma once
#include <iostream>
#include <string>
using namespace std;

class Kid
{
private:
	int m_age;

public:
	Kid(int age = 10) : m_age(age) {}
	void writeTo(ostream& out) const { out << "Kid, " << m_age << " years."; }
};
ostream& operator<<(ostream& out, const Kid& K) { K.writeTo(out); return out; }

class Developer
{
private:
	string m_seniority;

public:
	Developer(const string& seniority = "Junior") : m_seniority(seniority) {}
	void writeTo(ostream& out) const { out << m_seniority << " C++ Developer."; }
};
ostream& operator<<(ostream& out, const Developer& D) { D.writeTo(out); return out; }

class Tourist
{
private:
	string m_country;

public:
	Tourist(const string& country = "Poland") : m_country(country) {}
	void writeTo(ostream& out) const {	out << "Tourist from " << m_country << "."; }
};
ostream& operator<<(ostream& out, const Tourist& T) { T.writeTo(out); return out; }

class Student
{
private:
	int m_year;

public:
	Student(int year = 1) : m_year(year) {}
	void writeTo(ostream& out) const { out << "Student of " << m_year << " year."; }
};
ostream& operator<<(ostream& out, const Student& S) { S.writeTo(out); return out; }