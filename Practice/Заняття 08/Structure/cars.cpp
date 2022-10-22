#include "cars.h"
#include <iostream>
using namespace std;

void readCar(Car& C)
{
	cout << "Enter car info\n";
	cout << "Enter brand: "; cin >> C.brand;
	cout << "Enter model: "; cin >> C.model;
	cout << "Enter price: "; cin >> C.price;
}

void printCar(const Car& C)
{
	cout << "Car info\n";
	cout << "Brand: " << C.brand << "\n";
	cout << "Model: " << C.model << "\n";
	cout << "Price: " << C.price << "\n";
}

istream& operator>>(istream& in, Car& C)
{
	in >> C.brand >> C.model >> C.price;
	return in;
}

ostream& operator<<(ostream& out, const Car& C)
{
	out << C.brand << ' ' << C.model << ' ' << C.price;
	return out;
}

bool operator<(const Car& C1, const Car& C2)
{
	return C1.price < C2.price;
}

void printCarArray(Car* arr, const int n)
{
	cout << "Cars array\n";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\n";
	}
	cout << "\n";
}

double totalPrice(Car* arr, const int n)
{
	double totalSum = 0.;
	for (int i = 0; i < n; ++i)
	{
		totalSum += arr[i].price;
	}
	return totalSum;
}

Car mostExpensiveCar(Car* arr, const int n)
{
	Car maxCar = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].price > maxCar.price)
		{
			maxCar = arr[i];
		}
	}
	return maxCar;
}

Car cheapestCar(Car* arr, const int n)
{
	Car minCar = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < minCar)
		{
			minCar = arr[i];
		}
	}
	return minCar;
}

double totalBrandPrice(string brnd, Car* arr, const int n)
{
	double totalSum = 0.;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].brand == brnd)
		{
			totalSum += arr[i].price;
		}
	}
	return totalSum;
}
