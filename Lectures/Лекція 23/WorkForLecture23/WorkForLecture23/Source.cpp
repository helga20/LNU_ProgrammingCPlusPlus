#include "Header.h"

/* Задача 1.
 * Оголосіть функцію, яка знаходить у масиві цілих чисел елемент, що містить задане значення.
 */
int findValInMas(ValueType x, ValueType a[], int n)
{
	for (int i = 0; i < n; ++i)
		if (a[i] == x) return i;
	return -1;
}

/*
 * Задача 2.
 * Оголосіть функцію, яка знаходить у лінійному однозв’язному списку цілих чисел елемент,
 * що містить задане значення.
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
//last - вказівник на закінчення останнього елемента масиву, на "наступний після останнього"
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
