#include "iterProcedures.h"

void inCircle()
{
	cout << "\n *���������� ������� ����� � ����*\n\n";
	cout << "������ ������� ���������: ";
	unsigned n; cin >> n;
	cout << "������ �����: ";
	double r; cin >> r;
	double * a = new double[n];
	cout << "������ " << n << " �����: ";
	for (unsigned i = 0; i < n; ++i) cin >> a[i];
	// �������� ����� ��������
	// ����������� ��������
	unsigned k = 0; // ��������
	r *= r;
	// ��������� ����� �������� �����
	for (unsigned i = 0; i < n / 2; ++i)
	{
		if (a[i]*a[i] + a[n-1-i]*a[n-1-i] <= r) ++k;
	}
	k *= 2;
	if (n % 2) // ��������� ������� �����
	{
		if (2 * a[n/2] * a[n/2] <= r) ++k;
	}
	cout << "����� � ���� � " << k << '\n';
	return;
}