#include <Windows.h>
#include "calcProcedures.h"

int main()
{
	// ���������� � ������� �������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� ���������:\n\n 1 - ���������� ���� ���� �������\n"
			<< " 2 - ���������� ���� ������������ ����\n 3 - ����� ����� ������ �����\n"
			<< " 4 - ������� ������������\n 5 - ������� ������������ � ������-��������\n"
			<< " 6 - ���������� ������\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: sinSeriesSum(); break;
		case 2: sumOfSeriesB(); break;
		case 3: dichotomy(); break;
		case 4: numIntegration(); break;
		case 5: lambdaIntegration(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}