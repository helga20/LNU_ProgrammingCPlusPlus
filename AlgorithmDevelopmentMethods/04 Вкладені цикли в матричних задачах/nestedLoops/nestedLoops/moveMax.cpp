#include "loopsProcedures.h"
#include <cmath>

void moveMax()
{
	cout << "\n *���������� max-�������� �������������� ����� � �������� �������*\n\n";
	// ��� ��������� ������ ������� ������ � ��� ��������
	const unsigned n = 3;
	const unsigned m = 4;
	int a[n][m];
	// �������� ������ �������
	cout << "������ �������� ������� " << n << 'x' << m << '\n';
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) cin >> a[i][j];
	int b = abs(a[0][0]); // ��������� �������� �������������
	unsigned k = 0;		  // �� ���� ����������
	unsigned l = 0;
	// ����� - ����� � �������
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j)
			if (abs(a[i][j]) > b)  // ������� �����
			{
				b = abs(a[i][j]); // � �����'�����
				k = i; l = j;
			}
	}
	if (k != 0) // ������ ������ �����
		for (unsigned j = 0; j < m; ++j)
		{
			int toSwap = a[0][j];
			a[0][j] = a[k][j];
			a[k][j] = toSwap;
		}
	if (l != 0) // ������ ������ �������
		for (unsigned i = 0; i < n; ++i)
		{
			int toSwap = a[i][0];
			a[i][0] = a[i][l];
			a[i][l] = toSwap;
		}
	// ������� ����������
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j) cout << '\t' << a[i][j];
		cout << '\n';
	}
	return;
}