#include "stepProcedures.h"
#include <cmath>

void squareNorm()
{
	cout << "\n *������ ����������� ������ ������� ������ �����*\n\n������ ���������� �����: ";
	unsigned n; cin >> n;
	double s = 0.0;
	for (unsigned i = 1; i <= n; ++i)
	{
		cout << "������ " << i << "-� �����: ";
		double a; cin >> a;
		s += a * a;
	}
	s = std::sqrt(s);
	cout << "������ ����������� = " << s / n << '\n';
	return;
}