#include "loopsProcedures.h"

void triangleMatrix()
{
	cout << "\n *�������� �������� ������� �������� ������*\n\n"
		<<"������ ����� �������: ";
	unsigned n; cin >> n;
	// �������� ���'�� ��� �������� �������
	int ** a = createMatrix(n);
	// ���������� ������� ����������:
	int n1 = n - 1;
	//   ������ ��������
	for (int i = 0; i < n; ++i) a[i][n1 - i] = n;
	//   ������ ���������
	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < n1 - i; ++j)
			a[i][j] = i + j + 1;
	//   ����� ���������
	for (int i = 1; i < n; ++i)
		for (int j = n - i; j < n; ++j)
			a[i][j] = 0;
	// ��������� ����������
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}