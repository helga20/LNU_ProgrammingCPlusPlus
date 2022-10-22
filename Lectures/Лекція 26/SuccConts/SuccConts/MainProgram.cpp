#include <iostream>
#include <windows.h>
#include "noisy.h"
#include "Tools.h"

// визначення статичних змінних
long Noisy::create = 0, Noisy::assign = 0,
Noisy::copy = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

int quit()
{
	cout << "\nBye!\n";
	return 0;
}

int main()
{
	SetConsoleOutputCP(1251);
	typedef int(*act)(void); // using act = int(); не дозволить оголосити масив
	act proc[] = { use_basicOps, use_algos, test_Noisy, use_Inserters, compare, quit };
	const int n = sizeof proc / sizeof *proc;
	int choice = 0;
	while (choice < n - 1)
	{
		cout << "Оберіть процедуру для виконання:"
			<< "\n  0 - Базові операції з послідовними контейнерами"
			<< "\n  1 - Алгоритми над послідовними контейнерами"
			<< "\n  2 - Випробування тестових об'єктів Noisy"
			<< "\n  3 - Вставляння в послідовні контейнери"
			<< "\n  4 - Порівняння швидкодії вектора і дека"
			<< "\n  5 - Вихід\n >>> ";
		cin >> choice; cin.get();
		system("cls");
		proc[choice]();
	}
	cout << "\nClean up!\n";
	return 0;
}