#include <Windows.h>
#include "loopsProcedures.h"

int main()
{
	// ������� ����� � ��������� �������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� ��� �������:\n\n 1 - �������� �������� ������� �������� ������\n"
			<< " 2 - �������� �������� ������� �������� ������\n 3 - �������, ��������� ������\n"
			<< " 4 - ������� � ��� �������� ���� �������\n 5 - ���������� max-�������� �������������� ����� � ��������\n"
			<< " 6 - ³�������� �������� ���������������\n 7 - ���������� ������\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: unitaryMatrix(); symmetricBuildMatrix(); break;
		case 2: triangleMatrix(); break;
		case 3: matrixFromSequence(); sequenceToMatrix(); break;
		case 4: regionsSumming(); economySumming(); break;
		case 5: moveMax(); break;
		case 6: saddleElement(); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}