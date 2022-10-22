#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// ���������� ��������� ��������� ��� ��������� ��������
	SetConsoleOutputCP(1251);
	/* ������ ���� k � ������� [0; 99].
	   ����������� ����� "�� ������� k �����", ���������� ��������� ���
	*/
	cout << "������ ���� ����� � [0; 99]: ";
	int k;
	cin >> k;
	cout << "\n *** �� ��������� if\n\n";
	// 1, 21, 31, ..., 91 ����
	// 2, 3, 4, 22, 23, 24, ..., 94 �����
	// 5, 6, ..., 20, 25, 26, ..., 30, 35, ..., 99 �����
	if (k == 0) cout << "�� �� ������� �����\n";
	else
	{
		cout << "�� ������� " << k;
		if (k >= 5 && k <= 20) cout << "�����\n";
		else
		{
			int d = k % 10;
			if (d == 1) cout << " ����\n";
			else if (d >= 2 && d <= 4) cout << " �����\n";
			else cout << " �����\n";
		}
	}
	system("pause");

	cout << "\n *** �� ��������� switch\n\n";
	switch (k)
	{
	case 0:
		cout << "�� �� ������� �����\n"; break;
	case 11: case 12: case 13: case 14: case 15:
	case 16: case 17: case 18: case 19:
		cout << "�� ������� " << k << " �����\n"; break;
	default:
		switch (k % 10)
		{
		case 1: cout << "�� ������� " << k << " ����\n"; break;
		case 2: case 3: case 4:
			cout << "�� ������� " << k << " �����\n"; break;
		case 5: case 6: case 7: case 8: case 9: case 0:
			cout << "�� ������� " << k << " �����\n"; break;
		}
	}
	system("pause");
	return 0;
}