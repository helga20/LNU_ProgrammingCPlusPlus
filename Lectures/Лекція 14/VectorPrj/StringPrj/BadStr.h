#include <iostream>
using std::ostream;
#ifndef bad_str_h_
#define bad_str_h_
class StringBad
{
private:
	char * str;
	int len;
	static int num_strings;
public:
	StringBad(const char* s);
	StringBad();
	// ----------------------------- Зніміть коментарі //, щоб отримати працездатний клас
	//StringBad(const StringBad& st);
	//StringBad& operator=(const StringBad& st);
	~StringBad();
	friend ostream& operator<<(ostream& os, const StringBad& st);
};
#endif