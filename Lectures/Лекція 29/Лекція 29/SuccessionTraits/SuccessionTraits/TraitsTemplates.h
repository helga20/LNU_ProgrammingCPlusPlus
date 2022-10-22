#pragma once

#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <set>
#include <memory>
#include <iostream>

using std::cout;

// характеристики контейнерних КЛАСІВ, часткова спеціалізація для конкретних класів
template <class T, class Succession> class SuccessionTraits;
/* тут Succession - довільний клас: можливо, шаблонний, а може й ні
       Т - тип даних, які зберігаються в контейнері, він нам буде потрібний у спеціалізаціях
   сам шаблон - порожній, оскільки слугує основою для сім'ї шаблонів-спеціалізацій */

// клас характеристик вектора, часткова спеціалізація для Succession = std::vector<T>
// параметр Т залишається вільним, оскільки спеціалізація стосується всіх векторів
template <class T> class SuccessionTraits<T, std::vector<T>>
{
public:
	static const char * GetTitle() { return " * Vector *"; }
};
// повна спеціалізація для вектора значень цілого типу
template <> class SuccessionTraits<int, std::vector<int>>
{
public:
	static const char * GetTitle() { return " * Vector of Integers *"; }
};

// клас характеристик списка, часткова спеціалізація для Succession = std::list<T>
template <class T> class SuccessionTraits<T, std::list<T>>
{
public:
	static const char * GetTitle() { return " * List *"; }
};

// клас характеристик дека, часткова спеціалізація для Succession = std::deque<T>
template <class T> class SuccessionTraits<T, std::deque<T>>
{
public:
	static const char * GetTitle() { return " * Deque *"; }
};

// клас характеристик множини, часткова спеціалізація для Succession = std::set<T>
template <class T> class SuccessionTraits<T, std::set<T>>
{
public:
	static const char * GetTitle() { return " -*- Set -*-"; }
};

// єдиний аргумент функції не залежить від Т, тому його потрібно вказувати при виклику
template <class T, class Succession, class Traits = SuccessionTraits<T, Succession> >
void PrintSuccession(const Succession& S)
{
	typename Succession::const_iterator it = S.cbegin();
	cout << Traits::GetTitle() << '\n';
	while (it != S.cend())
	{
		cout.width(8);
		cout << *it++;
	}
	cout << '\n';
}

//----------------------------------------------------------

// характеристики ШАБЛОНІВ контейнерних класів
template <template <class T, class Allocator = std::allocator<T>> class Succession> class SuccTraits;
/* зручніший у використанні, бо тепер Т стає частиною оголошення контейнера
   але підходить не для всіх контейнерів, а лише для тих, чиї шаблони мають
   відповідний набір параметрів
*/
// спеціалізації для шаблонів стандартних послідовних контейнерів
template <> class SuccTraits<std::vector>
{
public:
	static const char * GetTitle() { return " +++ VECTOR +++"; }
	static const char leftBound = '[';
	static const char rightBound = ']';
};
template <> class SuccTraits<std::list>
{
public:
	static const char * GetTitle() { return " +++ DOUBLE-LINKED LIST +++"; }
	static const char leftBound = '<';
	static const char rightBound = '>';
};
template <> class SuccTraits<std::deque>
{
public:
	static const char * GetTitle() { return " +++ DEQUE +++"; }
	static const char leftBound = '\\';
	static const char rightBound = '/';
};
template <> class SuccTraits<std::forward_list>
{
public:
	static const char * GetTitle() { return " +++ SINGLE-LINKED LIST +++"; }
	static const char leftBound = '|';
	static const char rightBound = '|';
};
template <class E, template <class T, class Allocator = std::allocator<T>> class Succession, class Traits = SuccTraits<Succession> >
void PrintSucc(const Succession<E>& S)
{
	typename Succession<E>::const_iterator it = S.cbegin();
	cout << Traits::GetTitle() << '\n';
	if (S.empty())
	{
		cout << Traits::leftBound << " empty " << Traits::rightBound << '\n';
		return;
	}
	while (it != S.cend())
	{
		cout << Traits::leftBound << *it++ << Traits::rightBound << ' ';
	}
	cout << '\n';
}
