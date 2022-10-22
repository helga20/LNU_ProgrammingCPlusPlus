#include <iostream>
#include "film.h"
using namespace std;

Film::Film()
	: title("no title"), surname("no surname"), price(0.0)
{}

Film::Film(const std::string& ttl, const std::string& srnm, double prc)
	: title(ttl), surname(srnm), price(prc)
{}

Film::Film(const Film& F)
	: title(F.title), surname(F.surname), price(F.price)
{}

Film::~Film()
{}

const std::string& Film::getTitle()
{
	return title;
}

const std::string& Film::getSurname()
{
	return surname;
}

double Film::getPrice() const
{
	return price;
}

void Film::printFilmInfo() const
{
	cout << "�����: " << title << ". �������: " << surname << ". ������� ���: " << price << " ���.���.\n";
}

void Film::readFilm()
{
	cout << "������ ���������� ��� �����:\n";
	cout << "�����: "; cin >> title;
	cout << "�������: "; cin >> surname;
	cout << "������� ���: "; cin >> price;
}

void Film::readFrom(std::istream& in)
{
	in >> title >> surname >> price;
}

void Film::writeTo(std::ostream& out) const
{
	out << title << " " << surname << " " << price;
}

std::istream& operator>>(std::istream& in, Film& F)
{
	F.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Film& F)
{
	F.writeTo(out);
	return out;
}



