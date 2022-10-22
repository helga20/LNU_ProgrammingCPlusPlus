#include "HeaderNew.h"
#include <iostream>

using std::cout;

/* ����� ������ ��������� �� ����������� ��������� ����������� ����� ����������.
   ��������� � ����� �� "���������" � ������ ���������� ������� ����������� ����������.
*/
void PrintMas(ValueType* start, ValueType* end)
{
	for (ValueType* ptr = start; ptr != end; ++ptr)
	{
		cout << '\t' << *ptr;
	}
	cout << '\n';
}
ValueType* FindValInMas(ValueType x, ValueType* start, ValueType* end)
{
	while (start != end && *start != x) ++start;
	return start;
}

// �� ������� ���� ����� �� PrintMas, ��� �������� �� ����� ������ ����� ��� ���� ���������
void PrintList(Node* start, Node* end)
{
	for (Node* ptr = start; ptr != end; ptr = ptr->next)
	{
		cout << '\t' << ptr->data;
	}
	cout << '\n';
}
// ������������ "���������" ������� ����� ��������� ������. ������� ��������� �� FindValInMas
Iter FindValInList(ValueType x, Iter start, Iter end)
{
	while (start != end && *start != x) ++start;
	return start;
}