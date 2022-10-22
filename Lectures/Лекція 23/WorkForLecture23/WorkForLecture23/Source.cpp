#include "Header.h"

/* ������ 1.
 * �������� �������, ��� ��������� � ����� ����� ����� �������, �� ������ ������ ��������.
 */
int findValInMas(ValueType x, ValueType a[], int n)
{
	for (int i = 0; i < n; ++i)
		if (a[i] == x) return i;
	return -1;
}

/*
 * ������ 2.
 * �������� �������, ��� ��������� � ������� ������������ ������ ����� ����� �������,
 * �� ������ ������ ��������.
 */

Node* fintValInList(ValueType x, Node* head)
{
	while (head != nullptr)
	{
		if (head->data == x) return head;
		head = head->next;
	}
	return nullptr;
}
//last - �������� �� ��������� ���������� �������� ������, �� "��������� ���� ����������"
ValueType* findValMas(ValueType x, ValueType* a, ValueType* last)
{
	for (ValueType* curr = a; curr != last; ++curr)
		if (*curr == x) return curr;
	return nullptr;
}
Node* fintValList(ValueType x, Node* head, Node* stop)
{
	for (Node* curr = head; curr != stop; curr = curr->next) // ++Curr
		if (curr->data == x) return curr; // *Curr
	return nullptr;
}

Iter findVal(ValueType x, Iter head, Iter stop)
{
	for (Iter curr = head; curr != stop; ++curr) // ++Curr
		if (*curr == x) return curr; // *Curr
	return nullptr;
}
