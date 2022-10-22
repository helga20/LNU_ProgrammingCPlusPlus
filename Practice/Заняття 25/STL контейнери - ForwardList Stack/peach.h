#pragma once
#include "fruit.h"

class Peach : public Fruit
{
private:
	int m_weight;

public:
	Peach();
	Peach(const std::string& variety, const std::string& country, int weight);
	Peach(const Peach& P);
	virtual ~Peach();

	virtual std::string getType() const override;
	virtual Fruit* clone() const override;
	virtual void print() const override;
	virtual void readFrom(std::istream& in) override;
	bool operator<(const Peach& P) const;

	static const std::string PEACH_TYPE;
};
