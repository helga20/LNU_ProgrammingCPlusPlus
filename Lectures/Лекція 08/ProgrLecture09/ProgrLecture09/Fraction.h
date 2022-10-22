#pragma once
#include <iostream>
using std::ostream;

// Раціональне число
struct Fraction
{
	int nom;      // чисельник - ціле число
	unsigned den; // знаменник - натуральне
	Fraction() :nom(0), den(1) {} // конструктор за замовчуванням
	Fraction(int a, unsigned b);  // конструктор з параметрами
};

ostream& operator<<(ostream& os, const Fraction& q);

void Simplify(Fraction&);
void ReadFraction(Fraction&);
void PrintFraction(const Fraction&);
Fraction Add(const Fraction&, const Fraction&);
Fraction Mult(const Fraction&, const Fraction&);