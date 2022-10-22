#include "loopsProcedures.h"

void unitaryMatrix()
{
	cout << "\n *�������� �������� ������� �������� ������ (� ����������)*\n\n"
		<<"������ ����� �������: ";
	unsigned n; cin >> n;
	// �������� ���'�� ��� �������� �������
	int ** a = createMatrix(n);
	// ���������� ������� ����������
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = (i == j) ? 1 : 0;
	// ��������� ����������
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}

void symmetricBuildMatrix()
{
	cout << "\n *�������� �������� ������� �������� ������ (�� ����������)*\n\n"
		<<"������ ����� �������: ";
	unsigned n; cin >> n;
	// �������� ���'�� ��� �������� �������
	int ** a = createMatrix(n);
	// ���������� ������� ����������:
	//   ������� ��������
	for (int i = 0; i < n; ++i) a[i][i] = 1;
	//   ���������� ��� � �� ���������
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			a[i][j] = a[j][i] = 0;
	// ��������� ����������
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}