#pragma once

// ���������� ������ �'����� ������� ������� �����
double ptrt(double);
double Ptrt(double);

// ���� ������ ���� ������� ������ ���������:
// ���������-��������
void swapV(int a, int b);

// ��������� ���������
void swapP(int* a, int* b);

// ��������� ���������
void swapR(int& a, int& b);

// ����'�������� ����������� �������
void solve(double a, double b, double c, bool& success, double& x1, double& x2);

struct sqRoots
{
	bool success;
	double x1;
	double x2;
	sqRoots(bool s, double u = 0.0, double v = 0.0)
	{
		success = s;  x1 = u; x2 = v;
	}
};

sqRoots Solve(double a, double b, double c);