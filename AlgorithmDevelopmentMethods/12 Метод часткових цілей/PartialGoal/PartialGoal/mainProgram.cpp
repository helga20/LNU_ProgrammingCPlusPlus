#include <Windows.h>
#include "Procedures.h"

int main()
{
	// ��������� ������ ��������� �����

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ������������ ����������� ������������ ������\n"
			<< " 2 - ������������ ������ � �������\n 3 - ������������ ������ � ��������������� ����������\n"
			<< " 4 - ���������� �������� ������������� ������\n 5 - ���������� ������\n>>>> ";
		cin >> answer; cin.get();
		system("cls");
		switch (answer)
		{
		case 1: postfixLight(); break;
		case 2: postfix(); break;
		case 3: postfixExt(); break;
		case 4: translateAndCalculate(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 5);
	return 0;
}