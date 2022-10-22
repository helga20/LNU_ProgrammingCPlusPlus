#pragma once
#include <string>
#include <iostream>

class Person
{
protected:
	std::string name;
	std::string surname;

public:
	Person();
	Person(const std::string& nm, const std::string& snm);
	Person(const Person& P);
	virtual ~Person();

	virtual char getType() const abstract;
	virtual void workInfo() const abstract;
	virtual void printPersonInfo() const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;

	const std::string& getName() const;
	const std::string& getSurname() const;
};

std::istream& operator >> (std::istream& in, Person& P);
std::ostream& operator << (std::ostream& out, const Person& P);
