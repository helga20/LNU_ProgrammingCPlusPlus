#include <iostream>
#include "ListTools.h"
#include "ArrayTools.h"

using namespace ListTools;
using std::cin;
using std::cout;
using std::endl;

void Lists();
void Arrays();

int main()
{
	int answer;
	do
	{
		cout << "What kinde of structure do you want to use?\n"
			<< " 1 - list; 2 - array; 3 - to exit: ";
		cin >> answer;
		switch (answer)
		{
		case 1: Lists(); break;
		case 2: Arrays(); break;
		}
	} while (answer > 0 && answer < 3);
	return 0;
}

void Lists()
{
	cout << " **** Deel with linked lists\n-----------------------\n\n";
	cout << "+ Direct List +\n";
	List_t List = readList();
	writeList(List);
	system("pause");
	int a = delFirst(List);
	cout << "\n We get from the list: " << a << endl;
	cout << "\nRest of the list:\n";
	writeList(List);
	system("pause");
	removeList(List);
	cout << "\nAfter remove:\n";
	writeList(List);
	system("pause");

	cout << "\n+ Reverse List +\n";
	List = reverseReadList();
	writeList(List);
	system("pause");
	removeList(List);
	writeList(List);
	system("pause");

	cout << "\n+ Reverse List by recursion +\n";
	List = reverseReadList();
	writeList(List);
	system("pause");
	removeList(List);
	writeList(List);
	system("pause");

	cout << "\n+ Sorted List +\n";
	List = readSortedList();
	cout << "\nSorted list is:\n";
	writeList(List);
	int x, y;
	cout << "Input two integers: ";
	cin >> x >> y;
	insert(x, List);
	insert(y, List);
	writeList(List);
	system("pause");
	cout << "\n+ Merge Two Lists +\n";
	List_t newList = readSortedList();
	writeList(newList);
	List_t result = merge(List, newList);
	removeList(newList);
	removeList(List);
	writeList(result);
	removeList(result);
	writeList(result);
	/*List = readSortedLst();
	writeList(List);
	removeList(List);*/
	cout << "\n\n";
}

void Arrays()
{
	cout << " **** Deel with arrays\n-----------------------\n\n";
	cout << " - source arrays\n";
	const int n = 5;
	int a[n] = { 5, 3, 8, 2, 1 };
	const int m = 7;
	int b[m] = { 4, 7, 6, 10, 9, 11, 0 };
	writeArray(a, n);
	writeArray(b, m);
	cout << " - sorted arrays\n";
	sortByList(a, n);
	sortByList(b, m);
	writeArray(a, n);
	writeArray(b, m);
	cout << " - merged array\n";
	int* c = merge(a, n, b, m);
	writeArray(c, n + m);
	delete[] c;
	cout << "\n\n";
}
