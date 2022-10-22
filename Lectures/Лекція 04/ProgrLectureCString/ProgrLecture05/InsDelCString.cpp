#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// ������� � �������� ����� �� ������� '+' �� ����� "plus"
	char a[] = "One + Two * ++Three";
	cout << a << endl;
	size_t la = strlen(a);
	// ��������� ������� '+', ��� ������� ������� �����-����������
	size_t countPlus = 0;
	for (size_t i = 0; i < la; ++i)
		if (a[i] == '+') ++countPlus;
	// ������� ���'���, ��� ����� �������� �������
	char * b = new char[la + countPlus * 3 + 1];
	b[0] = '\0';
	// �����'����� ������� ������
	char * prevPos = a;
	// � �������� ������ '+'
	char * pos = strchr(a, '+');
	while (pos != nullptr)
	{
		// ���������� � ��������� ���, �� ���� ����� '+'
		strncat(b, prevPos, pos - prevPos);
		// �������� �����
		strcat(b, "plus");

		// �����'����� ������� ������ ������
		prevPos = ++pos;
		// �������� ��������� '+'
		pos = strchr(pos, '+');
	}
	// �������� "����"
	strcat(b, prevPos);
	// �������� �� ���������
	cout << b << endl;
	delete[] b;
	system("pause");

	// ������� � �������� ����� �� ������� "minus" �� ������ '-'
	const char * c = " 5 minus (minus2) = 7";
	cout << c << endl;
	size_t lc = strlen(c + 1);
	// ���� �� ����� ����� ������� � ������� - ���� ���������� �� �����������
	b = new char[lc];
	b[0] = '\0';
	const char * m = "minus";
	size_t lm = strlen(m);
	// �����'����� ������� ������
	const char * r = c;
	// �������� ������ "minus"
	const char * p = strstr(c, m);
	while (p != nullptr)
	{
		// ���������� � ��������� ���, �� ���� ����� "minus"
		strncat(b, r, p - r);
		strcat(b, "-");
		// �����'����� ������� ������ ������
		r = p += lm;
		//�������� ��������� "minus"
		p = strstr(p, m);
	}
	strcat(b, r);
	cout << b << endl;
	system("pause");

	return 0;
}