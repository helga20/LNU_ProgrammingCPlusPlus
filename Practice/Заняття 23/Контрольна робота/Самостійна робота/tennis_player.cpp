#include "tennis_player.h"
#include <iostream>
using namespace std;

TennisPlayer::TennisPlayer()
	: Sportsman(), income(0.0), rating(0)
{}

TennisPlayer::TennisPlayer(const std::string& snm, double icm, int rtng)
	: Sportsman(snm), income(icm), rating (rtng)
{}

TennisPlayer::TennisPlayer(const TennisPlayer& T)
	: Sportsman(T), income(T.income), rating(T.rating)
{}

TennisPlayer::~TennisPlayer()
{}

void TennisPlayer::printSportsmanInfo() const
{
	cout << "Tennis Player Info\n";
	Sportsman::printSportsmanInfo();
	cout << "Income: " << income << "\nRating: " << rating << "\n";
}

double TennisPlayer::incomeInfo() const 
{
	if (rating <= 10)
	{
		return income *1.15;
	}
	else
	{
		return income;
	}
}

void TennisPlayer::setRating(int rtng)
{
	if (rtng <= 0)
	{
		cout << "Error! Rating cannot be negative\n";
	}
	else
	{
		rating = rtng;
	}
}

void TennisPlayer::readFrom(std::istream& in)
{
	Sportsman::readFrom(in);
	in >> income >> rating;
}

void TennisPlayer::writeTo(std::ostream& out) const
{
	Sportsman::writeTo(out);
	out << ' ' << income << ' ' << rating;
}

