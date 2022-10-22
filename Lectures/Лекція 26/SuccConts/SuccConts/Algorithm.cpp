#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include "Tools.h"
using namespace std;

// допоміжна об'єкт функція для наповнення контейнерів
class RandGen
{
public:
	int operator()(){return rand()%10;}
};

// застосування різноманітних алгоритмів до послідовних контейнерів
template<typename ContainerOfInt>
void algos(char* s)
{
	const int size_1 = 10;
	const int size_2 = 15;
	cout << "-------- " << s << " --------" << endl;
	typedef ContainerOfInt Ci;
	Ci c1;
	generate_n(back_inserter(c1),size_1,RandGen());
	print(c1, "c1 after random generation");
	Ci c2;
	generate_n(back_inserter(c2),size_2,RandGen());
	print(c2, "c2 after random generation");
	Ci c3(c1);             // Конструктор копіювання
	print(c3, "c3 after copy-constructor(c1)");
	sort(c1.begin(),c1.end());
	print(c1, "c1 after sort");
	sort(c2.begin(),c2.end());
	print(c2, "c2 after sort");
	Ci r;
	merge(c1.begin(),c1.end(),c2.begin(),c2.end(),back_inserter(r));
	print(r, "r after merge(c1,c2):");
	Ci::iterator it = unique(r.begin(),r.end());
	print(r, "r after unique()");
	r.erase(it,r.end());
	print(r, "r after erase(it)");
	unique(c3.begin(),c3.end());
	print(c3, "c3 after unique()");
	cin.get();
}
// зі списком можна працювати інакше
template<>void algos<list<int>>(char* s)
{
	const int size_1 = 10;
	const int size_2 = 15;
	cout << "-------- " << s << " --------" << endl;
	typedef list<int> Ci;
	Ci c1;
	generate_n(back_inserter(c1),size_1,RandGen());
	print(c1, "c1 after random generation");
	Ci c2;
	generate_n(back_inserter(c2),size_2,RandGen());
	print(c2, "c2 after random generation");
	Ci c3(c1);             // Конструктор копіювання
	print(c3, "c3 after copy-constructor(c1)");
//	sort(c1.begin(),c1.end());
	c1.sort();
	print(c1, "c1 after sort");
//	sort(c2.begin(),c2.end());
	c2.sort();
	print(c2, "c2 after sort");
	Ci r;
	merge(c1.begin(),c1.end(),c2.begin(),c2.end(),back_inserter(r));
	print(r, "r after merge(c1,c2):");
	Ci::iterator it = unique(r.begin(),r.end());
	print(r, "r after unique()");
	r.erase(it,r.end());
	print(r, "r after erase(it)");
	unique(c3.begin(),c3.end());
	print(c3, "c3 after unique()");
	cin.get();
}

int use_algos()
{
	srand(time(0));
	algos< vector<int> >("vector");
	algos< deque<int> >("deque");
	algos< list<int> >("list");
	return 0;
}
/*
-------- vector --------
c1 after random generation:
1 7 4 0 2 0 3 2 7 5
size() 10 max_size() 1073741823 front() 1 back() 5
c2 after random generation:
9 2 7 9 5 3 7 8 5 6 7 2 4 5 9
size() 15 max_size() 1073741823 front() 9 back() 9
c3 after copy-constructor(c1):
1 7 4 0 2 0 3 2 7 5
size() 10 max_size() 1073741823 front() 1 back() 5
c1 after sort:
0 0 1 2 2 3 4 5 7 7
size() 10 max_size() 1073741823 front() 0 back() 7
c2 after sort:
2 2 3 4 5 5 5 6 7 7 7 8 9 9 9
size() 15 max_size() 1073741823 front() 2 back() 9
r after merge(c1,c2)::
0 0 1 2 2 2 2 3 3 4 4 5 5 5 5 6 7 7 7 7 7 8 9 9 9
size() 25 max_size() 1073741823 front() 0 back() 9
r after unique():
0 1 2 3 4 5 6 7 8 9 4 5 5 5 5 6 7 7 7 7 7 8 9 9 9
size() 25 max_size() 1073741823 front() 0 back() 9
r after erase(it):
0 1 2 3 4 5 6 7 8 9
size() 10 max_size() 1073741823 front() 0 back() 9
c3 after unique():
1 7 4 0 2 0 3 2 7 5
size() 10 max_size() 1073741823 front() 1 back() 5
-------- deque --------
c1 after random generation:
6 0 2 0 1 8 7 6 4 1
size() 10 max_size() 1073741823 front() 6 back() 1
c2 after random generation:
9 3 4 2 0 6 3 6 7 9 9 9 1 9 5
size() 15 max_size() 1073741823 front() 9 back() 5
c3 after copy-constructor(c1):
6 0 2 0 1 8 7 6 4 1
size() 10 max_size() 1073741823 front() 6 back() 1
c1 after sort:
0 0 1 1 2 4 6 6 7 8
size() 10 max_size() 1073741823 front() 0 back() 8
c2 after sort:
0 1 2 3 3 4 5 6 6 7 9 9 9 9 9
size() 15 max_size() 1073741823 front() 0 back() 9
r after merge(c1,c2)::
0 0 0 1 1 1 2 2 3 3 4 4 5 6 6 6 6 7 7 8 9 9 9 9 9
size() 25 max_size() 1073741823 front() 0 back() 9
r after unique():
0 1 2 3 4 5 6 7 8 9 4 4 5 6 6 6 6 7 7 8 9 9 9 9 9
size() 25 max_size() 1073741823 front() 0 back() 9
r after erase(it):
0 1 2 3 4 5 6 7 8 9
size() 10 max_size() 1073741823 front() 0 back() 9
c3 after unique():
6 0 2 0 1 8 7 6 4 1
size() 10 max_size() 1073741823 front() 6 back() 1
*/