#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	ValueType a[5] = { 1, 2, 3, 4 };
	int place = findValInMas(0, a, 5);
	cout << "place = " << place << '\n';
	place = findValInMas(5, a, 5);
	cout << "place = " << place << '\n';
	system("pause");

	Node* List = new Node(1, new Node(2, new Node(3, new Node(4))));
	Node* ptr = fintValInList(2, List);
	cout << "ptr = " << ptr << '\n';
	ptr = fintValInList(5, List);
	cout << "ptr = " << ptr << '\n';
	system("pause");

	ValueType* elem = findValMas(0, a, a + 5);
	cout << "place = " << elem - a << '\n';
	elem = findValMas(5, a, a + 5);
	cout << "place = " << elem - a << '\n';
	system("pause");

	ptr = fintValList(2, List, nullptr);
	cout << "ptr = " << ptr << '\n';
	ptr = fintValList(5, List, nullptr);
	cout << "ptr = " << ptr << '\n';
	system("pause");

	Iter it = findVal(2, List, Iter());
	cout << " value = " << *it << '\n';
	system("pause");

	elem = findValInSucc(3, a, a + 5);
	cout << "place = " << elem - a << " value = " << *elem << '\n';
	it = findValInSucc(3, Iter(List), Iter());
	cout << " value = " << *it << '\n';
	system("pause");

	elem = findAnyInSucc([](int x){ return x > 2;}, a, a + 5);
	cout << "place = " << elem - a << " value = " << *elem << '\n';
	system("pause");

	findAnyInSucc([](int x){ cout << '\t' << x;  return false; }, a, a + 5);
	cout << '\n';
	findAnyInSucc([](int x){ cout << '\t' << x;  return false; }, Iter(List), Iter());
	cout << '\n';
	system("pause");

	return 0;
}