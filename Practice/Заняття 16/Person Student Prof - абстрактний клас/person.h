#pragma once
#include <string>
#include <iostream>

class Person
{
protected:
	std::string name;
	std::string surname;
	int age;

public:
	Person();
	Person(const std::string& nm, const std::string& snm, int ag);
	Person(const Person& P);
	virtual ~Person();

	// abstract (pure virtual)
	virtual void workInfo() const abstract; // = 0;
	// virtual but not abstract
	virtual void printPersonInfo() const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

std::istream& operator >> (std::istream& in, Person& P);
std::ostream& operator << (std::ostream& out, const Person& P);
