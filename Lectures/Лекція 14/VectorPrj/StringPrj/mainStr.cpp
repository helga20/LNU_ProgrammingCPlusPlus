#include <iostream>
#include <fstream>
using std::cout;
using std::ofstream;
#include "BadStr.h"
void callme1(StringBad&);
void callme2(StringBad);
int main()
{
	StringBad headline1("Celery Stalks at Midnight");
	StringBad headline2("Lettuce Pray");
	StringBad sports("Spinach Leaves Bowl for Dollars");
	cout<<"headline1: "<<headline1<<'\n'
		<<"headline2: "<<headline2<<'\n'
		<<"sports: "<<sports<<"\n\n";
	ofstream fout("result.txt");
	fout<<"headline1: "<<headline1<<'\n'
		<<"headline2: "<<headline2<<'\n'
		<<"sports: "<<sports<<"\n\n";
	fout.close();
	callme1(headline1);
	cout<<"headline1: "<<headline1<<'\n';
	callme2(headline2);
	cout<<"headline2: "<<headline2<<'\n';

	cout<<"\nInitialize one object to another:\n";
	StringBad sailor = sports;
	cout<<"sailor: "<<sailor<<'\n';

	cout<<"\nAssign one object to another:\n";
	StringBad knot; knot = headline1;
	cout<<"knot: "<<knot<<"\n\nEnd of main()\n";
	return 0;
}
void callme1(StringBad& rsb)
{
	cout<<"String passed by referense:\n \""<<rsb<<"\"\n";
}
void callme2(StringBad sb)
{
	cout<<"String passed by value:\n \""<<sb<<"\"\n";
}