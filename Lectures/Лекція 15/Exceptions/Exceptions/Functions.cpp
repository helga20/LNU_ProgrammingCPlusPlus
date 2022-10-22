#include "Functions.h"
#include <iostream>
//#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <exception>

using namespace std;

//����� ����� �� ���������� �� ���������� �������, ���� �� a � b �������
double arithmetic(double a, double b)
{
	return (a + b)*0.5;
}

//�������� - ����� � ��'������: �������, ������� �������
double geometric(double a, double b) throw(const char*)
{
	if (a<0 || b<0)
		throw "���������� ��������� ��� geometric: 'a<0 | b<0'";
	return sqrt(a*b);
}

//�������� - ������ �� ����: �������, ����� �����������, ������� ��������
double harmonic_1(double a, double b)
{
	if (a == -b)
	{
		cout << "���������� ��������� ��� harmonic_1\n";
		abort();
	}
	return 2.0*a*b / (a + b);
}
//�������� - ������ �� ����: �������, �������� �����������-�������
bool harmonic_2(double a, double b, double * c)
{
	if (a == -b)
	{
		*c = DBL_MAX; return false;
	}
	else
	{
		*c = 2.0*a*b / (a + b); return true;
	}
}
//�������� - ������ �� ����: �������, ������� �������
double harmonic_3(double a, double b) throw(const char*)
{
	if (a == -b)
		throw "���������� ��������� ��� harmonic_3: 'a = -b'";
	return 2.0*a*b / (a + b);
}
// ������� �� ��������, �������� ������ ���������
double harmonic_4(double a, double b) throw(DivByZero, ZeroArg)
{
	if (a == 0 || b == 0) throw ZeroArg();
	if (a == -b) throw DivByZero();
	return 2.0*a*b / (a + b);
}
//�������� - ������ �� ����: �������, ������� ����������� �������
double harmonic_5(double a, double b)
{
	if (a == -b)
		throw invalid_argument("���������� ��������� ��� harmonic: 'a = -b'");
	return 2.0*a*b / (a + b);
}