#pragma once
#include <string>
#include <iostream>

class Film
{
protected:
	std::string title;
	std::string surname;
	double price;

public:
	Film();
	Film(const std::string& ttl, const std::string& srnm, double prc);
	Film(const Film& F);
	~Film();

	void readFilm();

	const std::string& getTitle();
	const std::string& getSurname();
	double getPrice() const;

	void printFilmInfo() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Film& F);
std::ostream& operator<<(std::ostream& out, const Film& F);