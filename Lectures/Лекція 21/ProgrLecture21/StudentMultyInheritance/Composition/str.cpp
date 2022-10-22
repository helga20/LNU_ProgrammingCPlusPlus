#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::cin;
#include "str.h"

NewStr::NewStr(const char* s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
}
NewStr::NewStr()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
}
NewStr::NewStr(const NewStr& st)
{
	len = st.len;
	str = new char[len+1];
	strcpy(str, st.str);
}
NewStr::~NewStr()
{
	delete [] str;
}
NewStr& NewStr::operator=(const NewStr& st)
{
	if (this == &st) return *this;
	delete[] str;
	len = st.len;
	str = new char[len+1];
	strcpy(str, st.str);
	return *this;
}
NewStr& NewStr::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	return *this;
}
char& NewStr::operator[](int i)
{
	if ( i<0 || i>=len )
	{
		std::cerr << "Error in NewStr limits: " << i 
			<< " is a bad index.\n";
		exit(1);
	}
	return str[i];
}
const char& NewStr::operator[](int i) const
{
	if ( i<0 || i>=len )
	{
		std::cerr << "Error in NewStr limits: " << i 
			<< " is a bad index.\n";
		exit(1);
	}
	return str[i];
}
bool operator<(const NewStr& st1, const NewStr& st2)
{
	return strcmp(st1.str,st2.str)<0;
}
bool operator>(const NewStr& st1, const NewStr& st2)
{
	return strcmp(st1.str,st2.str)>0;
}
bool operator==(const NewStr& st1, const NewStr& st2)
{
	return strcmp(st1.str,st2.str)==0;
}
ostream& operator<<(ostream& os, const NewStr& st)
{
	os<<st.str; return os;
}
istream& operator>>(istream& is, NewStr& st)
{
	char temp[NewStr::CINLIM];
	is.get(temp,NewStr::CINLIM);
	if (is) st = temp;
	while (is && is.get()!='\n') continue;
	return is;
}