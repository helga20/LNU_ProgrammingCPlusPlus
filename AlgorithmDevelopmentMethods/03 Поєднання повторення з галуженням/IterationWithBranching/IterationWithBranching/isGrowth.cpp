#include "iterProcedures.h"

void isGrowth()
{
	cout << "\n *��������, �� ������������ �����������*\n\n";
	const int n = 5;
	cout << "������ " << n << " �����: ";
	int a[n]; int i;
	for (i = 0; i < n; ++i) cin >> a[i];
	// ��������
	i = 1;
	while (a[i-1] < a[i] && i < n) ++i;
	if (i == n) cout << "����������� ���������\n";
	else cout << "����� �������������� �������� ����� �[" << i << "]\n";
	return;
}