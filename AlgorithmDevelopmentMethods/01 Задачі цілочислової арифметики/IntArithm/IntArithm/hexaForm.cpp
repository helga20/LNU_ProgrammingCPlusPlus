#include "intProcedures.h"
#include <cmath>

void binaryForm()
{
	cout << "\n *����������� ����� � ������� �������*\n\n";
	unsigned n;
	cout << "������ ���������� �����: "; cin >> n;
	long long s = 0; // �������� ����� �������� �������
	long long p = 1; // p=10^0
	while (n > 0)
	{
		s += (n % 2) * p; // ������ �������� � �������� �����
		n /= 2;			  // ������ ����� �� ���������
		p *= 10;		  // ���������� ������ 10 ��� �������� �����
	}
	cout << "����� � ������� ������: " << s << '\n';
	return;
}

void binaryFormStr()
{
	using std::log;
	cout << "\n *�������� ������ ����� � ������� ������*\n\n";
	unsigned n;
	cout << "������ ���������� �����: "; cin >> n;
	// ������ ���� ��� ��������� ������
	int k = log(double(n)) / log(2.0) + 1;
	char * str = new char[k + 1]; str[k] = '\0';
	while (n > 0)
	{
		--k;
		if (n % 2) str[k] = '1'; // ������� ������� ����� ��������� ����� - 1
		else str[k] = '0';	     // ��������� ������� - �������� 0
		n /= 2;
	}
	cout << "����� � ������� ������: " << str << '\n';
	delete[] str;
	return;
}

void hexaFormStr()
{
	using std::log;
	cout << "\n *�������� ������ ����� � �������������� ������*\n\n";
	unsigned n, m;
	cout << "������ ���������� �����: "; cin >> n; m = n;
	// ������ ���� ��� ���������������� ������
	int k = log(double(n)) / log(16.0) + 1;
	char * str = new char[k + 1]; str[k] = '\0';
	while (n > 0)
	{
		--k;
		unsigned c = n % 16;		  // ������� ������������� ����� �����
		if (c < 10) str[k] = '0' + c; // ������� �����
		else str[k] = 'A' - 10 + c;   // ������ �����-�����
		n /= 16;
	}
	cout << "����� " << m << " � �������������� ������: " << str << '\n';
	delete[] str;
	cout.setf(std::ios_base::hex, std::ios_base::basefield);
	cout << "�� ���� �������� ����������: " << m << '\n';
	return;
}