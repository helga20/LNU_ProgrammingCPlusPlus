#include <Windows.h>
#include "intProcedures.h"

int main()
{
	// ������ ����������� ����������
	//
	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� �������:\n\n 1 - ������ ����������� ���� �����\n"
			<< " 2 - �� � ����� ����������?\n 3 - �������� ������� ����\n"
			<< " 4 - ����������� �� (2) � (16) ������ ��������\n 5 - ������� ����� �� ����� ��������\n"
			<< " 6 - ���������� ������\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: digitsAverage(); break;
		case 2: isPolyndrome(); break;
		case 3: BezuHypothesis(); break;
		case 4: binaryForm(); binaryFormStr();
			hexaFormStr(); break;
		case 5: decomposition1(); decomposition2();
			Decomposition(); Factors(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}