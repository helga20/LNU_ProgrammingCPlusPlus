#include <Windows.h>
#include "stepProcedures.h"

int main()
{
	// ������ � ���������� ���������-���������� �����

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� �������:\n\n 1 - ������ ����������� ����������� n �����\n"
			<< " 2 - ������ ����������� ����������� ����� �� ������� ����\n 3 - ������� ������� ���������������� �������\n"
			<< " 4 - ��������� ������� �����������\n 5 - ����� Գ�������\n 6 - ���\'���� ��������� �����������\n"
			<< " 7 - ���������� ������\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: squareNorm(); break;
		case 2: average(); break;
		case 3: table(); break;
		case 4: succession(); break;
		case 5: Fibonacci(); break;
		case 6: aveVSgeo(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}