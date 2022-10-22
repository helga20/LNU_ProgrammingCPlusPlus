#include <iostream>
using std::cin;
using std::cout;
#include "arraydb.h"
#include "str.h"
int main()
{
	NewStr a("How do you do?");
	NewStr b;
	cout<<"Input a line: "; cin>>b;
	cout<<"The greater string is: ";
	if (a>b) cout<<a<<'\n';
	else cout<<b<<'\n';
	double c[10] = {1.,2.,3.,4.,5.,6.};
	ArrayDb d(c,8);
	cout<<"The array is:\n"<<d<<"Average value = "<<d.average()<<'\n';
	return 0;
}