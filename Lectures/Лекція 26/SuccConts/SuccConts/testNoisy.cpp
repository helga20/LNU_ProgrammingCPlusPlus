#include <Windows.h>
#include "noisy.h"
#include "Tools.h"

int test_Noisy()
{
	cout << "���������: ������������ �� �������������\n   ������� ����\n";
	Noisy a, b, c;
	cin.get();
	cout << "   �����\n";
	Noisy N[2];
	cin.get();
	cout << "��������� ��������� ��'����:\n"
		<< '\t' << a << '\t' << b << '\t' << c << "\n\t" << N[0] << '\t' << N[1] << '\n';
	cin.get();
	cout << "��������� ��'���: ";
	Noisy * p = new Noisy();
	cin.get();
	cout << "���� ��������:" << *p
		<< "\n� ����� - ��������: ";
	delete p;
	cin.get();
	cout << "���������: ������������ ���������\n";
	Noisy f(a); Noisy g = b;
	cin.get();
	cout << "�������� ���������:\n";
	N[0] = f; N[1] = b;
	cout << "\n��������� �����\t" << N[0] << '\t' << N[1];
	cin.get();
	cout << "���������: ������������ � �����������\n";
	Noisy o(17), t(5, 3);
	cout << "\n������� ��'����\t" << o << '\t' << t << '\n';
	cin.get();
	cout << "����������\n";
	return 0;
}
