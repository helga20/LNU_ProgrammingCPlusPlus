#pragma once
#include "tree.h"

class ApricotTree : public FruitTree
{
private:
	bool freeze;

public:
	ApricotTree();
	ApricotTree(const std::string& nm, int ag, double h, int w, bool snow);
	ApricotTree(const ApricotTree& A);
	~ApricotTree();

	virtual int getWeight() const;
	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;

	void setFreeze(bool snow);
};
