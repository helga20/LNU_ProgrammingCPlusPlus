#include "loopsProcedures.h"
#include <iomanip>

// �������� ���'�� ��� �������� �������
int** createMatrix(int n)
{
	int ** a = new int*[n];
	a[0] = new int[n * n];
	for (int i = 1; i < n; ++i) a[i] = a[i -1] + n;
	return a;
}

// ��������� ������� �� �������
void printMatrix(int** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << std::setw(4) << a[i][j];
		cout << '\n';
	}
	return;
}

// ��������� ���'�� �� �������
void eraseMatrix(int ** a)
{
	delete [] a[0];
	delete [] a;
}