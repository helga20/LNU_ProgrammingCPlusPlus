#include "iterProcedures.h"

void exchange()
{
	cout << "\n *���� ������� � ���������*\n\n";
	const int n = 5;
	cout << "������ " << n << " �����: ";
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	// ����� ����������
	double b = a[0];
	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > b)
		{
			b = a[i]; k = i;
		}
	}
	// ������������� ��������
	a[k] = a[0]; a[0] = b;
	cout << "������ �����������:\n";
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}