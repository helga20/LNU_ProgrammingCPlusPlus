#include "intProcedures.h"

void isPolyndrome()
{
	cout << "\n *��������: �� ��������?*\n\n������ ���������� �����: ";
	unsigned n; cin >> n;
	// ��������� �������� ������ ����� �� ���� n
	unsigned s = 0; unsigned m = n;
	// ���������� ����� ��������� �����
	while (m > 0)
	{
		unsigned c = m % 10; // �������� ���������� �����
		s = s*10 + c;        // ��������� ��
		m /= 10;             // � �������� ��
	}
	if (s == n) cout << n << "- ��������\n";
	else cout << n << "- �� ��������\n";
	return;
}