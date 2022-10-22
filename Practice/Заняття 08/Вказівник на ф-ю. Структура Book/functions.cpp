#include "functions.h"
#include <iostream>
using namespace std;

void sayHi()
{
	cout << "Hello!\n";
}

void sayBye()
{
	cout << "Good bye!\n";
}

int multTwo(int x)
{
	return x * 2;
}

int addFive(int y)
{
	return y + 5;
}

double sum(double a, double b)
{
	return a + b;
}

double mult(double a, double b)
{
	return a * b;
}

void doActionIntegers(int a, int (*f)(int))
{
	int result = f(a);
	cout << "\nBefore: " << a << ". After: " << result << "\n";
}











void readArray(int* arr, const int n)
{
	cout << "Enter array of " << n << " elements\n";
	for (int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		cin >> arr[i];
	}
}

void printArray(const int* arr, const int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}






void modifyArray(int* arr, const int n, int (*f)(int))
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = f(arr[i]);
	}
}