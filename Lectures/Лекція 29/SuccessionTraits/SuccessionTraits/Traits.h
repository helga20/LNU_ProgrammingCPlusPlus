#pragma once
#include <vector>
#include <iostream>
using std::cout;
// "ієрархія" класів характеристик
template <class Container> class ContainerTraits;
// конкретизацій для вектора - декілька: для кожного типу елементів
template <> class ContainerTraits<std::vector<int>>
{
public:
	static const char * GetTitle() { return " * Vector of Integers *"; }
};
template <> class ContainerTraits<std::vector<double>>
{
public:
	static const char * GetTitle() { return " * Vector of Reals *"; }
};
// шаблон функції працює з нешаблонним типом контейнера
template <class Container, class Traits = ContainerTraits<Container>>
void PrintContainer(const Container& S)
{
	typename Container::const_iterator it = S.cbegin();
	cout << Traits::GetTitle() << '\n';
	while (it != S.cend())
	{
		cout.width(8);
		cout << *it++;
	}
	cout << '\n';
}
