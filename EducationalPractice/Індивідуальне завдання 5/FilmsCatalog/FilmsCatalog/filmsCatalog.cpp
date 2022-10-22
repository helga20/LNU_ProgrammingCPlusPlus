#include <iostream>
#include "list.h"
#include "film.h"
#include "filmsCatalog.h"
#include <fstream>
using namespace std;

FilmsCatalog::FilmsCatalog()
	: country(), film_list()
{}

FilmsCatalog::FilmsCatalog(const std::string& cntry)
	: country(cntry)
{}

FilmsCatalog::~FilmsCatalog()
{}

void FilmsCatalog::addFilm(const Film& F)
{
	if (film_list.isEmpty())
	{
		film_list.push_front(F);
		return;
	}

	if (film_list.Back().getPrice() < F.getPrice())
	{
		film_list.push_front(F);
	}
	else
	{
		film_list.push_back(F);
	}
}

void FilmsCatalog::printFilmsCatalogInfo() const
{
	cout << "\nКраїна: " << country;
	cout << "\nКаталог фільмів: \n";
	film_list.printList();
	cout << "\n********************\n\n";
}

void FilmsCatalog::readFromFile(const std::string& fileName)
{
	ifstream iFile(fileName);
	iFile >> country;
	int count;	iFile >> count;
	for (int i = 0; i < count; ++i)
	{
		Film flm;
		iFile >> flm;
		addFilm(flm);
	}
	iFile.close();
}

double FilmsCatalog::totalPrice()
{
	double total = 0.0;
	while (film_list.isEmpty() == false)
	{
		total = total + film_list.Back().getPrice();
		film_list.pop_back();
	}
	cout << "\nЗагальна вартість: " << total << endl;
	return total;
}

double FilmsCatalog::averagePrice()
{
	if (film_list.isEmpty() == true)
	{
		return 0.0;
	}

	double average = 0.0;
	while (film_list.isEmpty() == false)
	{
		average = totalPrice() / film_list.getLength();
	}
	return average;
}

//const Film& FilmsCatalog::getFilmWithMaxPrice() const
//{
//	мені тут незрозумілі символи виводило
//}

