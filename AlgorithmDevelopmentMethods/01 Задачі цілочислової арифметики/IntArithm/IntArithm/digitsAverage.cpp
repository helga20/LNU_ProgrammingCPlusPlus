#include "intProcedures.h"

void digitsAverage()
{
	cout << "\n *���������� ���������� ������������� ����*\n\n������ ���������� �����: ";
	unsigned n, m; cin >> n; m = n;
	// �������� �������� ���� �� ���������
	unsigned s = 0; unsigned k = 0;
	// ���������� ����� ��������� �����
	while (m > 0)
	{
		unsigned c = m % 10; // �������� ���������� �����
		s += c; ++k;         // ��������� ��
		m /= 10;             // �������� ��
	}
	// ��������� ������ ����������� � ����������� ����
	double average = s; average /= k;
	cout << "n = " << n << "   average = " << average << '\n';
	return;
}