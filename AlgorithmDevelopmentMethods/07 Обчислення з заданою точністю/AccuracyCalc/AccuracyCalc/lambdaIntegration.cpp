#include "calcProcedures.h"

void lambdaIntegration()
{
	cout << "\n *���������� ��������� � ������������� ������-������*\n\n";
	// ��������� ����������� ��������
	cout << "Integral(sin,0,Pi) = " << leftRect(0., M_PI, sin) << '\n';
	// � ����� - ���� S(t)
	static double t;           // �������� ������������ �������
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i*0.5;
		cout << "  " << t << '\t' << leftRect(-1., 1., [](double x) {return pow(x * t, 2) + 1; }, 1e-5) << '\n';
	}
	// � ������ - ��������
	static double X;           // ������ �������� ������������ �������
	cout << "\n �������� �������� ��������� �������� �������������\n";
	double I = leftRect(0., 1., [](double x) { X = x; return leftRect(0., x, [](double y) { return pow(X + 2.*y, 2); }, 0.0001); }, 0.0001);
	cout << "Double integral = " << I << '\n';
	return;
}