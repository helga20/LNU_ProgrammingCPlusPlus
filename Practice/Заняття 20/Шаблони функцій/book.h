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

	bool operator< (const Book& B) const;
};
