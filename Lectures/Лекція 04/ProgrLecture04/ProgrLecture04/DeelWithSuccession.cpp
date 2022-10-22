#include <iostream>

using namespace std;

int main()
{
	/* ������ ���������� n � ����������� n ������� �����.
	   ��������� ���� ����.
	*/
	cout << " *** Task 1\n\n";
	cout << "Input size of the succession: ";
	int n;
	cin >> n;
	double S = 0.;
	cout << "Input " << n << " positive numbers: ";
	for (int i = 0; i < n; ++i)
	{
		double a;
		cin >> a;
		S += a;
	}
	cout << "Sum = " << S << endl;
	system("pause");
	/* ������ ���������� n � ����������� n ������� �����.
	   �� ������������ �� �� ����������?
	*/
	cout << "\n *** Task 2\n\n";
	cout << "Input size of the succession: ";
	cin >> n;
	cout << "Input " << n << " numbers: ";
	double a, b; // ���� ������ ����� �����������
	cin >> b;    // ������ ���� ������ ���� ������
	int i;       // �������� ���� �������� ���� �����
	for (i = 1; i < n; ++i)
	{
		a = b;
		cin >> b; // ����� �����������
		if (a >= b) // ����� �������������� ��������!
			break;  // ����������� ��������� �����!
	}
	if (i == n)
	{   // �������� ������� �� ���� �����
		cout << "The succession is sorted\n";
	}
	else
	{   // ���� ���������� ���������� ����� ��������� ����� ��������������
		cout << "The succession is not ordered. Wrong value at the position " << i << endl;
	}
	system("pause");
	/* ������ ���������� n � ����������� n �����.
	   ���������� ���� ������ � ��� � �������� ���� �������.
	*/
	cout << "\n *** Task 3\n\n";
	cout << "Input size of the succession: ";
	cin >> n;
	cout << "Input " << n << " numbers: ";
	int counter = 0;       // ������� �������
	for (int i = 0; i < n; ++i)
	{
		double a;
		cin >> a; // �������� ���� �����������
		if (a <= 0)   // ����� ������ �� �������
			continue; // ����������� ������� ����������
		cout << ' ' << a;
		++counter;
	}
	cout << endl;
	cout << "Count of positive members of the succession is equal to " << counter << endl;
	system("pause");
	return 0;
}