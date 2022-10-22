////Завдання 3
//#include "functions 3,4,5,6.h"
//#include <iostream>
//using namespace std;
//void printInfo(int day, int month, int year)
//{
//	cout << "Enter day: "; cin >> day;
//	cout << "Enter month: "; cin >> month;
//	cout << "Enter year: "; cin >> year;
//
//	if (day < 0)
//	{
//		cout << "Sorry, " << day << " is wrong!\n"; return;
//
//	}
//	if (month < 0)
//	{
//		cout << "Sorry, " << month << " is wrong!\n"; return;
//	}
//	if (year < 0)
//	{
//		cout << "Sorry, " << year << " is wrong!\n"; return;
//	}
//
//	cout << "Day: " << day << "\n";
//	cout << "Month: " << month << "\n";
//	cout << "Year: " << year << "\n";
//}


#include "functions 3,4,5,6.h"
#include <cmath>

double difference(double a, double b)
{
	double mydifference = a - b;
	return mydifference;
}
double difference1(double a, double b)
{
	return a - b;
}
double product(double a, double b)
{
	double myproduct = a * b;
	return myproduct;
}
double product1(double a, double b)
{
	return a * b;
}
double perimOfSquare(double a)
{
	double perim = 4 * a;
	return perim;
}
double squareOfSquare(double a)
{
	double square = a * a;
	return square;
}
double perimOfTrianglee(double a, double b, double c)
{
	double perim = a + b + c;
	return perim;
}
double squareOfTriangle(double a, double b, double c)
{
	double perim = a + b + c;
	double p0 = perim / 2;
	double square = sqrt(p0 * (p0 - a) * (p0 - b) * (p0 - c));
	return square;
}
double squareOfCircle(double a)
{
	const float pi = 3.14;
	double square = a * a * pi;
	return square;
}

double squareOfPentagon(double a, double b, double c, double d, const double e)
{
	const double m = 2.5, h = 2;
	double perim1 = a + e + h;
	double p1 = perim1 / 2;
	double square1 = sqrt(p1 * (p1 - a) * (p1 - h) * (p1 - e));
	double perim2 = h + m + d;
	double p2 = perim2 / 2;
	double square2 = sqrt(p2 * (p2 - d) * (p2 - h) * (p2 - m));
	double perim3 = m + b + c;
	double p3 = perim3 / 2;
	double square3 = sqrt(p3 * (p3 - b) * (p3 - c) * (p3 - m));
	double square = square1 + square2 + square3;
	return square;
}
