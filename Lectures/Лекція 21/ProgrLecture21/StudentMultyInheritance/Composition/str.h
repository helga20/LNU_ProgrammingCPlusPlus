#ifndef str_new_h_
#define str_new_h_

#include <iostream>
using std::ostream;
using std::istream;

class NewStr
{
private:
	char * str;
	int len;
	static const int CINLIM = 80;
public:
	NewStr(const char* s);
	NewStr();
	NewStr(const NewStr&);
	~NewStr();
	int length() const { return len; }
	NewStr& operator=(const NewStr&);
	NewStr& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;
	friend bool operator<(const NewStr&, const NewStr&);
	friend bool operator>(const NewStr&, const NewStr&);
	friend bool operator==(const NewStr&, const NewStr&);
	friend ostream& operator<<(ostream&, const NewStr&);
	friend istream& operator>>(istream&, NewStr&);
};
#endif