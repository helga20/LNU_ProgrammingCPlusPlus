#pragma once
#include "fruit.h"

class Apple : public Fruit
{
private:
	std::string m_season;

public:
	Apple();
	Apple(const std::string& variety, const std::string& country, const std::string &season);
	Apple(const Apple& A);
	virtual ~Apple();

	virtual std::string getType() const override;
	virtual Fruit* clone() const override;
	virtual void print() const override;
	virtual void readFrom(std::istream& in) override;
	bool operator<(const Apple& A) const;

	static const std::string APPLE_TYPE;
};
