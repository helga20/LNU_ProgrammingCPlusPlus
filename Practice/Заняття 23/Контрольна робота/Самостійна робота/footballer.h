#pragma once
#include "sportsman.h"

class Footballer : public Sportsman
{
private:
	int goals;
public:
	Footballer();
	Footballer(const std::string& snm, int gls);
	Footballer(const Footballer& F);
	virtual ~Footballer();

	virtual void printSportsmanInfo() const override;
	virtual double incomeInfo() const override;
	void setGoals(int gls);

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};
