#pragma once
#include <string>
#include <iostream>

class Book
{
private:
	std::string author;
	std::string title;
	double price;

public:
	Book();
	Book(const std::string& auth, const std::string& ttl, double prc);
	Book(const Book& B);
	~Book();

	void print() const;
	double getPrice() const;
	const std::string& getAuthor() const;

	void setDiscount(int discount);
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

	bool operator< (const Book& B) const;
};

std::istream& operator>>(std::istream& in, Book& B);
std::ostream& operator<<(std::ostream& out, const Book& B);