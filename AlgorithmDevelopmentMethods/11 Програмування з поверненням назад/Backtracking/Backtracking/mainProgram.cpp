#include <Windows.h>
#include "Procedures.h"

int main()
{
	// ��������� � ������������ (��������� �� �������)

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ��� ���� ����������� ����������\n"
			<< " 2 - ��� ���� ��� ������\n 3 - ������ ��� ������������ �����\n"
			<< " 4 - ���������� ������\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: tourByRecursion(); break;
		case 2: solveTour(); break;
		case 3: putQueens(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 4);
	return 0;
}