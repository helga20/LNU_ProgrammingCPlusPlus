#include <Windows.h>
#include "noisy.h"
#include "Tools.h"

int test_Noisy()
{
	cout << "Створення: конструктори за замовчуванням\n   звичайні змінні\n";
	Noisy a, b, c;
	cin.get();
	cout << "   масив\n";
	Noisy N[2];
	cin.get();
	cout << "Виведення створених об'єктів:\n"
		<< '\t' << a << '\t' << b << '\t' << c << "\n\t" << N[0] << '\t' << N[1] << '\n';
	cin.get();
	cout << "Динамічний об'єкт: ";
	Noisy * p = new Noisy();
	cin.get();
	cout << "його значення:" << *p
		<< "\nА тепер - знищення: ";
	delete p;
	cin.get();
	cout << "Створення: конструктори копіювання\n";
	Noisy f(a); Noisy g = b;
	cin.get();
	cout << "Оператор присвоєння:\n";
	N[0] = f; N[1] = b;
	cout << "\nоновлений масив\t" << N[0] << '\t' << N[1];
	cin.get();
	cout << "Створення: конструктори з параметрами\n";
	Noisy o(17), t(5, 3);
	cout << "\nстворені об'єкти\t" << o << '\t' << t << '\n';
	cin.get();
	cout << "Завершення\n";
	return 0;
}
