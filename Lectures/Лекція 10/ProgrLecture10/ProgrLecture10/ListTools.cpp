#include "ListTools.h"
#include <iostream>
using std::cin;
using std::cout;

namespace ListTools
{
	List_t readList()
	{
		// кожне прочитане число дописується в кінець списку
		List_t L = nullptr;
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		cin >> x;
		// перша ланка особлива, бо на неї вказує голова списку
		// її створюємо окремо
		L = new Node(x);
		// допоміжний вказівник на останню ланку
		Node* p = L;
		// цикл для решти чисел і ланок
		while (cin >> x)
		{
			p->link = new Node(x);
			p = p->link;
		}
		// відновлення стану потоку введення
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}

	void writeList(List_t L)
	{
		if (L == nullptr)
		{
			cout << "The list is empty\n";
			return;
		}
		// локальна змінна L перебере всі ланки списку
		while (L != nullptr)
		{
			cout << '\t' << L->value;
			L = L->link;
		}
		cout << '\n';
	}
	List_t shortList()
	{
		// "примітивний" список з трьох ланок
		return new Node(32, new Node(45, new Node(95)));
	}
	List_t reverseReadList()
	{
		// кожне число вставляється на початок списку
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		List_t L = nullptr;
		while (cin >> x)
		{
			L = new Node(x, L);
		}
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}
	// рекурсивна процедура завантаження чисел в оберненому порядку до списку
	// для правильної роботи перед викликом L = nullptr;
	void recursiveReadList(List_t& L)
	{
		int x;
		if (cin >> x) L = new Node(x, L);
		else
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			return;
		}
	}

	int delFirst(List_t& L)
	{
		// вилучає зі списку першу ланку, повертає значення, яке в ній зберігалося
		int x = L->value;
		Node* victim = L;
		L = L->link;
		delete victim;
		return x;
	}
	void removeList(List_t& List)
	{
		// вилучає з динамічної пам'яті весь список
		while (List != nullptr)
			delFirst(List);
	}
	List_t readSortedList()
	{
		// створення заголовної ланки
		List_t L = new Node(0);
		// цикл введення даних
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		while (cin >> x)
		{
			// пошук місця вставки
			Node* place = L;
			while (place->link != nullptr && place->link->value < x) place = place->link;
			// вставка нового елемента
			place->link = new Node(x, place->link);
		}
		// вилучення заголовної ланки
		delFirst(L);
		// відновлення і очишення потоку введення
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}
	List_t readSortedLst()
	{
		// ланка - голова списку
		Node L(0);
		// цикл введення даних
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		while (cin >> x)
		{
			// пошук місця вставки
			Node* place = &L;
			while (place->link != nullptr && place->link->value < x) place = place->link;
			// вставка нового елемента
			place->link = new Node(x, place->link);
		}
		// відновлення і очишення потоку введення
		cin.clear();
		while (cin.get() != '\n') continue;
		return L.link;
	}

	List_t merge(List_t a, List_t b)
	{
		// допоміжна ланка, щоб перша ланка результату не була "особливою"
		Node phantom(0);
		List_t r = &phantom;
		while (a != nullptr && b != nullptr)
		{
			// до результуючого списку першим проходить менший
			if (a->value < b->value)
			{
				r->link = new Node(a->value);
				a = a->link;
			}
			else
			{
				r->link = new Node(b->value);
				b = b->link;
			}
			r = r->link;
		}
		// дописуємо "хвости"
		while (a != nullptr)
		{
			r->link = new Node(a->value);
			a = a->link;
			r = r->link;
		}
		while (b != nullptr)
		{
			r->link = new Node(b->value);
			b = b->link;
			r = r->link;
		}
		return phantom.link;
	}
}

void ListTools::insert(int x, List_t& L)
{
	Node phantom(0, L);
	// перед першою ланкою списку з’явилася ще одна
	// тепер шукатимемо місце незалежно від того, чи ланка перша чи ні 
	List_t place = &phantom;
	// поки є ланка попереду і значення в ній замале
	while (place->link != nullptr && place->link->value < x)
		// йдемо до наступної ланки
		place = place->link;
	// вставка нового елемента
	place->link = new Node(x, place->link);
	place = nullptr;
	L = phantom.link;
}
