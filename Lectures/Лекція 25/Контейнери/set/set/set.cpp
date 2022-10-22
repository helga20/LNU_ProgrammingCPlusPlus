#include <iostream>
#include <set>
#include <Windows.h>
using namespace std;

void print(set<int, less<int> >& Set);
void reverse_print(set<int, less<int> >& Set);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 5;
	int i;

	set<int, less<int> >::iterator where, newWhere;

	// створюю множини
	set<int, less<int> > Set, newSet;
	// заповнюю множини insert()
	for (i = 0; i < size; i++)
	{
		Set.insert(i);
		newSet.insert(i + 1);
	}
	cout << "Множина\n";
	print(Set);
	cout << "Нова множина\n";
	print(newSet);
	system("pause");
	cout << "\n";

	// виводжу множини у зворотному порядку
	cout << "Множина у зворотному порядку\n";
	reverse_print(Set);
	cout << "Нова множинаt у зворотному порядку\n";
	reverse_print(newSet);
	system("pause");
	cout << "\n";

	// виводжу розміри множин
	int SetSize = Set.size();
	cout << "Розмір множини: " << SetSize << endl;
	SetSize = newSet.size();
	cout << "Розмір нової множини: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// виводжу максимальні розміри множин
	SetSize = Set.max_size();
	cout << "Максимальний розмір множини: " << SetSize << endl;
	SetSize = newSet.max_size();
	cout << "Максимальний розмір нової множини: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// виводжу кількість трійок
	SetSize = Set.count(3);
	cout << "Кількість трійок у множини: " << SetSize << endl;
	SetSize = newSet.count(5);
	cout << "Кількість трійок у новій множини: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// шукаю й видаляю трійку в множиниі
	where = Set.find(3);
	Set.erase(where);
	cout << "Множина після видалення трійки: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// видаляю два останніх елементи множини 
	where = Set.find(2);
	Set.erase(where, Set.end());
	cout << "Множина після видалення двох останніх елементів: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// очищаю множину clear()
	Set.clear();
	cout << "Спроба вивести порожню множину\n";
	print(Set);
	system("pause");
	cout << "\n";

	// заповнюю множину insert().
	for (i = 0; i < size; i++)
	{
		if (i < 2) Set.insert(5); else Set.insert(10);
	}
	cout << "Нова множина: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// перестановка множин
	swap(Set, newSet);
	cout << "Множина після перестановки\n";
	print(Set);
	cout << "Нова множина після перестановки\n";
	print(newSet);
	system("pause");
	cout << "\n";

	// порівняння множин
	if (Set == newSet) cout << "Множина == Нова множина\n";
	if (Set > newSet) cout << "Множина > Нова множина\n";
	if (Set >= newSet) cout << "Множина >= Нова множина\n";
	if (Set < newSet) cout << "Множина < Нова множина\n";
	if (Set <= newSet) cout << "Множина <= Нова множина\n";

	system("pause");
	return 0;
}
void print(set<int, less<int> >& Set)
{
	if (Set.empty())
	{
		cout << "Множина порожня\n";	return;
	}
	set<int, less<int> >::iterator i;
	for (i = Set.begin(); i != Set.end(); i++)
	cout << " " << *i;
	cout << "\n";
}
void reverse_print(set<int, less<int> >& Set)
{
	if (Set.empty())
	{
		cout << "Множина порожня\n";	return;
	}
	set<int, less<int> >::reverse_iterator i;
	for (i = Set.rbegin(); i != Set.rend(); i++)
	cout << " " << *i;
	cout << "\n";
}