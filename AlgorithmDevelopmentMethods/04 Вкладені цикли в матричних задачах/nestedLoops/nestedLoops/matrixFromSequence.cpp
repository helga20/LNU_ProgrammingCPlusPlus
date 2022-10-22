#include "loopsProcedures.h"

void matrixFromSequence()
{
	cout << "\n *���������� ������� \"������\" �������� ����������*\n\n"
		<<"������ ����� �������: ";
	unsigned n; cin >> n;
	// �������� ���'�� ��� �������� �������
	int ** a = createMatrix(n);
	// ����������� ������� ������������
	int * b = new int[n * n];
	for (int i = 0; i < n * n; ++i) b[i] = i + 1;
	// ���������� ������� ����������:
	for (int j = 0; j < n; ++j)
	{
		if (j % 2 == 0) // �������� ��������
		{
			int l = j * n;
			for (int i = 0; i < n; ++i)
				a[i][j] = b[l + i];
		}
		else // ������ ��������
		{
			int l = (j + 1) * n - 1;
			for (int i = 0; i < n; ++i)
				a[i][j] = b[l - i];
		}
	}
	// ��������� ����������
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}

void sequenceToMatrix()
{
	cout << "\n *��������� \"������\" ����������� � �������*\n\n"
		<<"������ ����� �������: ";
	unsigned n; cin >> n;
	// �������� ���'�� ��� �������� �������
	int ** a = createMatrix(n);
	// ����������� ������� ������������
	int * b = new int[n * n];
	for (int i = 0; i < n * n; ++i) b[i] = i + 1;
	// ���������� ������� ����������:
	int i = 0; int j = 0;   // ���������� ����������� ��������
	int step = 1;           // �������� ������ ���� - �������
	for (int k = 1; k <= n * n; ++k)
	{					    // �������� �� ����� �����������
		a[i][j] = b[k - 1]; // ����������� ������� �����
		if (k % n == 0)     // �������� ���������
		{
			++j;            // �������� �� ������ �������
			step = -step;   // � ������ ������
		}
		else i += step;     // ����������� ��������
	}
	// ��������� ����������
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}