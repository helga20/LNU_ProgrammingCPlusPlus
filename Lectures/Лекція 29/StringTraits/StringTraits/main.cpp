#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "icharTraits.h"
using namespace std;

int main()
{
	istring first = "tHis";
	istring second= "ThISs";
	cout << first << endl;
	cout << second << endl;
	//assert(first.compare(second)==0);
	assert(first.find('h')==1);
	assert(first.find('I')==2);
	assert(first.find('x')==string::npos);
	cout << (first.compare(second)==0) << endl;
	cout << (first.find('h')==1) << endl;
	cout << (first.find('I')==2) << endl;
	cout << (first.find('x')==string::npos) << endl;
	if (first==second) cout<<"yess!!!\n";
	else cout << "noonono\n";
	list<istring> words;
	words.push_back("AMERIGO"); words.push_back("mysterious");
	words.push_back("Ukraine"); words.push_back("UKRAINE");
	words.push_back("America"); words.push_back("ukrainian");
	words.push_back("myCls"); words.push_back("MyObj");
	words.push_back("american"); words.push_back("MYcomparer");
	words.push_back("Snowboard"); words.push_back("CAPITALS");
	words.push_back("capital"); words.push_back("snow");
	copy(words.begin(), words.end(), ostream_iterator<istring>(cout, " "));
	cout << '\n';
	words.sort();
	copy(words.begin(), words.end(), ostream_iterator<istring>(cout, " "));
	cout << '\n';
	system("pause");
	return 0;
}