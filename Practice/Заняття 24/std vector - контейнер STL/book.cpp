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

const std::string& Book::getAuthor() const
{
	return author;
}

bool Book::operator< (const Book& B) const
{
	return price < B.getPrice();
}

void Book::setDiscount(int discount)
{
	double discountValue = price * (double)discount / 100.0;
	price -= discountValue;
}

void Book::readFrom(std::istream& in)
{
	in >> author >> title >> price;
}

void Book::writeTo(std::ostream& out) const
{
	out << author << ' ' << title << ' ' << price;
}

std::istream& operator>>(std::istream& in, Book& B)
{
	B.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Book& B)
{
	B.writeTo(out);
	return out;
}