#include <iostream>
#include <cmath>
#include "functions 13.h"
using namespace std;

double task13y(double y) 
{ 
	return (pow(y, 2.) + 1) * pow(cos(y),2.);
}

void task13(double a, double h, int n)
{
	cout << "Task 13\n";
	double result = 0;

	for (int i = 0; i <= n; i++)
	{
		result += task13y(a + (2 * (double)n * h));
	}
	cout << "f(a) = " << result << endl;

	return;
}