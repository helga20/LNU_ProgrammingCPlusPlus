#include "stepProcedures.h"

void Fibonacci()
{
	cout << "\n *�������� ����������� ����� Գ�������*\n\n";
	unsigned k;
	cout << "������ ����� (>=2) ���������� �����: "; cin >> k;
	k = (k > 2) ? k : 2;
	long long a;
	long long b = 1; // ������ ������� �����������
	long long c = 1;
	cout << "f(0)=" << b << "\nf(1)=" << c << '\n';
	for (unsigned i = 2; i <= k; ++i)
	{
		a = b; b = c; // �������� b � c "��������"
		c = a + b;    // ��������� ����� ���� �����������
		cout << "f(" << i << ")=" << c << '\n';
	}
	return;
}