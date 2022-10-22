#pragma once
#include "person.h"

class Student : public Person
{
private:
	double mark;

public:
	Student();
	Student(const std::string& nm, const std::string& snm, double m);
	Student(const Student& S);
	virtual ~Student();

	virtual char getType() const override;
	virtual void workInfo() const override;
	virtual void printPersonInfo() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;

	virtual double getMark() const override;

	virtual Person* clone() const override;
};