#include "calcProcedures.h"

// �������� ����
double t;
double X;

// ��������� ����������� �������
double funParam(double x)
{   // ��� ���������, ��������� �� ��������� t
	return pow(x * t, 2) + 1;
}
// ��� ��������� ���������
double twoArg(double y)
{
	return pow(X + 2.*y, 2);
}
double firstInt(double x)
//�������, �� �������� �������� �������� � ����������
{
	X = x;  // ����������� ����� ����� ����� ���������
	return leftRect(0., x, twoArg, 0.0001);
}

void numIntegration()
{
	cout << "\n *���������� ��������� ������� ���� ������������*\n\n";
	// ��������� ����������� ��������
	cout << "Integral(sin,0,Pi) = " << leftRect(0., M_PI, sin) << '\n';
	// � ����� - ���� S(t)
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i*0.5;
		cout << "  " << t << '\t' << leftRect(-1., 1., funParam, 1e-5) << '\n';
	}
	// � ������ - ��������
	cout << "\n �������� �������� ��������� �������� �������������\n";
	cout << "Double integral = " << leftRect(0., 1., firstInt, 0.0001) << '\n';
	return;
}