#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include "noisy.h"
#include "Tools.h"
using namespace std;

const int n = 7;

// Алгоритм copy(sourceStart, sourceEnd, destinationStart) використовують
// для копіювання діапазонів. Щоб він правильно спрацював з контейнером
// змінного розміру в якості приймача даних, потрібно використовувати
// ітератори вставляння.
// Наступні шаблони демонструють застосування ітераторів вставляння до
// послідовних контейнерів

// Дописування в кінець послідовного контейнера
template<class Cont>
void backInsertion(Noisy* a, Cont& ci, char* name)
{
	cout<<"\n*** BI *** Дописування в кінець "<<name<<" \n";
	//copy(a, a + n, back_inserter(ci));  // можна використати замість циклу
	for (typename Cont::value_type * p = a; p != a + n; ++p)
	{
		ci.push_back(*p);
		cout << "  .................\n";
	}
	cout<<"\nОтримали:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout<<'\n'; cin.get();
}
// Створення в кінці контейнера як альтернатива вставлянню в кінець контейнера
template<class Cont>
void backEmplacing(Noisy* a, Cont& ci, char* name)
{
	cout << "\n*** BE *** Створення в кінці " << name << " \n";
	cout << " = з масива\n";
	for (int i = 0; i < 3; ++i)
	{
		ci.emplace_back(a[i]);
		cout << "  .................\n";
	}
	cout << " = за замовчуванням\n";
	for (int i = 3; i < n; ++i)
	{
		ci.emplace_back();
		cout << "  .................\n";
	}
	cout << " = з одним параметром\n";
	for (int i = 1; i < 4; ++i)
	{
		ci.emplace_back(i + 100);
		cout << "  .................\n";
	}
	cout << " = з двома параметрами\n";
	for (int i = 2; i < 5; ++i)
	{
		ci.emplace_back(i, 7);
		cout << "  .................\n";
	}
	cout << "\nОтримали:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

// Вставляння всередину. Позиція вставляння вибрана довільно.
template<class Cont>
void midInsertion(Noisy* a, Cont& ci, char* name)
{
	typename Cont::iterator it = ci.begin();
	++it; ++it; ++it;
	cout << "\n*** MI *** Вставляння всередину " << name << " (після третього)\n";
	copy(a, a + n / 2, inserter(ci, it));
	cout << "\nОтримали:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

// Вставляння на початок контейнера звичайне для list, deque
template<class Cont>
void frontInsertion(Noisy* a, Cont& ci, char* name)
{
	cout << "\n*** FI *** Вставляння на початок " << name << " \n";
	copy(a, a + n, front_inserter(ci));
	cout << "\nОтримали:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}
// vector не має методу вставляння на початок, тому для нього пишемо
// явну спеціалізацію шаблона
template<>
void frontInsertion<vector<Noisy>>(Noisy* a, vector<Noisy>& ci, char* name)
{
	cout << "\n*** FI *** Вставляння на початок " << name << " \n";
	copy(a, a + n, inserter(ci, ci.begin()));
	cout << "\nОтримали:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename vector<Noisy>::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

int use_Inserters()
{
	// Джерело даних для наповнення контейнерів
	Noisy a[n];

	cout<<"\nСтворюємо порожні контейнери\n";
	deque<Noisy> di;
	list<Noisy> li;
	vector<Noisy> vi, A, B;
	A.reserve(5); B.reserve(5);
	cin.get();

	cout << "\n~~~ Порівняння push_back і emplace_back\n\n";
	A.push_back(Noisy());
	B.emplace_back();
	cout << "  .................\n";
	A.push_back(Noisy(17));
	B.emplace_back(17);
	cout << "  .................\n";
	A.push_back(Noisy(5, 5));
	B.emplace_back(5, 5);
	cout << "  .................\n";
	cin.get();

	cout << "\n+++ Дописування в кінець контейнера\n\n";
	backInsertion(a, vi, "VECTOR");
	backInsertion(a, di, "DEQUE");
	backInsertion(a, li, "LIST");

	cout << "\n--- Очищення контейнерів\n\n";
	vi.clear(); vi.shrink_to_fit(); cin.get();
	di.clear(); di.shrink_to_fit(); cin.get();
	li.clear(); cin.get();

	cout << "\n+++ Створення в кінці контейнера\n\n";
	backEmplacing(a, vi, "VECTOR");
	backEmplacing(a, di, "DEQUE");
	backEmplacing(a, li, "LIST");

	cout << "\n--- Очищення контейнерів\n\n";
	vi.clear(); vi.shrink_to_fit(); cin.get();
	di.clear(); di.shrink_to_fit(); cin.get();
	li.clear(); cin.get();

	cout << "\n+++ Вставляння на початок контейнера\n\n";
	frontInsertion(a, vi, "VECTOR");
	frontInsertion(a, di, "DEQUE");
	frontInsertion(a, li, "LIST");

	cout << "\n+++ Вставляння в середину контейнера\n\n";
	midInsertion(a, vi, "VECTOR");
	midInsertion(a, di, "DEQUE");
	midInsertion(a, li, "LIST");

	return 0;
}

/*
23 19 17 13 11 7 5 3 1
23 19 17 13 11 7 5 3 1
1 3 5 7 11 13 17 19 23
1 3 5 7 11 13 17 19 23
1 3 5 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
*/
