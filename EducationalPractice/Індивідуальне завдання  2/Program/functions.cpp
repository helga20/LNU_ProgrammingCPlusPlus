#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std;
void function(double* a, int n, double x)
{
	    unsigned long long f = 1ULL;
	    for (int i = 0; i <= n; ++i) 
		f *= (i + 1);

		for (int i = 0; i < n-1; ++i)
		{
			a[i] = (1 / f) + (i * (sqrt(abs(x))));
		}
		cout << "Your array: ";
		for (int i = 0; i < n - 1; ++i)
		{
			cout << "[" << i << "]: " << a[i] << endl;
		}	
}

int sumArray(double* a, int n, double x)
{
	int sum = 0;
	for (int i = 0; i < n-1; ++i)
	{
		sum += a[i];
	}
	return sum;
}
int prodArray(double* a, int n, double x)
{
	int prod = 1;
	for (int i = 0; i < n-1 ; ++i)
	{
		prod *= a[i];
	}
	return prod;
}