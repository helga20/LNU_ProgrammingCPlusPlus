#include "iterProcedures.h"

void countProper()
{
	cout << "\n *���������� ������� \"����������\" ����� �����������*\n\n";
	unsigned n;
	cout << "������ ������� �����: "; cin >> n;
	long long p = 1; // ������ �����
	long long f = 1; // ��������
	unsigned k = 0;  // ��������
	for (unsigned i = 1; i <= n; ++i)
	{
		cout << "������ " << i << "-e ����o: ";
		double a; cin >> a;
		p *= 2; f *= i;
		if (p < a && a < f+3) ++k;
	}
	cout << "k = " << k << '\n';
	return;
}