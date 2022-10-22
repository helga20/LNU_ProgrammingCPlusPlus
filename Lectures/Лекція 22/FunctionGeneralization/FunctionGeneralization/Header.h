#pragma once
#include <iostream>
#include <complex>

// �������� ����������, ���������� �� ������� ���������
// ������� ����� � ��������� ����������
double value(double x, double a[], int n)
{
	// ���������� �������� ������� �� ������ �������
	double P = a[0];
	for (int i = 1; i < n; ++i) P = P * x + a[i];
	return P;
}

// �������� ����������, ���������� ����� �� ���� �����
template <typename TNum>
TNum Value(TNum x, TNum a[], int n)
{
	TNum P = a[0];
	for (int i = 1; i < n; ++i) P = P * x + a[i];
	return P;
}

// �������� ���������� ��������� �������
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
// ������������ ��� ������� � ������������ �������������
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