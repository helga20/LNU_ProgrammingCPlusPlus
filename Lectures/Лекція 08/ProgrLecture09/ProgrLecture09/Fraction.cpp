#include "Fraction.h"

using std::cin;
using std::cout;

Fraction::Fraction(int a, unsigned b)
{
	if (b == 0)
	{
		nom = INT_MAX;
		den = 1;
		cout << "WARNING: Fraction constructor: denominator = 0 - corrected to 1\n"
			<< " the fraction is " << nom << '/' << den << '\n';
	}
	else
	{
		nom = a; den = b;
		Simplify(*this);
	}
}

void Simplify(Fraction& f)
{
	if (f.nom == 0) return;
	int a = abs(f.nom);
	int b = f.den;
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	f.nom /= a;
	f.den /= a;
}
void ReadFraction(Fraction& f)
{
	int a, b;
	cin >> a >> b;
	f = (b < 0) ? Fraction(-a, -b) : Fraction(a, b);
}
void PrintFraction(const Fraction& f)
{
	cout << f.nom << '/' << f.den;
}
Fraction Add(const Fraction& a, const Fraction& b)
{
	return Fraction(a.nom*b.den + b.nom*a.den, a.den*b.den);
}
Fraction Mult(const Fraction& a, const Fraction& b)
{
	return Fraction(a.nom*b.nom, a.den*b.den);
}

ostream& operator<<(ostream& os, const Fraction& q)
{
	os << q.nom << '/' << q.den;
	return os;
}