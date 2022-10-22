#pragma once

//typedef double (*func)(double);
using func = double(*)(double);
typedef void(*proc)(void);

// �������� ������� ������� �������
void Tabulate(func f, double a, double b, double h);

// ���������� ��������� ������ ����� ������ �����
double bisection(func f, double a, double b, double eps = 1e-8);

// ���������, �� ��������� ����� "������" ������ ��������
void CalculateRoots();
void Integrate();
void DeelWithArray();