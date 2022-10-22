#pragma once
#include <string>
#include <iostream>

class FruitTree
{
protected:
	std::string name;
	int age;
	double height;
	int weight;

public:
	FruitTree();
	FruitTree(const std::string& nm, int ag, double h, int w);
	FruitTree(const FruitTree& F);
	~FruitTree();

	virtual int getWeight() const;
	void addOneYear();

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

std::istream& operator >>(std::istream& in, FruitTree& F);
std::ostream& operator <<(std::ostream& out, const FruitTree& F);