#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// ���������� ��������� ��������� ��� ��������� ��������
	SetConsoleOutputCP(1251);
	/* ������ ���������� n. ��������� n!
	*/
	cout << " *** Task 1\n\n";
	cout << "������ ���������� (�� ���� ������) �����: ";
	unsigned n;
	cin >> n;
	// ��� ���������� ��������� ����� ��������� n ���������� �����
	// � �������� �������� � ������
	// ��� ����� ����������� ���������� for
	long long factorial = 1LL; // ��������� �������� ���������
	for (unsigned multiplier = 2; multiplier <= n; ++multiplier)
	{
		factorial *= multiplier;
	}
	cout << n << "! = " << factorial << endl;
	system("pause");
	/* ������ ���������� n. ��������� sqrt(3 + sqrt(6 + ... + sqrt(3(n-1) + sqrt(3n)) ... )).
	*/
	cout << "\n *** Task 2\n\n";
	cout << "������ ���������� �����: ";
	cin >> n; // �� ����� ��� ��������� �����
	double R = 0.; // �������� ���������
	// ���������� ������� �������� � ���������� ������.
	// ��������� ������ �� ����
	for (unsigned term = 3 * n; term >= 3; term -= 3)
	{
		R = sqrt(term + R);
	}
	cout << "������ ����� = " << R << endl;
	system("pause");
	/* ������ ���������� n. ���������
	   sin(1)    sin(1)+sin(2)           sin(1)+sin(2)+...+sin(n)
	   ------ x --------------- x ... x --------------------------.
	   cos(n)   cos(n)+cos(n-1)         cos(n)+cos(n-1)+...+cos(1)
	*/
	cout << "\n *** Task 3\n\n";
	cout << "������ ���������� �����: ";
	cin >> n; // �� ����� ��� ��������� �����
	// ������ ������������ ���� ������ ��� ����������, ���� �������� ��� ���������� � ���� �������
	double S = 0.; // ���� ������
	double C = 0.; // ���� ��������
	double P = 1.; // ������� �������
	// � ���������� for ������ ��������� ��������� � ������, � ��������
	for (unsigned i = 1, j = n; i <= n; ++i, --j)
	{
		S += sin(i);
		C += cos(j);
		P *= S / C;
	}
	cout << "������� ����� ���������������� ������� = " << P << endl;
	system("pause");
	return 0;
}