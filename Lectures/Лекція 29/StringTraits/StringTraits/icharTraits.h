#ifndef ICHAR_TAITS_H
#define ICHAR_TAITS_H

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <ostream>
#include <string>

//using std::allocator;
using std::basic_string;
using std::char_traits;
using std::ostream;
using std::string;

struct ichar_traits: char_traits<char>
{
	static bool eq(char a, char b)
	{
		return toupper(a)==toupper(b);
	}
	static bool ne(char a, char b)
	{
		return !eq(a,b);
	}
	static bool lt(char a, char b)
	{
		return toupper(a)<toupper(b);
	}
	static int compare(const char * str1, const char * str2, size_t n)
	{
		for (size_t i=0; i<n; ++i)
		{
			if (str1 == 0) return -1;
			if (str2 == 0) return 1;
			if (tolower(*str1)<tolower(*str2)) return -1;
			if (tolower(*str1)>tolower(*str2)) return 1;
			assert(tolower(*str1) == tolower(*str2));
			++str1; ++str2;
		}

		return 0;
	}
	static const char * find(const char * str, size_t n, char c)
	{
		while (n-->0)
		{
			if (toupper(*str) == toupper(c)) return str;
			++str;
		}
		return 0;
	}
};


typedef basic_string<char,ichar_traits> istring;

inline ostream & operator<<(ostream & os, const istring & str)
{
	return os << string(str.c_str(),str.length());
}

#endif