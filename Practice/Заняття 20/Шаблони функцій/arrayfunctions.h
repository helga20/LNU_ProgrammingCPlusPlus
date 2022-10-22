#pragma once
#include <iostream>
using namespace std;

// Array: 1 2 3 4 5
// Array: 1.1 2.2 3.3 4.4 5.5
// Array: a b c d e

template <typename TNum>
void printArray_1(TNum arr[], int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

template <typename TNum, int n>
void printArray_2(TNum arr[])
{
	cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

template <typename TNum, int n>
void printArray_3(TNum (&arr)[n])
{
	cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

template <typename TNum>
void printDynamicArray(TNum* arr, int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

template <typename TClass, int n>
void printBucket(TClass(&arr)[n])
{
	cout << "Your bucket:\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i].print();
	}
	cout << "--------------------------------\n\n";
}

template <typename TClass>
void printBucketDynamic(TClass *arr, int n)
{
	cout << "Your bucket:\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i].print();
	}
	cout << "--------------------------------\n\n";
}

template <typename TNum, int n>
TNum sumArray(TNum(&arr)[n])
{
	TNum totalSum = arr[0];
	for (int i = 1; i < n; ++i)
	{
		totalSum += arr[i];
	}
	return totalSum;
}

template <typename TClass>
double sumBucket(TClass* arr, int n)
{
	double totalSum = arr[0].getPrice();
	for (int i = 1; i < n; ++i)
	{
		totalSum += arr[i].getPrice();
	}
	return totalSum;
}

template <typename TNum, int n>
TNum minNumberInArray(TNum(&arr)[n])
{
	TNum minNumber = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < minNumber)
		{
			minNumber = arr[i];
		}
	}
	return minNumber;
}

template <typename TClass>
int minElement(TClass* arr, int n)
{
	int minIndex = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < arr[minIndex])  //(arr[i].getPrice() < arr[minIndex].getPrice())
		{
			minIndex = i;
		}
	}
	return minIndex;
}