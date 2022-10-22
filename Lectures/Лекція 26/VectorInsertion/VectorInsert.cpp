#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "noisy.h"
using namespace std;

long Noisy::create = 0, Noisy::assign = 0,
	Noisy::copy = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

int main()
{
	vector<Noisy> v;
	v.reserve(15);
	cout<<"15 spaces have been reserved\n";
	cin.get();
	generate_n(back_inserter(v),8,NoisyGen());
	ostream_iterator<Noisy> out(cout," ");
	cout<<endl;
	copy(v.begin(),v.end(),out);
	cin.get();
	cout << "\nEmlace elements:\n";
	v.emplace_back(5);
	v.emplace_back();
	cout << endl;
	copy(v.begin(), v.end(), out);
	cin.get();
	cout<<"\nInserting an element:\n";
	vector<Noisy>::iterator it = v.begin()+v.size()/2;
	v.insert(it,Noisy());
	cout<<endl;
	copy(v.begin(),v.end(),out);
	cin.get();
	it = v.end() - 3;
	v.insert(it, Noisy());
	cout << endl;
	copy(v.begin(), v.end(), out);
	cin.get();
	cout << "\nErasing an element:\n";
	it = v.begin()+v.size()/2;   // !!!
	v.erase(it);
	cout<<endl;
	copy(v.begin(),v.end(),out);
	cout<<endl;
	cin.get();
	//*out++ = Noisy();
	//*out = Noisy();
	//cin.get();
	return 0;
}
/*
11 spaces have been reserved
d[0]
c[0]
~[0]
d[1]
c[1]
~[1]
d[2]
c[2]
~[2]
d[3]
c[3]
~[3]
d[4]
c[4]
~[4]
d[5]
c[5]
~[5]
d[6]
c[6]
~[6]
d[7]
c[7]
~[7]
d[8]
c[8]
~[8]
d[9]
c[9]
~[9]

0 1 2 3 4 5 6 7 8 9
Inserting an element:
d[10]
c[10]
c[9]
(9)=[8]
(8)=[7]
(7)=[6]
(6)=[5]
(5)=[10]
~[10]
~[10]

0 1 2 3 4 10 5 6 7 8 9
Erasing an element:
(10)=[5]
(5)=[6]
(6)=[7]
(7)=[8]
(8)=[9]
~[9]

0 1 2 3 4 5 6 7 8 9
~[0]
~[1]
~[2]
~[3]
~[4]
~[5]
~[6]
~[7]
~[8]
~[9]

--------------------------------
  Noisy creations: 11
Copy-Constructions: 12
Assigniments: 10
Destructions: 23
*/