#include <iostream>
#include "ArrProcedures.h"

void ReadArray(Array a)
{
	std::cout << "Input " << N << " values: ";
	for (size_t i = 0; i < N; ++i) std::cin >> a[i];
	std::cin.get();
}
num_type ScalarProduct(Array a, Array b)
{
	num_type s = 0;
	for (size_t i = 0; i < N; ++i) s += a[i] * b[i];
	return s;
}

// ��������� ���������� ������ �������� ������
num_type* CreateArray(size_t n, num_type x)
{
	// ��������� ���'��� ��� ������
	num_type* a = new num_type[n];
	// ������ ��������� ������ ���������� �������
	for (size_t i = 0; i < n; ++i) a[i] = x;
	// ��������� ������� �����. �������� ���'��� �� ����� ������� ����������
	return a;
}
// ����������� �������� ������ � ������
void ReadArray(num_type* a, size_t n)
{
	std::cout << "Input " << n << " values: ";
	for (size_t i = 0; i < n; ++i) std::cin >> a[i];
	std::cin.get();
}
// ��������� ������ �� �������
void WriteArray(const num_type* a, size_t n)
{
	for (size_t i = 0; i < n; ++i) std::cout << '\t' << a[i];
	std::cout << '\n';
}
// ���������� ���������� ������� �������
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n)
{
	num_type s = 0;
	for (size_t i = 0; i < n; ++i) s += a[i] * b[i];
	return s;
}
// ���������� ����� �������
num_type Norm(const num_type* a, size_t n)
{
	return sqrt(ScalarProduct(a, a, n));
}

// ��������� �������� �������� � �����
double maxVal(const double* a, size_t n)
{
	double result = a[0];
	for (size_t i = 1; i < n; ++i)
		if (a[i] > result) result = a[i];
	return result;
}

// ��������� �������� �������� � �������
double maxVal(const double* start, const double* end)
{
	double result = *start++;
	while (start != end)
	{
		if (*start > result) result = *start;
		++start;
	}
	return result;
}

// ��������� ���� ���������� �������� � �������
double* max(double* start, double* end)
{
	double* pos = start;
	while (start != end)
	{
		if (*start > *pos) pos = start;
		++start;
	}
	return pos;
}
