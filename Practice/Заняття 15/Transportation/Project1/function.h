#pragma once
#include <string>
#include <iostream>
class Transportation
{
protected:
	std::string depart;
	std::string  arriv;
	int num;
	double price;
public:
	Transportation();
	Transportation(const std::string& dp, const std::string& arrv, int nm, double prc);
	Transportation(const Transportation& T);
	~Transportation();
	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};
std::istream& operator>>(std::istream& in, Transportation& T);
std::ostream& operator<<(std::ostream& out, const Transportation& T);