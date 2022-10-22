#include <iostream>
#include <cstring>
using std::cout;
#include "BadStr.h"

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
	num_strings++;
	cout<<num_strings<<": \""<<str<<"\" object created\n";
}
StringBad::StringBad()
{
	len = 3;
	str = new char[4];
	strcpy(str,"C++");
	num_strings++;
	cout<<num_strings<<": \""<<str<<"\" default object created\n";
}
StringBad::~StringBad()
{
	--num_strings;
	cout<<'\"'<<str<<" object deleted, "<<num_strings<<" left\n";
	delete [] str;
}
ostream& operator<<(ostream& os, const StringBad& st)
{
	os<<st.str; return os;
}
// ----------------------------- ����� �������� //, ��� �������� ������������ ����
/* ����������� ��������� */
//StringBad::StringBad(const StringBad& st)
//{
//	len = st.len;		// ������� � ��ﳿ ���� �
//	str = new char[len + 1];	// �������� �����
//	strcpy(str, st.str);	// ��������� �����
//	num_strings++;		// ��������� ���������� ��������-���������
//	cout << num_strings << ": \"" << str << "\" object copy-created\n";
//}
/* �������� ��������� */
//StringBad& StringBad::operator=(const StringBad& st)
//{
//	if (this == &st) return *this;	// �������� ������������� !
//	delete[] str;		// �������� ����� ������� ������
//	len = st.len;
//	str = new char[len + 1];	// ������� ���� ������
//	strcpy(str, st.str);	// �������� �����
//	return *this;		// ��������� ����������
//}
