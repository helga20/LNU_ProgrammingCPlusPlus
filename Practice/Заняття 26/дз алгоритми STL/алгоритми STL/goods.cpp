#include "goods.h"
#include <fstream>
using namespace std;

Goods::Goods()
	: category("no category"), name("no name"), price(0.0)
{}

Goods::Goods(const std::string& ctgr, const std::string& nm, double prc)
	: category(ctgr), name(nm), price(prc)
{}

Goods::Goods(const Goods& G)
	: category(G.category), name(G.name), price(G.price)
{}

Goods::~Goods()
{}

void Goods::printInfo() const
{
	cout << "Category: " << category << " | name: " << name << " | price: " << price << " hrn\n";
}

void Goods::printCategoryInfo() const
{
	cout << "*Product: " << name << " | price: " << price << " hrn\n";
}

double Goods::getPrice() const
{
	return price;
}

const std::string& Goods::getCategory() const
{
	return category;
}

const std::string& Goods::getName() const
{
	return name;
}

bool Goods::operator< (const Goods& G) const
{
	return price < G.getPrice();
}

bool Goods::operator> (const Goods& G) const
{
	return price > G.getPrice();
}

double Goods::getDiscountMax() const
{
	double cheaper = (price / 100) * 10;
	double discount = price - cheaper;
	cout << "After discount: " << discount << endl;
	return discount;
}

double Goods::getDiscountMin() const
{
	cout << "After discount: " << price * 1.25 << endl;
	return price * 1.25;
}

void Goods::readFrom(std::istream& in)
{
	in >> category >> name >> price;
}

void Goods::writeTo(std::ostream& out) const
{
	out << category << " " << name << " " << price << " ";
}

std::istream& operator>>(std::istream& in, Goods& G)
{
	G.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Goods& G)
{
	G.writeTo(out);
	return out;
}

void readGoodsFromFile(std::vector<Goods>& goods, const std::string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		Goods good; iFile >> good;
		goods.push_back(good);
	}
	iFile.close();
}