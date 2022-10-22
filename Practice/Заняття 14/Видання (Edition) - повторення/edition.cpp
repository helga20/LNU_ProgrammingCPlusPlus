#include "edition.h"
using namespace std;

Edition::Edition()
	: author(), title(), price(0.), nofPages(0)
{}

Edition::Edition(const string& auth, const string& ttl, double prc, int n)
	: author(auth), title(ttl), price(prc), nofPages(n)
{}

Edition::Edition(const Edition& E)
	: author(E.author), title(E.title), price(E.price), nofPages(E.nofPages)
{}

Edition::~Edition()
{}

void Edition::print() const
{
	cout << "Author: " << author << ". Title: " << title << ". " << nofPages << " pages. Price: " << price << " uah.\n";
}

const string& Edition::getAuthor() const
{
	return author;
}

const string& Edition::getTitle() const
{
	return title;
}

double Edition::getPrice() const
{
	return price;
}

int Edition::getPages() const
{
	return nofPages;
}

void Edition::setAuthor(const std::string auth)
{
	author = auth;
}

void Edition::setTitle(const std::string ttl)
{
	title = ttl;
}

void Edition::setPrice(double prc)
{
	price = prc;
}

void Edition::setPages(int n)
{
	nofPages = n;
}

void Edition::writeTo(ostream& out) const
{
	out << author << ' ' << title << ' ' << price << ' ' << nofPages;
}

void Edition::readFrom(istream& in)
{
	in >> author >> title >> price >> nofPages;
}

double Edition::pagePrice() const
{
	return price / (double)nofPages;
}

bool Edition::operator<(const Edition& E) const
{
	return price < E.getPrice();
}

std::ostream& operator<<(std::ostream& out, const Edition& E)
{
	E.writeTo(out);
	return out;
}

std::istream& operator>>(std::istream& in, Edition& E)
{
	E.readFrom(in);
	return in;
}