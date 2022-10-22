#include "functions.h"
#include <iostream>
using namespace std;

double funcX(double x) {
	if (x < -2) {
		return -2;
	}
	else if (x > 1) {
		return x * x;
	}
	else {
		return x;
	}
}

int createMatrix(int** matrix, int n) {
	int i = 0;
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; ++j)
		{
			if (i < j)
			{
				matrix[i][j] = 0;
			}
			else
			{
				matrix[i][j] = n - i + j;
			}
		}
	}

	return matrix[i][j];
}

void writeMatrix(int** matrix, int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int createMXC(int mxC[5][6]) {

	int i = 0;
	int j = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			mxC[i][j] = rand() % 20 - 10;
		}
	}

	return mxC[i][j];
}
void writeMXC(int mxC[5][6]) {
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << mxC[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int vectorA(int arr[5],int mxC[5][6]) {
	for (int i = 0; i < 5; ++i)
	{
		int max = mxC[i][0];
		for (int j = 1; j < 6; ++j)
		{
			if (mxC[i][j] > max) 
			{
				max = mxC[i][j];
			}
		}
	 arr[i] = max;
	}
	return arr[5];
}
void printVectorA(int arr[5]) {
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int indexOFmin(int arr[5]) {
	int min = arr[0];
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
