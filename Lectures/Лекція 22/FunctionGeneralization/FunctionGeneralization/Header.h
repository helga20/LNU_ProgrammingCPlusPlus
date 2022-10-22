#pragma once
#include <iostream>
#include <complex>

// Алгоритм обчислення, незалежний від способу отримання
// вхідних даних і виведення результатів
double value(double x, double a[], int n)
{
	// обчислення значення полінома за схемою Горнера
	double P = a[0];
	for (int i = 1; i < n; ++i) P = P * x + a[i];
	return P;
}

// Алгоритм обчислення, незалежний також від типу даних
template <typename TNum>
TNum Value(TNum x, TNum a[], int n)
{
	TNum P = a[0];
	for (int i = 1; i < n; ++i) P = P * x + a[i];
	return P;
}

// Алгоритм друкування довільного полінома
template <typename TNum>
void Print(TNum a[], int n)
{
	if (a[0] != 1) std::cout << a[0];
	for (int i = 1; i < n; ++i)
	{
		std::cout << " x^" << n - i << ' ';
		if (a[i] > 0) std::cout << '+';
		std::cout << a[i];
	}
	std::cout << '\n';
}
// Спеціалізація для полінома з комплексними коефіцієнтами
template<>
void Print(std::complex<double> a[], int n)
{
	std::cout << a[0];
	for (int i = 1; i < n; ++i)
	{
		std::cout << " x^" << n - i << " + " << a[i];
	}
	std::cout << '\n';
}