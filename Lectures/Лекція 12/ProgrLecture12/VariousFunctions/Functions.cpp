#include "Functions.h"
#include <iostream>
#include <cstdarg>

using std::cout;

int maxVal(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

double maxVal(double * A, unsigned n)
{
	double max = A[0];
	for (unsigned i = 1; i < n; ++i)
		if (A[i] > max) max = A[i];
	return max;
}

//-----------------------------------------

void writeLine(char c, unsigned k)
{
	for (unsigned i = 0; i < k; ++i) cout << c;
	cout << '\n';
}

char * left(const char * str, int n)
{
	if (n < 0) n = 0;
	char * p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; ++i) p[i] = str[i];
	while (i <= n) p[i++] = '\0';
	return p;
}

//-------------------------------------------------------
// процедура обчислює і друкує суму переданих їй аргументів
// відомо, що всі вони цілі, список закінчується нулем
void writeSum(int d ...)
{
	int s = 0;
	va_list ap;
	va_start(ap, d);
	cout << "SUM = ";
	while (d != 0){
		if (d>0) cout << '+'; cout << d;
		s += d;
		d = va_arg(ap, int);
	} va_end(ap);
	cout << " = " << s << '\n';
}

void PrintVar(char *szTypes, ...)
{
	va_list vl;
	//int i;
	va_start(vl, szTypes);
	for (int i = 0; szTypes[i] != '\0'; ++i)
	{
		switch (szTypes[i])   // Type to expect.  
		{
		case 'i':
			cout << (int)va_arg(vl, int) << '\n';
			break;
		case 'f':
			cout << (double)va_arg(vl, double) << '\n';
			break;
		case 'c':
			cout << (char)va_arg(vl, char) << '\n';
			break;
		case 's':
			cout << (char*)va_arg(vl, char *) << '\n';
			break;
		default:
			break;
		}
	}
	va_end(vl);
}

//  ShowVar takes a format string of the form "ifcs", where each character specifies the 
//  type of the argument in that position.  
//      i = int  
//      f = float  
//      c = char  
//      s = string (char *)  
//  Following the format specification is a variable list of arguments. Each argument 
//  corresponds to a format character in the format string to which the szTypes parameter 
//  points
void ShowVar(char *szTypes, ...)
{
	va_list vl;
	int i;
	//  szTypes is the last argument specified; you must access   
	//  all others using the variable-argument macros.  
	va_start(vl, szTypes);
	// Step through the list.  
	for (i = 0; szTypes[i] != '\0'; ++i)
	{
		union Printable_t
		{
			int     i;
			double  f;
			char    c;
			char   *s;
		} Printable;

		switch (szTypes[i])   // Type to expect.  
		{
		case 'i':
			Printable.i = va_arg(vl, int);
			cout << Printable.i << '\n';
			break;
		case 'f':
			Printable.f = va_arg(vl, double);
			cout << Printable.f << '\n';
			break;
		case 'c':
			Printable.c = va_arg(vl, char);
			cout << Printable.c << '\n';
			break;
		case 's':
			Printable.s = va_arg(vl, char *);
			cout << Printable.s << '\n';
			break;
		default:
			break;
		}
	}
	va_end(vl);
}

//--------------------------------------------

unsigned printChars(char c, int k)
{
	static unsigned counter = 0;
	for (int i = 0; i < k; ++i) cout << c;
	return ++counter;
}
