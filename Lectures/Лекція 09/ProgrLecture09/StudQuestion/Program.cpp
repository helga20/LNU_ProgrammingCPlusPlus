#include "Header.h"

bool check_num(node* L);

int main()
{
	node * L = new node(1, 'D', 23.5, new node(2, 'A', 51.0,
		new node(3, 'F', 99.5, new node(4, 'C', 80))));
	node * p = L;
	while (p != nullptr)
	{
		std::cout << p->val << '\n';
		p = p->link;
	}
	std::cout << '\n';
	// Умову пошуку задає зовнішня функція, значення фіксоване
	show(find(L, check_num));
	// Умову пошуку задали лямбда-виразом з фіксованим значенням
	show(find(L, [](node*q){ return q->val.num == 3; }));
	// Умову задали лямбда-виразом, що використовує статичну змінну,
	// через яку можна передавати різні значення для пошуку
	static int x = 2;
	show(find(L, [](node*q){ return q->val.num == x; }));
	// Лямбда для доступу до інших полів
	show(find(L, [](node*q){ return q->val.letter == 'D'; }));
	show(find(L, [](node*q){ return q->val.point > 50.5; }));

	// Замість вказівника на функцію можна використати шаблон function
	// тоді легше використовувати лямбда-вирази
	int y = x + 2;
	show(find_f(L, [y](node*q){ return q->val.num == y; }));
	system("pause");
	return 0;
}

bool check_num(node* L)
{
	return L->val.num == 13;
}
