#pragma once
#include "sportsman.h"

class TennisPlayer : public Sportsman
{
private:
	double income;
	int rating;
public:
	TennisPlayer();
	TennisPlayer(const std::string& snm, double icm, int rtng);
	TennisPlayer(const TennisPlayer& T);
	virtual ~TennisPlayer();

	virtual void printSportsmanInfo() const override;
	virtual double incomeInfo() const override;
	void setRating(int rtng);

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};

