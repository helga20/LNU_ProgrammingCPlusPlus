#pragma once
#include <iostream>
#include <string>
using namespace std;

void printIntValue(int val)
{
	cout << "Your value: " << val << "\n";
}

void printDoubleValue(double val)
{
	cout << "Your value: " << val << "\n";
}

template <typename TNum>
void printValue(TNum val)
{
	cout << "Your value: " << val << "\n";
}

// TClass should have method print()
template <typename TClass>
void printInfo(const TClass& val)
{
	cout << "\n----------------------------------\n";
	cout << "Your bucket contains:\n";
	val.print();
	cout << "\n----------------------------------\n";
}

template <typename TClass>
void printPriceInfo(const TClass& val, const std::string& currency)
{
	cout << "Order price: " << val.getPrice() << " " << currency << "\n";
}

template <typename TNum>
double averageVal(TNum a1, TNum a2)
{
	double res = (double)(a1 + a2) / 2.0;
	return res;
}

template <typename TNum>
TNum applyCoef(TNum val, int coef)
{
	return val * coef;
}

template <typename TNum, typename TCoef>
void printSaleResult(TNum val, TCoef coef)
{
	cout << "Before: " << val << " ";
	cout << "After: " << val * coef << "\n";
}
