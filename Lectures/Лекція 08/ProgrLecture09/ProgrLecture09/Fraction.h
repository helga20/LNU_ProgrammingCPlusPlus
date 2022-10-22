#pragma once
#include <iostream>
using std::ostream;

// ����������� �����
struct Fraction
{
	int nom;      // ��������� - ���� �����
	unsigned den; // ��������� - ����������
	Fraction() :nom(0), den(1) {} // ����������� �� �������������
	Fraction(int a, unsigned b);  // ����������� � �����������
};

ostream& operator<<(ostream& os, const Fraction& q);

void Simplify(Fraction&);
void ReadFraction(Fraction&);
void PrintFraction(const Fraction&);
Fraction Add(const Fraction&, const Fraction&);
Fraction Mult(const Fraction&, const Fraction&);