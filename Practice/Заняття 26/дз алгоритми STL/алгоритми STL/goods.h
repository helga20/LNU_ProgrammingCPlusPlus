#pragma once
#include <string>
#include <iostream>
#include <vector>

class Goods
{
private:
	std::string category;
	std::string name;
	double price;

public:
	Goods();
	Goods(const std::string& ctgr, const std::string& nm, double prc);
	Goods(const Goods& G);
	~Goods();

	void printInfo() const;
	void printCategoryInfo() const;
	double getPrice() const;
	const std::string& getCategory() const;
	const std::string& getName() const;

	bool operator< (const Goods& G) const;
	bool operator> (const Goods& G) const;

	double getDiscountMax() const;
	double getDiscountMin() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Goods& G);
std::ostream& operator<<(std::ostream& out, const Goods& G);

void readGoodsFromFile(std::vector<Goods>& goods, const std::string& fileName);