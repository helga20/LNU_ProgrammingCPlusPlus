#include <Windows.h>
#include "sortProcedures.h"

int main()
{
	// ������ ��������� ����������

	SetConsoleOutputCP(1251); // ��������� ��������� ���������
	cout << "������� ����� ������ ��� �������������: ";
	unsigned n; cin >> n;
	int * sample = createRandomVector(n);
	int answer;
	do
	{
		system("cls");
		cout << "������� �������� �������������:\n\n 1 - ���������� ���������\n"
			<< " 2 - ���������� �������\n 3 - ���������� �������\n"
			<< " 4 - ���� ������ ��� ����������\n 5 - ���������� ������\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: manage(simpleInsertSort, sample, n); break;
		case 2: manage(findMaxSort, sample, n); break;
		case 3: manage(bubbleSort, sample, n); 
			manage(replaceSort, sample, n); break;
		case 4: delete[] sample;
			cout << "������� ����� ������ ��� �������������: ";
			cin >> n; sample = createRandomVector(n); break;
		default: cout << "�����������!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 5);
	delete[] sample;
	return 0;
}