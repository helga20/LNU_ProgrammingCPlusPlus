#include "functions.h"

double sum(double a, double b)
{
	double mySum = a + b;
	return mySum;
}

double sum1(double a, double b)
{
	return a + b;
}

double min(double a, double b)
{
	double minAB = a;
	if (b < a)
	{
		minAB = b;
	}
	return minAB;
}

double max(double a, double b)
{
	if (a >= b)
	{
		return a;
	}

	return b;
}

double max1(double a, double b)
{
	// ()?():()
	return (a >= b) ? a : b;
}

double perimOfRectangle(double a, double b)
{
	double perim = (a + b) * 2.0;
	return perim;
}

double squareOfRectangle(double a, double b)
{
	double square = a * b;
	return square;
}

void multFive(int& a)
{
	a *= 5;
	cout << "multFive: " << a << "\n";
}

void swapValues(double& a, double& b)
{
	double c = a;
	a = b;
	b = c;
}