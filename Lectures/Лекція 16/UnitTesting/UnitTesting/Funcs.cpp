#include "Funcs.h"

double harmony(double a, double b)
{
	double inverseA = 1. / a;
	double inverseB = 1. / b;
	double c = 2. / (inverseA + inverseB);
	return c;
}