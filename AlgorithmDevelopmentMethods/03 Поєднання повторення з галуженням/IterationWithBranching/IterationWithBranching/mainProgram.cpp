#include <Windows.h>
#include "iterProcedures.h"

int main()
{
	// ������, �� �������� ���������� � ����������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� �������:\n\n 1 - ������ ����� ����������� ������������� �����\n"
			<< " 2 - ������ ����� �������� ������\n 3 - ���������� - �� ������� �����������\n"
			<< " 4 - �������� �������������� ������� �����������\n 5 - ������� ����� � ������������ �����������\n"
			<< " 6 - ���������� ������\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: countProper(); break;
		case 2: inCircle(); break;
		case 3: exchange(); break;
		case 4: isGrowth(); break;
		case 5: forwardInsert(); simpleInsert(); binaryInsert(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}