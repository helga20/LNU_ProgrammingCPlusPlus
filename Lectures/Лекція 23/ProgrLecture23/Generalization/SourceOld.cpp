#include "HeaderOld.h"
#include <iostream>

using std::cout;

/* Функції для роботи з масивом та однозв'язним списком виконані в традиційному стилі.
   Вони враховують внутрішню будову контейнерів, з якими працюють.
*/
void printMas(ValueType a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << '\t' << a[i];
	}
	cout << '\n';
}
int findValInMas(ValueType x, ValueType a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (x == a[i]) return i;
	}
	return -1;
}

void printList(Node* L)
{
	while (L != nullptr)
	{
		cout << '\t' << L->data;
		L = L->next;
	}
	cout << '\n';
}
Node* buildList(ValueType a[], int n)
{
	Node* L = new Node(a[n - 1]);
	for (int i = n - 2; i >= 0; --i)
	{
		L = new Node(a[i], L);
	}
	return L;
}
Node* findValInList(ValueType x, Node* L)
{
	while (L != nullptr && L->data != x) L = L->next;
	return L;
}