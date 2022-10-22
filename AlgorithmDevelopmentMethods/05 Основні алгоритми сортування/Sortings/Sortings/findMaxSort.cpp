#include "sortProcedures.h"

// ������������� ������ � �� ��������� ������ �����������
void findMaxSort(int * a, unsigned n)
{
	// ���������� ��������� ������� �������������� �������
	// � ������������� ���� � �� ������� ���������.
	// �������� ��������������� ���� ������
	for (unsigned j = n - 1; j > 0; --j)
	{
		int maxVal = a[0]; // �������� �������� � ����� ����������
		unsigned maxPos = 0;
		for (unsigned i = 1; i <= j; ++i)
			if (a[i] > maxVal)
			{
				maxVal = a[i];
				maxPos = i;
			}
		if (maxPos != j) // ������� ���������� �� ���� ����
		{
			a[maxPos] = a[j];
			a[j] = maxVal;
		}
	}
	return;
}