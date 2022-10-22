#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Tools.h"
using namespace std;

// Шаблон функції, що демонструє використання базових можливостей
// довільного послідовного контейнера
template<typename ContainerOfInt>
void basicOps(const char* s)
{
	cout << "-------- " << s << " --------" << endl;
	typedef ContainerOfInt Ci;
	Ci c;
	print(c, "c after default constructor");
	Ci c1{ 10, 20, 30, 45 }; // безпосередня ініціалізація
	print(c1, "c1 after initialization");
	typename Ci::iterator iter = c1.begin();
	c1.emplace(++iter, 13);
	print(c1, "c1 after emplace");
	Ci c2(10, 1);          // 10 елементів = 1
	print(c2, "c2 after constructor(10,1)");
	int ia[] = { 1, 3, 5, 7, 9 };
	const int iasz = sizeof(ia)/sizeof(*ia);
// Ініціалізація за допомогою початкового та кінцевого ітераторів
	Ci c3(ia, ia + iasz);
	print(c3, "c3 after constructor(iter,iter)");
	Ci c4(c2);             // Конструктор копіювання
	print(c4, "c4 after copy-constructor(c2)");
	c = c2;                // Оператор присвоєння
	print(c, "c after operator=c2");
	c.assign(10, 2);       // 10 елементів зі значенням 2
	print(c, "c after assign(10,2)");
// Присвоєння за допомогою ітераторів
	c.assign(ia, ia + iasz);
	print(c, "c after assign(iter,iter)");
	cout << "c using reverse iterators:" << endl;
	typename Ci::reverse_iterator rit = c.rbegin();
	while (rit != c.rend()) cout << *rit++ << " ";
	cout << endl;
	c.resize(4);
	print(c, "c after resize(4)");
	c.push_back(47);
	print(c, "c after push_back(47)");
	c.pop_back();
	print(c, "c after pop_back()");
	typename Ci::iterator it = c.begin();
	++it; ++it;
	c.insert(it,74);
	print(c, "c after insert(it,74)");
	it = c.begin(); ++it;
	c.insert(it,3,96);
	print(c, "c after insert(it,3,96)");
	it = c.begin(); ++it;
	c.insert(it,c3.begin(),c3.end());
	print(c, "c after c.insert(it,c3.begin(),c3.end())");
	it = c.begin(); ++it;
	c.erase(it);
	print(c, "c after erase(it)");
	typename Ci::iterator it2 = it = c.begin();
	++it;
	++it2; ++it2; ++it2; ++it2; ++it2;
	c.erase(it,it2);
	print(c, "c after erase(it,it2)");
	c.swap(c2);
	print(c, "c after swap(c2)");
	c.clear();
	print(c, "c after clear()");
}
int use_basicOps()
{
	// при виклику потрібно явно вказувати тип спеціалізації
	basicOps< vector<int> >("vector");
	basicOps< deque<int> >("deque");
	basicOps< list<int> >("list");
	return 0;
}
/*
-------- vector --------
c after default constructor:
(empty)
c2 after constructor(10,1):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c3 after constructor(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c4 after copy-constructor(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after operator=c2:
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after assign(10,2):
2 2 2 2 2 2 2 2 2 2
size() 10 max_size() 1073741823 front() 2 back() 2
c after assign(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c using reverse iterators:
9 7 5 3 1
c after resize(4):
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after push_back(47):
1 3 5 7 47
size() 5 max_size() 1073741823 front() 1 back() 47
c after pop_back():
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after insert(it,74):
1 3 74 5 7
size() 5 max_size() 1073741823 front() 1 back() 7
c after insert(it,3,96):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after c.insert(it,c3.begin(),c3.end()):
1 1 3 5 7 9 96 96 96 3 74 5 7
size() 13 max_size() 1073741823 front() 1 back() 7
c after erase(it):
1 3 5 7 9 96 96 96 3 74 5 7
size() 12 max_size() 1073741823 front() 1 back() 7
c after erase(it,it2):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after swap(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after clear():
(empty)
-------- deque --------
c after default constructor:
(empty)
c2 after constructor(10,1):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c3 after constructor(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c4 after copy-constructor(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after operator=c2:
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after assign(10,2):
2 2 2 2 2 2 2 2 2 2
size() 10 max_size() 1073741823 front() 2 back() 2
c after assign(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c using reverse iterators:
9 7 5 3 1
c after resize(4):
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after push_back(47):
1 3 5 7 47
size() 5 max_size() 1073741823 front() 1 back() 47
c after pop_back():
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after insert(it,74):
1 3 74 5 7
size() 5 max_size() 1073741823 front() 1 back() 7
c after insert(it,3,96):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after c.insert(it,c3.begin(),c3.end()):
1 1 3 5 7 9 96 96 96 3 74 5 7
size() 13 max_size() 1073741823 front() 1 back() 7
c after erase(it):
1 3 5 7 9 96 96 96 3 74 5 7
size() 12 max_size() 1073741823 front() 1 back() 7
c after erase(it,it2):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after swap(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after clear():
(empty)
-------- list --------
c after default constructor:
(empty)
c2 after constructor(10,1):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c3 after constructor(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c4 after copy-constructor(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after operator=c2:
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after assign(10,2):
2 2 2 2 2 2 2 2 2 2
size() 10 max_size() 1073741823 front() 2 back() 2
c after assign(iter,iter):
1 3 5 7 9
size() 5 max_size() 1073741823 front() 1 back() 9
c using reverse iterators:
9 7 5 3 1
c after resize(4):
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after push_back(47):
1 3 5 7 47
size() 5 max_size() 1073741823 front() 1 back() 47
c after pop_back():
1 3 5 7
size() 4 max_size() 1073741823 front() 1 back() 7
c after insert(it,74):
1 3 74 5 7
size() 5 max_size() 1073741823 front() 1 back() 7
c after insert(it,3,96):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after c.insert(it,c3.begin(),c3.end()):
1 1 3 5 7 9 96 96 96 3 74 5 7
size() 13 max_size() 1073741823 front() 1 back() 7
c after erase(it):
1 3 5 7 9 96 96 96 3 74 5 7
size() 12 max_size() 1073741823 front() 1 back() 7
c after erase(it,it2):
1 96 96 96 3 74 5 7
size() 8 max_size() 1073741823 front() 1 back() 7
c after swap(c2):
1 1 1 1 1 1 1 1 1 1
size() 10 max_size() 1073741823 front() 1 back() 1
c after clear():
(empty)
*/