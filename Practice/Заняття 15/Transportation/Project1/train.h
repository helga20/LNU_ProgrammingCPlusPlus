#pragma once
#include "function.h"
class Train : public Transportation
{
private:
	int van;
public:
	Train();
	Train(const std::string& dp, const std::string& arrv, int nm, double prc, int vn);
	Train(const Train& V);
	~Train();
	virtual double getPrice() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};
double totalPrice(Train* arr, const int n);
