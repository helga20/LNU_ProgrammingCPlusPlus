#pragma once
#include <string>
#include <iostream>

class Edition
{
private:
	std::string author;
	std::string title;
	double price;
	int nofPages;

public:
	Edition();
	Edition(const std::string& auth, const std::string& ttl, double prc, int n);
	Edition(const Edition& E);
	~Edition();

	void print() const;
	const std::string &getAuthor() const;
	const std::string& getTitle() const;
	double getPrice() const;
	int getPages() const;

	void setAuthor(const std::string auth);
	void setTitle(const std::string ttl);
	void setPrice(double prc);
	void setPages(int n);

	void writeTo(std::ostream& out) const;
	void readFrom(std::istream& in);

	double pagePrice() const;
	bool operator <(const Edition& E) const;

};

std::ostream& operator<<(std::ostream& out, const Edition& E);
std::istream& operator>>(std::istream& in, Edition& E);
