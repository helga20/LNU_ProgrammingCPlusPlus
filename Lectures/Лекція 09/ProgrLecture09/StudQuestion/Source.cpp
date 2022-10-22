#include "Header.h"

std::ostream& operator<<(std::ostream& os, const data& L)
{
	os << '[' << L.num << ',' << L.letter << ',' << L.point << ']';
	return os;
}

node* find(node* L, predicate f)
{
	while (L != nullptr && !f(L)) L = L->link;
	return L;
}

node* find_f(node* L, std::function<bool(node*)> f)
{
	while (L != nullptr && !f(L)) L = L->link;
	return L;
}

void show(node* p)
{
	if (p != nullptr) std::cout << "found " << p->val << '\n';
	else std::cout << "not found\n";
}