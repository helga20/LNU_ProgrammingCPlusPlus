#define _USE_MATH_DEFINES
#include "Points.h"
#include <cmath>

double Distance(const CPoint& a, const CPoint& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

PPoint CartToPolar(CPoint c)
{
	PPoint answer;
	answer.ro = sqrt(c.x*c.x + c.y*c.y);
	answer.phi = atan2(c.y, c.x) / M_PI * 180;
	return answer;
}

CPoint PolarToCart(PPoint p)
{
	double alpha = p.phi / 180 * M_PI;
	CPoint answer;
	answer.x = p.ro*cos(alpha);
	answer.y = p.ro*sin(alpha);
	return answer;
}
