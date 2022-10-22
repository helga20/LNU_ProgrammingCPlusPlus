#include "book.h"
using namespace std;

Book::Book()
	: author(""), title(""), price(0.0)
{}

Book::Book(const std::string& auth, const std::string& ttl, double prc)
	: author(auth), title(ttl), price(prc)
{}

Book::Book(const Book& B)
	: author(B.author), title(B.title), price(B.price)
{}

Book::~Book()
{}

void Book::print() const
{
	cout << "Book: " << title << ". Author: " << author << ". " << price << " uah\n";
}

double Book::getPrice() const
{
	return price;
}

bool Book::operator< (const Book& B) const
{
	return price < B.getPrice();
}