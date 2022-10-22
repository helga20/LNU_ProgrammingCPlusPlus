#include "stepProcedures.h"
#define _USE_MATH_DEFINES   // �������� ���������� ������������ ��������,
#include <math.h>           // ���������� ����������� ������������ �������
#include <iomanip>          // �� ����������� ��������� ���������

using std::setw;
using std::setprecision;

void table()
{
	cout << "\n *������� ������� ���������������� ������� �� ������� [0;Pi]*\n\n";
	const int n = 12;
	// ������� ����� �������
	cout << "  x     sin x    cos x\n------------------------\n";
	double h = M_PI / n; // ���� ���� ��������� ������ ���������� ���� ���
	for ( int i = 0; i <= n; ++i) // ���������� � ������� ����� �������
	{
		double x = h * i;
		double s = sin(x);
		double c = cos(x);
		cout << std::showpoint << std::fixed
			<< setw(5) << setprecision(2) << x
			<< setw(9) << setprecision(5) << s
			<< setw(9) << setprecision(5) << c << '\n';
	}
	return;
}