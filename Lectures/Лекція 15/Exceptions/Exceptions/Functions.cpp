#include "Functions.h"
#include <iostream>
//#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <exception>

using namespace std;

//майже ніколи не призводить до виникнення проблем, хіба що a і b завеликі
double arithmetic(double a, double b)
{
	return (a + b)*0.5;
}

//проблема - корінь з від'ємного: розпізнає, запускає виняток
double geometric(double a, double b) throw(const char*)
{
	if (a<0 || b<0)
		throw "Недопустимі аргументи для geometric: 'a<0 | b<0'";
	return sqrt(a*b);
}

//проблема - ділення на нуль: розпізнає, друкує повідомлення, завершує програму
double harmonic_1(double a, double b)
{
	if (a == -b)
	{
		cout << "Недопустимі аргументи для harmonic_1\n";
		abort();
	}
	return 2.0*a*b / (a + b);
}
//проблема - ділення на нуль: розпізнає, сигналізує результатом-ознакою
bool harmonic_2(double a, double b, double * c)
{
	if (a == -b)
	{
		*c = DBL_MAX; return false;
	}
	else
	{
		*c = 2.0*a*b / (a + b); return true;
	}
}
//проблема - ділення на нуль: розпізнає, запускає виняток
double harmonic_3(double a, double b) throw(const char*)
{
	if (a == -b)
		throw "Недопустимі аргументи для harmonic_3: 'a = -b'";
	return 2.0*a*b / (a + b);
}
// розпізнає дві проблеми, сигналізує різними винятками
double harmonic_4(double a, double b) throw(DivByZero, ZeroArg)
{
	if (a == 0 || b == 0) throw ZeroArg();
	if (a == -b) throw DivByZero();
	return 2.0*a*b / (a + b);
}
//проблема - ділення на нуль: розпізнає, запускає стандартний виняток
double harmonic_5(double a, double b)
{
	if (a == -b)
		throw invalid_argument("Недопустимі аргументи для harmonic: 'a = -b'");
	return 2.0*a*b / (a + b);
}