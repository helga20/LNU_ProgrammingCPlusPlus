#include "Header.h"
#include <cmath>

double Dist(Point A, Point B)
{
	return std::sqrt(std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2));
}

ostream& operator<<(ostream& os, const Point& P)
{
	os << '(' << P.x << ',' << P.y << ')';
	return os;
}