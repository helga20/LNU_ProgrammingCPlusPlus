#pragma once
#include "person.h"

class Prof : public Person
{
private:
	std::string courseName;

public:
	Prof();
	Prof(const std::string& nm, const std::string& snm, int ag, const std::string& course);
	Prof(const Prof& P);
	virtual ~Prof();

	virtual void workInfo() const override;
	virtual void printPersonInfo() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};
