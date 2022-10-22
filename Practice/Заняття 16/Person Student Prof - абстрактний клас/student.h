#pragma once
#include "person.h"

class Student : public Person
{
private:
	std::string groupName;

public:
	Student();
	Student(const std::string& nm, const std::string& snm, int ag, const std::string &group);
	Student(const Student& S);
	virtual ~Student();

	virtual void workInfo() const override;
	virtual void printPersonInfo() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};