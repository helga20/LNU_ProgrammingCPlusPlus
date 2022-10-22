#include "book.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& in, Book& B)
{
	in >> B.author >> B.title >> B.price;
	return in;
}

ostream& operator<<(ostream& out, const Book& B)
{
	out << B.author << ' ' << B.title << ' ' << B.price;
	return out;
}

bool operator<(const Book& B1, const Book& B2)
{
	return B1.price < B2.price;
}

bool comparePrices(const Book& B1, const Book& B2)
{
	return B1.price < B2.price;
}

bool compareAuthors(const Book& B1, const Book& B2)
{
	return B1.author < B2.author;
}

bool compareTitles(const Book& B1, const Book& B2)
{
	return B1.title < B2.title;
}
