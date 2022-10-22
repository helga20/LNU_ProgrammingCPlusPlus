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
// ----------------------------- Зніміть коментарі //, щоб отримати працездатний клас
/* конструктор копіювання */
//StringBad::StringBad(const StringBad& st)
//{
//	len = st.len;		// довжина у копії така ж
//	str = new char[len + 1];	// виділення пам’яті
//	strcpy(str, st.str);	// копіювання рядка
//	num_strings++;		// оновлення статичного елемента-лічильника
//	cout << num_strings << ": \"" << str << "\" object copy-created\n";
//}
/* оператор присвоєння */
//StringBad& StringBad::operator=(const StringBad& st)
//{
//	if (this == &st) return *this;	// запобігти самоприсвоєнню !
//	delete[] str;		// звільнити раніше зайняту пам’ять
//	len = st.len;
//	str = new char[len + 1];	// виділити нову пам’ять
//	strcpy(str, st.str);	// копіювати рядок
//	return *this;		// повернути отримувача
//}
