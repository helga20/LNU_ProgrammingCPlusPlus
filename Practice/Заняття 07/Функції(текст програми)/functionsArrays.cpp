#include "functionsArrays.h"
#include <iostream>
#include <cmath>
using namespace std;

void readStaticArray10(int(&arr)[10])
{
	cout << "Enter array of 10 integers\n";
	for (int i = 0; i < 10; ++i)
	{
		cout << i << ": ";
		cin >> arr[i];
	}
	cout << "Done.\n";
}

void printStaticArray10(int(&arr)[10])
{
	cout << "Array of 10 integers\n";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

void readArray(int* arr, int n)
{
	cout << "Enter array of " << n <<" integers\n";
	for (int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		cin >> arr[i];
	}
	cout << "Done.\n";
}

void printArray(const int* arr, int n)
{
	cout << "Array of " << n << " integers\n";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

int sumArray(const int* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

int minElement(const int* arr, int n)
{
	int min = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

double calculateP(double(&a)[7], double y)
{
	// p(y) = a[0]*y^0 + a[1]*y^1 + ... + a[6]*y^6;
	double p = a[0];
	double yPow = 1.0;
	for (int i = 1; i < 7; ++i)
	{
		yPow *= y;
		p += a[i] * yPow;
	}
	return p;
}

void task11(double(&a)[7])
{
	cout << "Task 11\n";
	double x = 1.0;
	double p_x = calculateP(a, x + 1) - calculateP(a, x);
	cout << "x = " << x << ", p_x = " << p_x << "\n";
	x = 3.0;
	p_x = calculateP(a, x + 1) - calculateP(a, x);
	cout << "x = " << x << ", p_x = " << p_x << "\n";
	x = 4.0;
	p_x = calculateP(a, x + 1) - calculateP(a, x);
	cout << "x = " << x << ", p_x = " << p_x << "\n\n";
}

double task12(double(&a)[7], double s, double t)
{
	// p(1) - p(t) + p(s-t)^2 - p(1)^3
	double p_1 = calculateP(a, 1.0);
	double p_t = calculateP(a, t);
	double p_st = calculateP(a, s - t);
	double result = p_1 - p_t + p_st * p_st - pow(p_1, 3.0);
	return result;
}