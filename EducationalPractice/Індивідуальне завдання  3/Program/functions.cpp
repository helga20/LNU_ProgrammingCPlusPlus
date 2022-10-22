#include <iostream>
#include "functions.h"
#include <cmath>

using namespace std;

double expression(double a, int b)
{
	double expression = pow(2.7, b) + pow((a + 1), - 5);
	return expression;
}

void matrix(int n)
{
	int** a = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[n];

		for (int j = 0; j < n; ++j)
		{
			if (i + j == n - 1) a[i][j] = i + 1;
			if (i + j > n - 1) a[i][j] = 0;
			if (i + j < n - 1) a[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		delete a[i];
	}
	delete[] a;
}

int crMatrixA(int mtrxA[5][6])
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			mtrxA[i][j] = 1 + rand() % 20 - 10;
		}
	}
	return mtrxA[i][j];
}

void wrMatrixA(int mtrxA[5][6])
{
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << mtrxA[i][j] <<' ';
		}
		cout << endl;
	}
	cout << endl;
}

int vecrorB(int arr[5], int mtrxA[5][6])
{
	for (int i = 0; i < 5; ++i)
	{
		int max = mtrxA[i][0];
		for (int j = 1; j < 6; ++j)
		{
			if (mtrxA[i][j] > max)
			{
				max = mtrxA[i][j];
			}
		}
		arr[i] = max;
	}
	return arr[5];
}
void printvecrorB(int arr[5])
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int indexMin(int arr[5])
{
	int min = arr[1];
	int index = 0;
	for (int i = 1; i < 5; ++i)
	{
		if (min > arr[i])
		{
			index = i;
		}
	}
	return index;
}

