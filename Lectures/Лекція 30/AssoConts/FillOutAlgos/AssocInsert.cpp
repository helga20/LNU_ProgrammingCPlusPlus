#include <iterator>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "SimplGens.h"
#include "aFilGenN.h"
using namespace std;

int main()
{
	set<int> s;
	fill_n(inserter(s,s.begin()), 10, 47);
	generate_n(inserter(s,s.begin()),10,IncrGen<int>(12));
	copy(s.begin(),s.end(),ostream_iterator<int>(cout, "\t"));
	cout<<'\n';
	s.clear();
	as_fill_n(s, 10, 47);
	as_generate_n(s,10,IncrGen<int>(12));
	copy(s.begin(),s.end(),ostream_iterator<int>(cout, "\t"));
	cout<<'\n';
	map<int,int> m;
	fill_n(inserter(m,m.begin()), 10, make_pair(90,120));
	generate_n(inserter(m,m.begin()),10,PairGen<int,int>(3,9));
	copy(m.begin(),m.end(),ostream_iterator< pair<int,int> >(cout, ""));
	cout<<'\n';
	m.clear();
	as_fill_n(m, 10, make_pair(90,120));
	as_generate_n(m,10,PairGen<int,int>(3,9));
	copy(m.begin(),m.end(),ostream_iterator< pair<int,int> >(cout, ""));
	cout<<'\n';
	return 0;
}
/*
12      13      14      15      16      17      18      19      20      21
47
12      13      14      15      16      17      18      19      20      21
47
3 : 9
4 : 10
5 : 11
6 : 12
7 : 13
8 : 14
9 : 15
10 : 16
11 : 17
12 : 18
90 : 120

3 : 9
4 : 10
5 : 11
6 : 12
7 : 13
8 : 14
9 : 15
10 : 16
11 : 17
12 : 18
90 : 120
*/