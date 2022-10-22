#pragma once
#include "person.h"

class Prof : public Person
{
public:
	Prof();
	Prof(const std::string& nm, const std::string& snm);
	Prof(const Prof& P);
	virtual ~Prof();

	virtual char getType() const override;
	virtual void workInfo() const override;
	virtual void printPersonInfo() const override;

	virtual Person* clone() const override;
};
