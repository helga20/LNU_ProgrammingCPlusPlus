#include "HeaderNew.h"
#include <iostream>

using std::cout;

/* ѕерша спроба наблизити за синтаксисом алгоритми опрацюванн€ р≥зних контейнер≥в.
   ¬каз≥вники в масив≥ та "≥тератори" у списку приховують внутр≥шнЇ влаштуванн€ контейнер≥в.
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

// ц€ функц≥€ дуже схожа до PrintMas, але вказ≥вник на вузол мусить знати про його структуру
void PrintList(Node* start, Node* end)
{
	for (Node* ptr = start; ptr != end; ptr = ptr->next)
	{
		cout << '\t' << ptr->data;
	}
	cout << '\n';
}
// використанн€ "≥тератора" повн≥стю маскуЇ структуру списку. ‘ункц≥€ ≥дентична до FindValInMas
Iter FindValInList(ValueType x, Iter start, Iter end)
{
	while (start != end && *start != x) ++start;
	return start;
}