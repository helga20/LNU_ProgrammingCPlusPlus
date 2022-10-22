#include "calcProcedures.h"

double dychotom(func f, double a, double b, double eps)
// ���������� ��������� ������ ������쳿
{
	double fa = f(a);
	while (b - a > eps)
	{
		double c = (a + b)*0.5; // �������� �������
		double fc = f(c);
		if (fa*fc < 0) b = c;   // ����� � � ��� ������� �������
		else                    // ����� � ��������
		{
			a = c; fa = fc;
		}
	}
	return (a + b)*0.5;
}

double dychotomRec(func f, double a, double b, double eps)
// ���������� ��������� ������ ������쳿
{
	double c = (a + b)*0.5;
	if (b - a <= eps)     // ������� ��������� �����
		return c;
	if (f(a)*f(c) < 0)    // ������ ����� �� ��� �������
		return dychotomRec(f, a, c, eps);
	else                  // ������ ����� �� ����� �������
		return dychotomRec(f, c, b, eps);
}

double leftRect(double a, double b, func f, double eps)
// �������� �� f �� ������� [a;b] ������� ���� ������������
// p - �������� I(2n); q - �������� I(n); s - ���������������
// ��� ��������� ����������� ���� ������� f(i)
// ��������� �� ����� 12 ������� ���� ������������
{
	int n = 10;
	double h = (b - a) / n;
	double s = 0.;
	for (int i = 0; i < n; ++i) s += f(a + i*h);
	double p = s*h;  // ����� �������� ���������
	double q = 0.;   // �������� ��������
	int k = 0;       // ������� ������� ����� ������������
	while (abs(p - q) / 3.>eps && k < 13)
	{
		++k; q = p;            // ���������� �������� I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			s += f(a2 + i*h);  // ��������� ����
		p = s * h2;            // �������� ���� �������� I(2n)
		h = h2; n += n;        // ������� ������� �������
	}
	if (k > 12) cout << "leftRec::WARNING: Accuracy loss is possible\n";
	return p;
}