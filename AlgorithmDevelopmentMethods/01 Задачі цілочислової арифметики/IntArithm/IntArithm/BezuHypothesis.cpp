#include "intProcedures.h"

void BezuHypothesis()
{
	cout << "\n *�������� ������� ����*\n\n";
	unsigned a, b, l;
	cout << "������ ��� a,b,l: ";
	cin >> a >> b >> l;
	// �������� ����� ������������ ����� �������� ��������
	for (unsigned n = a; n <= b; ++n)
	{
		unsigned k = 0;  // �������� ����������� �����
		long long m = n; // �� ������� ����� ����� - ���� n,
						 // �� ��������� - ���� ������� � ���������� ������
		long long s = 0; // ��������� ����� ����� m
		do
		{
			m += s;
			s = reverse(m);
			++k;
		}
		while (s != m && k <= l);
		// ���������� ��������
		std::cout << "��� ����� " << n << " �� " << k - 1 << " ����(�) ";
		if (k > l) cout << "������� �� ����������\n";
		else cout << "�������� �������� " << s << '\n';
	}
	return;
}

// ������� �������� ����������� ������ �����
long long reverse(long long m)
{
	long long s = 0;
	while (m > 0)
	{
		s = s * 10 + m % 10;
		m /= 10;
	}
	return s;
}