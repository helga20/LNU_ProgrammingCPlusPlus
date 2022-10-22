#include "HeaderOld.h"
#include "HeaderNew.h"
#include "ListTempl.h"
#include "ArrayTempl.h"
#include <iostream>

using std::cout;

int main()
{
	const int n = 5;

	cout << " *** Part 1 - deeling with array and list as usual\n\n";
	int a[n] = { 1, 2, 3, 4, 5 };
	cout << " --- Array\n";
	printMas(a, n);
	int ind = findValInMas(4, a, n);
	if (ind >= 0)
	{
		cout << "The value 4 found at position " << ind << '\n';
		a[ind] = 7;
		cout << "The array after change\n";
		printMas(a, n);
	}
	else cout << "The value not found\n";
	Node * L = buildList(a, n);
	cout << " --- List\n";
	printList(L);
	Node * ptr = findValInList(7, L);
	if (ptr != nullptr)
	{
		cout << "The value 7 found in the List\n";
		ptr->data = 4;
		cout << "The list after change\n";
		printList(L);
	}
	else cout << "The value not found\n";
	cout << '\n';
	system("pause");

	cout << "\n\n *** Part 2 - deeling with array and list by pointers and iterators\n\n";
	cout << " --- Array\n";
	ValueType* start = a;
	ValueType* end = a + n;
	PrintMas(start, end);
	ValueType * Pos = FindValInMas(4, start, end);
	// перевірка тепер виглядає інакше!
	if (Pos != end)
	{
		cout << "The value 4 found at position " << Pos - start << '\n';
		*Pos = 7;
		cout << "The array after change\n";
		PrintMas(start, end);
	}
	else cout << "The value not found\n";
	cout << " --- List\n";
	// друк списку тепер має два параметри
	PrintList(L, nullptr);
	Iter startL = Iter(L);
	Iter endL = Iter();
	Iter itr = FindValInList(4, startL, endL);
	if (itr != endL)
	{
		cout << "The value 4 found in the List\n";
		*itr = 9;
		cout << "The list after change\n";
		PrintList(L, nullptr);
	}
	else cout << "The value not found\n";
	cout << '\n';
	system("pause");

	cout << "\n\n *** Part 3 - deeling with array and list by templates\n\n";
	cout << " --- Built-in array\n";
	// Iter == int*
	PrintSuccession(a, a + n);
	// ValueType == int, Iter == int*
	int * pos = FindValInSuccession(3, a, a + n);
	if (pos != a + n)
	{
		cout << "The value 3 found at position " << pos - a << '\n';
		*pos = 8;
		cout << "The array after change\n";
		PrintSuccession(a, a + n);
	}
	else cout << "The value not found\n";
	cout << " --- List\n";

	// Тепер список - екземпляр шаблону
	List<int> Lst(a, n);
	PrintSuccession(List<int>::Iter(Lst), List<int>::Iter());
	List<int>::Iter startIt = Lst.begin();
	List<int>::Iter endIt = Lst.end();
	List<int>::Iter Itr = FindValInSuccession(8, startIt, endIt);
	if (Itr != endIt)
	{
		cout << "The value 8 found in the List\n";
		*Itr = 0;
		cout << "The list after change\n";
		PrintSuccession(Lst.begin(), Lst.end());
	}
	else cout << "The value not found\n";
	cout << '\n';

	// А тепер - клас-масив, екземпляр шаблону
	cout << " --- Class Array\n";
	Array<int> A(a, 5);
	cout << "Array: " << A << "average = " << A.average() << "    size = " << A.arSize() << '\n';
	PrintSuccession(A.begin(), A.end());
	Array<int>::Iter itStart = A.begin();
	Array<int>::Iter itEnd = A.end();
	Array<int>::Iter itFind = FindValInSuccession(5, itStart, itEnd);
	if (itFind != itEnd)
	{
		cout << "The value 5 found in the Array\n";
		*itFind = 10;
		cout << "The Array after change\n";
		PrintSuccession(itStart, itEnd);
	}
	else cout << "The value not found\n";
	cout << '\n';
	system("pause");

	cout << "\n\n *** Part 4 - dealing with templates and lambdas\n\n";
	// за допомогою функторів загальний алгоритм можна налаштувати на різні умови виконання
	// звичайний пошук значення
	Itr = FindAnyInSuccession([](int x){ return x == 0; }, Lst.begin(), endIt);
	if (Itr != endIt)
	{
		cout << "The value 0 found in the List\n";
		*Itr = 3;
		cout << "The list after change\n";
		// "пошук", що друкує послідовність значень
		FindAnyInSuccession([](int x){ cout << '\t' << x; return false; }, Lst.begin(), endIt);
	}
	else cout << "The value not found\n";
	cout << '\n';
	// "пошук", що обчислює суму елементів списку
	int total = 0;
	FindAnyInSuccession([&total](int x){ total += x; return false; }, Lst.begin(), endIt);
	cout << "The total = " << total << '\n';
	system("pause");
	return 0;
}