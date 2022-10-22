#pragma once
#include <string>
#include <iostream>

class Fruit
{
protected:
	std::string m_variety;
	std::string m_country;

public:
	Fruit();
	Fruit(const std::string& variety, const std::string& country);
	Fruit(const Fruit& F);
	virtual ~Fruit();

	virtual std::string getType() const abstract;
	virtual Fruit* clone() const abstract;
	virtual void print() const;
	virtual void readFrom(std::istream& in);
};

std::istream& operator>>(std::istream& in, Fruit& F);