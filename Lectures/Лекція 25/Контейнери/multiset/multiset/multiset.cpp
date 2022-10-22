#include <iostream>
#include <set>
#include <Windows.h>
using namespace std;

void print(multiset<int, less<int> >& Multiset);
void reverse_print(multiset<int, less<int> >& Multiset);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 5;
	int i;

	multiset<int, less<int> >::iterator where, newWhere;
	// створюю множини
	multiset<int, less<int> > Multiset, newMultiset;
	// заповнюю множини insert()
	for (i = 0; i < size; i++)
	{
		Multiset.insert(i);
		newMultiset.insert(i + 1);
	}
	cout<< "Множина: \n";
	print(Multiset);
	cout << "Нова множина: \n";
	print(newMultiset);
	system("pause");
	cout << "\n";

	// виводжу множини у зворотному порядку
	cout << "Множина у зворотному порядку: \n";
	reverse_print(Multiset);
	cout << "Нова множина у зворотному порядку: \n";
	reverse_print(newMultiset);
	system("pause");
	cout << "\n";

	// виводжу розміри множин
	int MultisetSize = Multiset.size();
	cout << "Розмір множини: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.size();
	cout << "Розмір нової множини: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// виводжу максимальні розміри множин
	MultisetSize = Multiset.max_size();
	cout << "Максимальний розмір множини: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.max_size();
	cout << "Максимальний розмір нової множини: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// виводжу кількість трійок
	MultisetSize = Multiset.count(3);
	cout << "Кількість трійок у множині: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.count(3);
	cout << "Кількість трійок у новій множини: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// шукаю й видаляю трійку в множині
	where = Multiset.find(3);
	Multiset.erase(where);
	cout << "Множина після видалення трійки: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// видаляю два останні елементи множини
	where = Multiset.find(2);
	Multiset.erase(where, Multiset.end());
	cout << "Множина після видалення двох останніх елементів: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// "чищу" множину clear()
	Multiset.clear();
	cout << "Спроба вивести порожню множина\n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// заповнюю множину insert()
	for (i = 0; i < size; i++)
	{
		if (i < 2) Multiset.insert(5); else Multiset.insert(10);
	}
	cout << "Нова множина: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// перестановка множин
	swap(Multiset, newMultiset);
	cout << "Множина після перестановки: \n";
	print(Multiset);
	cout << "Нова множина після перестановки: \n";
	print(newMultiset);
	system("pause");
	cout << "\n";

	// діапазон, що складається з десяток
	cout << "Діапазон, що складається з десяток: \n";
	for (where = newMultiset.lower_bound(10);
		where != newMultiset.end();
		where++)
		cout << " " << *where;
		cout << "\n";
	system("pause");
	cout << "\n";

	// діапазон, що складається з п'ятірок
	cout << "Діапазон, що складається з п'ятірок: \n";
	for (where = newMultiset.begin();
		where != newMultiset.upper_bound(5);
		where++)
		cout << " " << *where;
		cout << "\n";
	system("pause");
	cout << "\n";

	// порівняння множин
	if (Multiset == newMultiset) cout << "Множина == Нова множина\n";
	if (Multiset > newMultiset) cout << "Множина > Нова множина\n";
	if (Multiset >= newMultiset) cout << "Множина >= Нова множина\n";
	if (Multiset < newMultiset) cout << "Множина < Нова множина\n";
	if (Multiset <= newMultiset) cout << "Множина <= Нова множина\n";

	system("pause");
	return 0;
}

void print(multiset<int, less<int> >& Multiset)
{
	if (Multiset.empty())
	{
		cout << "Множина порожня\n";	return;
	}
	multiset<int, less<int> >::iterator i;
	for (i = Multiset.begin(); i != Multiset.end(); i++)
	cout << " " << *i;
	cout << "\n";
}
void reverse_print(multiset<int, less<int> >& Multiset)
{
	if (Multiset.empty())
	{
		cout << "Множина порожня\n";	return;
	}
	multiset<int, less<int> >::reverse_iterator i;
	for (i = Multiset.rbegin(); i != Multiset.rend(); i++)
	cout << " " << *i;
	cout << "\n";
}