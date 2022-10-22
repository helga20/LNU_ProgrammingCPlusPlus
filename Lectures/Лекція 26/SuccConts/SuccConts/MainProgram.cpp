#include <iostream>
#include <windows.h>
#include "noisy.h"
#include "Tools.h"

// ���������� ��������� ������
long Noisy::create = 0, Noisy::assign = 0,
Noisy::copy = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

int quit()
{
	cout << "\nBye!\n";
	return 0;
}

int main()
{
	SetConsoleOutputCP(1251);
	typedef int(*act)(void); // using act = int(); �� ��������� ��������� �����
	act proc[] = { use_basicOps, use_algos, test_Noisy, use_Inserters, compare, quit };
	const int n = sizeof proc / sizeof *proc;
	int choice = 0;
	while (choice < n - 1)
	{
		cout << "������ ��������� ��� ���������:"
			<< "\n  0 - ����� �������� � ����������� ������������"
			<< "\n  1 - ��������� ��� ����������� ������������"
			<< "\n  2 - ������������ �������� ��'���� Noisy"
			<< "\n  3 - ���������� � �������� ����������"
			<< "\n  4 - ��������� ������䳿 ������� � ����"
			<< "\n  5 - �����\n >>> ";
		cin >> choice; cin.get();
		system("cls");
		proc[choice]();
	}
	cout << "\nClean up!\n";
	return 0;
}