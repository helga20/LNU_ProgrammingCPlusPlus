#pragma once
#include <iostream>
#include "car.h"
using namespace std;

void printFunction(int elem)
{
	cout << elem << ' ';
}

struct PrintStruct
{
	void operator() (int elem)
	{
		cout << elem << ' ';
	}
};

void printCar(const Car& car)
{
	cout << car << '\n';
}

class CarPrinterClass
{
public:
	void operator() (const Car& car)
	{
		car.print();
	}
};

void duplicateFucntion(int& elem)
{
	elem *= 2;
}

struct Modifier
{
	int m_coef;

	Modifier(int coef) : m_coef(coef) {};
	void setCoef(int coef) { m_coef = coef; }

	void operator() (int& elem)
	{
		elem += m_coef;
	}
};

bool carPriceGreater350(const Car& car)
{
	return car.getPrice() > 350000;
}

struct GreaterThen
{
	int m_boundary;

	GreaterThen(int boundary) : m_boundary(boundary){}
	bool operator() (int val)
	{
		return val > m_boundary;
	}
};

bool compareCarsByModel(const Car& carLeft, const Car& carRight)
{
	return carLeft.getModel() < carRight.getModel();
}