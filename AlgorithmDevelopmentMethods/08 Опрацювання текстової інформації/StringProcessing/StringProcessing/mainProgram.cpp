#include <Windows.h>
#include "processProcedures.h"

int main()
{
	// ����������� �������� ����������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	SetConsoleCP(1251);
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ���������� ������� ���� (�����������)\n"
			<< " 2 - ���������� ������� ���� � �����\n 3 - ������������ ����� �� �����\n"
			<< " 4 - ���� ����������� �����\n 5 - ����������� ��������� ����� �����\n"
			<< " 6 - ³�������� ���������� �����\n 7 - ���������� ������\n>>>> ";
		cin >> answer; cin.get();
		system("cls");
		switch (answer)
		{
		case 1: countCharByChar(); break;
		case 2: countInString(); break;
		case 3: stringToNumber(); break;
		case 4: intSuccession(); break;
		case 5: tryfprint(); break;
		case 6: printLongest(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}