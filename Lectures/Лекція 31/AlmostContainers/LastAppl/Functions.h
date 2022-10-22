#pragma once

#include <complex>
#include <vector>

template <class T>
T maxVal(T* a, size_t n)
{
	T max = a[0];
	for (size_t i = 1; i < n; ++i)
		if (a[i] > max) max = a[i];
	return max;
}

template <class T>
T maxVal(T* a, size_t n, size_t& pos)
{
	pos = 0;
	for (size_t i = 1; i < n; ++i)
		if (a[i] > a[pos]) pos = i;
	return a[pos];
}

template <class T>
struct Element
{
	T value;
	size_t index;
	Element(T v, size_t i) :value(v), index(i) {}
};

template <class T>
Element<T> maxElement(T* a, size_t n)
{
	size_t pos = 0;
	for (size_t i = 1; i < n; ++i)
		if (a[i] > a[pos]) pos = i;
	return Element<T>(a[pos], pos);
}

template <class T>
std::pair<T, size_t> Max(T* a, size_t n)
{
	size_t pos = 0;
	for (size_t i = 1; i < n; ++i)
		if (a[i] > a[pos]) pos = i;
	return pair<T, size_t>(a[pos], pos);
}

typedef std::complex<double> Complex;

std::pair<Complex, Complex> SolveSqrEq(Complex a, Complex b, Complex c);
Complex CalcSqr(Complex a, Complex b, Complex c, Complex x);

void ComplexRoots(Complex C, size_t power, std::vector<Complex>& Roots);
