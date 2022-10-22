#include "loopsProcedures.h"

void saddleElement()
{
	cout << "\n *³�������� �������� �������� �������*\n\n";
	// ��� ��������� ������ ������� ������ � ��� ��������
	const unsigned n = 3;
	const unsigned m = 4;
	int a[n][m];
	// �������� ������ �������
	cout << "������ �������� ������� " << n << 'x' << m << '\n';
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) cin >> a[i][j];
	// ���������� ��������� �������� �������� � ������������ �������
	// ������� ����� ������� - �������� ����!
	int saddle = a[0][0]; // ��������� �������� �������������
	unsigned k = 0;		  // �� ���� ����������
	unsigned l = 0;
	// ����� - ����� � �����
	for (unsigned j = 1; j < m; ++j)
		if (a[k][j] > saddle)  // ������� �����
		{
			saddle = a[k][j]; // � �����'�����
			l = j;
		}
	// ����� ����������� �� ���� ����� �������
	for (unsigned i = 1; i < n; ++i)
	{
		// � �������� ��� ���������� ��������
		int currMax = a[i][0];
		unsigned p = 0;
		for (unsigned j = 1; j < m; ++j)
			if (a[i][j] > currMax)
			{
				currMax = a[i][j];
				p = j;
			}
		// �� ��������� �� � �������� ��������� �������� ��������
		if (currMax < saddle)
		{
			saddle = currMax;
			k = i; l = p;
		}
	}
	cout << "ѳ������ � ������� a[" << k << "][" << l << "] = " << saddle << '\n';
	return;
}