#include "functionsArrays.h"
#include <iostream>
#include <cmath>
using namespace std;
void readArray(int* arr, int n)
{
	cout << "Enter array of " << n << " integers\n";
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

int prodArray(const int* arr, int n)
{
	int prod = 1;
	for (int i = 0; i < n; ++i)
	{
		prod *= arr[i];
	}
	return prod;
}

int maxElement(const int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
