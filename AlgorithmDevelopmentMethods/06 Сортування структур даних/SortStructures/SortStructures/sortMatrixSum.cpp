#include "dataProcedures.h"
#include <cmath>

void sortMatrixSum()
{
	cout << "\n *���������� ����� ������� �� ���������� ��� ������*\n\n";
	// ��� ��������� ������ ������� ������ � ��� ��������
	int a[n][m];
	// ������� ������ �������
	readMatrix(a);
	// ���������� ������ ���ײ�
	int key[n] = {0};
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) key[i] += abs(a[i][j]);
	// ������������� ������ ���ײ� & ���ʲ� �����ֲ
	for (unsigned j = n; j > 1; --j)
	{
		// ��������� ��������� ������� �������������� �������
		unsigned k = 0;                  // ���������� ����� �����
		for (unsigned i = 1; i < j; ++i) // ���������� �� �����
			if (key[i] > key[k]) k = i;
		if (k != j)
		{
			// ������ ������ ����� � �����: j-� � k-��
			int toSwap = key[j - 1];
			key[j - 1] = key[k];
			key[k] = toSwap;
			exchange(a[j - 1], a[k], m);
		}
	}
	// ������� ����������
	cout << "\n�����:\n";
	for (unsigned i = 0; i < n; ++i) cout << '\t' << key[i];
	cout << "\n\n�������:\n";
	printMatrix(a);
	return;
}