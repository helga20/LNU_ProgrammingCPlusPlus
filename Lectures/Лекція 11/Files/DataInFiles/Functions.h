#pragma once
#include <iostream>

// ���������� ���� ������� ��� ����, ��� ������� ������ ���� ���� �����
using num_type = double;

// ����������� �������� ������ � ������
void ReadArrayFromStream(num_type* a, size_t n, std::istream& is);
// ���������� ���������� ������� �������
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n);
// ��������� ������ �� �������
void WriteArray(num_type* a, size_t n);

using func = double(*)(double);
typedef void(*proc)(void);

// �������� ������� ������� �������
void TabulateToStream(std::ostream& os, func f, double a, double b, double h);