#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Book
{
	string author;
	string title;
	double price;

	Book() : author("No author"), title("No title"), price(0.0) {}
	Book(string auth, string ttl, double prc) : author(auth), title(ttl), price(prc) {}
	Book(const Book& B) : author(B.author), title(B.title), price(B.price) {}
	~Book() {}
};

istream& operator>>(istream& in, Book& B);
ostream& operator<<(ostream& out, const Book& B);
bool operator<(const Book& B1, const Book& B2);

bool comparePrices(const Book& B1, const Book& B2);
bool compareAuthors(const Book& B1, const Book& B2);
bool compareTitles(const Book& B1, const Book& B2);
