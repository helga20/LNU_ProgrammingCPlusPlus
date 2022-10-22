#include <iostream>

using namespace std;

int main()
{
	/* ������ ����������� �����, �� ���������� �����.
	   �������� ������ ����������� �����������.
	   ���� �� �����������
	*/
	cout << " *** Task 1\n\n";
	cout << "Input a succession of numbers terminated by zero:\n";
	int a;      // ���� �����������
	cin >> a;   // ������ ������ ���� ������
	int i = 0;  // ������� ����������
	int S = 0;  // ���� �����������
	// ������� ������� ������� �� �����, ���� ����������� ����������� ����:
	// ���������� �������������, ���� ���������� ������� �������� ��������
	while (a != 0)
	{
		S += a;
		++i;
		cin >> a; // ����� �����������
	}
	if (i == 0)
	{
		cout << "The succession starts with zero.\n";
	}
	else
	{
		cout << "The average is equal to " << (double)S / i << endl;
	}
	system("pause");

	/* ������ ����������� �� ����� �� �'�������� �����.
	   ������� �������� ���������� � ���.
	*/
	cout << "\n *** Task 2\n\n";
	const int n = 50; // ³���� ������� ��������� ����������
	cout << "Input up to " << n << " numbers: ";
	cin >> a;    // ������ ���� �����������
	int max = a; // ���� ���� ���������
	int k = 1;   // ������� ����������
	// ����� ����� ������ �������� �������!
	// ���� ���������� ��� �����, cin ������������� �� true
	while (k <= n && cin >> a)
	{
		++k;
		if (a > max) max = a;
	}
	cout << "The maximal value among " << k << " integers is " << max << endl;
	// ��������� ���� �������� �� �������� �����
	cin.clear();
	while (cin.get() != '\n') continue;
	system("pause");
	/* ������ ����� �����. �������� ����� ������� � ����� �� ���������� �������.
	   ���������� ����������� ���������� �� ����'���� �������.
	   ���������� ��������, ���� ��� �������� ���������� ����������� ����� �� �� 10^(-7)
	*/
	cout << "Input a number: ";
	double x;
	cin >> x;
	double r = 1.; // ��������� ����������
	double p;      // p ������ �������� ����������
	do
	{
		p = r;
		cout << p << endl;
		r = (x / (p*p) + 2.*p) / 3.;
	} while (abs(p - r) > 1e-7);
	cout << "Cube root of " << x << " is equal to " << r << endl;
	system("pause");
	return 0;
}