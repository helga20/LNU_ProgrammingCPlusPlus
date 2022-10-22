#pragma once
#include <string>
#include <iostream>
#include "list.h"
#include "film.h"

class FilmsCatalog
{
private:
	std::string country;
	List<Film> film_list;

public:
	FilmsCatalog();
	FilmsCatalog(const std::string& cntry);
	~FilmsCatalog();

	void addFilm(const Film& F);
	void printFilmsCatalogInfo() const;
	void readFromFile(const std::string& fileName);
	double totalPrice();
	double averagePrice();
	//const Film& getFilmWithMaxPrice() const;
};
