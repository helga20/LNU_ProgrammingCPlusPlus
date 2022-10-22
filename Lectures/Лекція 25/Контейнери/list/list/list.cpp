#include <iostream>
#include <algorithm>
#include "Windows.h"
#include <list>
#include <functional>
using namespace std;

void print(list<int>& List);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 11;
	int i;

	// створюю список
	list<int>List;
	list<int>::iterator where;

	// заповнюю список push_back()
	for (i = 0; i < size; i++) List.push_back(i);
	// заповнюю список push_front()
	for (i = 0; i < size; i++) List.push_front(100 - i);
	// виводжу список на екран
	cout << "Вихідний список: \n";
	print(List);
	system("pause");
	cout << "\n";

	// знаходжу й видаляю зі списку число 11
	where = find(List.begin(), List.end(), 10);
	if (where != List.end()) List.erase(where);
	else cout << "Такого числа в списку не існує :( \n";
	cout << "Після видалення числа 10: \n";
	print(List);
	system("pause");
	cout << "\n";

	// видаляю число з початку списку
	if (!List.empty())List.pop_front();
	cout << "Після видалення числа з початку списку\n";
	print(List);
	system("pause");
	cout << "\n";

	// видаляю число з кінця списку
	if (!List.empty())List.pop_back();
	cout << "Після видалення числа з кінця списку\n";
	print(List);
	system("pause");
	cout << "\n";

	// видаляю всі числа, не рівні 3
	List.remove_if(bind2nd(not_equal_to<int>(), 3));
	cout << "Після видалення всіх чисел, не рівних 3\n";
	print(List);
	system("pause");
	cout << "\n";

	// виводжу зарезервований розмір списку
	int ListMaxSize = List.max_size();
	cout << "Максимальний розмір списку: " << ListMaxSize << endl;
	// виводжу розмір списку
	int ListSize = List.size();
	cout << "Розмір списку: " << ListSize << endl;
	// виводжу ємність списку
	int ListCapacity = List.size();
	cout << "Ємність списку: " << ListCapacity << endl;
	system("pause");
	cout << "\n";

	// вставляю в початок списку 6 вісімок
	List.insert(List.begin(), 6, 8);
	cout << "Після вставки шести вісімок у початок списку\n";
	print(List);
	system("pause");
	cout << "\n";

	// сортування списку
	List.sort();
	cout << "Після сортування: \n";
	print(List);
	system("pause");
	cout << "\n";

	// видаляю останній елемент
	cout << "Після видалення останнього елемента\n";
	List.pop_back();
	print(List);
	system("pause");
	cout << "\n";

	// створюю новий список, копіюю в нього вміст списку List
	list<int>newList(List.begin(), List.end());
	cout << "Новий список: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// заповнюю новий список 5
	newList.insert(newList.begin(), newList.size(), 5);
	cout << "Після заповнення нового списку п'ятірками\n";
	print(newList);
	system("pause");
	cout << "\n";

	// дописую в новий список вміст списку List
	newList.assign(List.begin(), List.end());
	cout << "Після присвоєння списку List: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// стираю новий список
	newList.clear();
	cout << "Спроба вивести порожній список\n";
	print(newList);
	system("pause");
	cout << "\n";

	// дублікати
	for (i = 0; i < size; i++)
	{
		if (i < 5) newList.push_back(40); else newList.push_back(50);
	}
	cout << "Список з дублікатами: \n";
	print(newList);
	newList.unique();
	cout << "Список без дублікатів: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// об'єднання списків
	newList.merge(List);
	cout << "Після об'єднання списків: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// Порівняння списків
	if (List == newList) cout << "Список == Новий список\n";
	if (List > newList) cout << "Список > Новий список\n";
	if (List >= newList) cout << "Список >= Новий список\n";
	if (List < newList) cout << "Список < Новий список\n";
	if (List <= newList) cout << "Список <= Новий список\n";

	system("pause");
	return 0;
}
void print(list<int>& List)
{
	if (List.empty())
	{
		cout << "\nСписок порожній\n";
		return;
	}

	list<int>::iterator iter;
	for (iter = List.begin(); iter != List.end(); iter++)
		cout << " " << *iter;
	cout << "\n";
}