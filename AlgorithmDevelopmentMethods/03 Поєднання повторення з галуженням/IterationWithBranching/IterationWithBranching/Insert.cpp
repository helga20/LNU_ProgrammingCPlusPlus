#include "iterProcedures.h"

void forwardInsert()
{
	cout << "\n *������� ����� � ������������ �����������*\n"
		<< "    ����� �� �������\n\n";
	const int n = 6;
	cout << "������ " << n - 1 << " �����: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "����i�� ���� �����: ";
	double b; cin >> b;
	// ������ ���� ��� b
	i = 0;
	while (a[i] < b && i < n - 1) ++i;
	//�������� �����
	for (int j = n - 2; j >= i; --j) a[j + 1] = a[j];
	a[i] = b; // ���������� b � �����
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}

void simpleInsert()
{
	cout << "\n *������� ����� � ������������ �����������*\n"
		<< "    ����� �� ����\n\n";
	const int n = 6;
	cout << "������ " << n - 1 << " �����: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "����i�� ���� �����: ";
	double b; cin >> b;
	// ������ ���� ��� b � �������� �����
	i = n - 2;
	while (a[i] > b && i >= 0)
	{
		a[i + 1] = a[i];
		--i;
	}
	a[i + 1] = b; // ���������� b � �����
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}

void binaryInsert()
{
	cout << "\n *������� ����� � ������������ �����������*\n"
		<< "    �������� �����\n\n";
	const int n = 6;
	cout << "������ " << n - 1 << " �����: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "����i�� ���� �����: ";
	double b; cin >> b;
	// �������� ��� ������
	int p = 0; int q = n - 1;
	while (p != q)
	{
		int s = (p + q) / 2; // ������ ������� �������
		if (a[s] < b) p = s + 1; else q = s; //� ��������� � ���
	}
	//�������� �����
	for (int j = n - 2; j >= p; --j) a[j + 1] = a[j];
	a[p] = b; // ���������� b � �����
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}