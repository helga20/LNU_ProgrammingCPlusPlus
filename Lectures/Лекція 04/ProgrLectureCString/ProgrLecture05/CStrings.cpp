//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// ������� ������� ����������� ���������
	char a[] = "Hello";
	cout << a << endl;
	char b[] = "World";
	cout << b << endl;
	// ��������� ���� �� ���� �����
	char c[20] = {'\0'};
#ifdef _CRT_SECURE_NO_WARNINGS
	// ������� ����� �����
	strcpy(c, a);
	// �������� �����������
	strcat(c, ", ");
	strcat(c, b);
	// ���������� ���������� ����� ���������� �������� �����
	size_t n = strlen(c);
	c[n] = '!';
#else
	// ������� ����� �����
	strcpy_s(c, a);
	// �������� �����������
	strcat_s(c, ", ");
	strcat_s(c, b);
	// ���������� ���������� ����� ���������� �������� �����
	size_t n = strlen(c);
	c[n] = '!';
	c[n + 1] = '\0';
#endif
	cout << c << endl;
	system("pause");
	// ������� ����� - ������� ����� ����� �������� �������
	char * pos = strchr(c, 'W');
	// ������ ����� - ������, ��������
	/*while (*pos != '!')
	{
		*pos = toupper(*pos);
		++pos;
	}*/
	// ������ ����� - �� ��������� ���������� �������
#ifdef _CRT_SECURE_NO_WARNINGS
	_strupr(pos);
#else
	_strupr_s(pos, 10);
#endif
	cout << c << endl;
	system("pause");
	return 0;
}