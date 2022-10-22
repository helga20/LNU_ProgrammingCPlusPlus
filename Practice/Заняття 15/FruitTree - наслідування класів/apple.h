#pragma once
#include "tree.h"

class AppleTree : public FruitTree
{
private:
	std::string color;

public:
	AppleTree();
	AppleTree(const std::string& nm, int ag, double h, int w, const std::string& clr);
	AppleTree(const AppleTree& A);
	~AppleTree();

	virtual int getWeight() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;

	const std::string& getColor() const;

};
