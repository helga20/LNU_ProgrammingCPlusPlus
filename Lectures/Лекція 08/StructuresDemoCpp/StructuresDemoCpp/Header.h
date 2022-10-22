#pragma once
#include <iostream>

using std::ostream;

struct Point
{
	double x;
	double y;
	// конструктори
	Point()   // за замовчуванн€м
	{
		x = 0; y = 0;
	}
	Point(double a, double b)  // з параметрами
	{
		x = a; y = b;
	}
};

double Dist(Point A, Point B);

ostream& operator<<(ostream& os, const Point& P);