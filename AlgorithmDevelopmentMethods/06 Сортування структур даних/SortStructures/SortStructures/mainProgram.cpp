#include <Windows.h>
#include "dataProcedures.h"

int main()
{
	// ���������� �������� �����

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ������������� ������� ����� �������\n"
			<< " 2 - ���������� ����� �������\n 3 - ���������� ����� ������� �� ������ ������\n"
			<< " 4 - ������������� ����� �� ��������� ������\n 5 - ������������� ����� ������� �������\n"
			<< " 6 - ������������� ����� �������\n 7 - ���������� ������\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: sortEachRow(); break;
		case 2: sortMatrix(); break;
		case 3: sortMatrixSum(); break;
		case 4: sortByChain(); break;
		case 5: sortByTree(); break;
		case 6: sortByMerge(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}