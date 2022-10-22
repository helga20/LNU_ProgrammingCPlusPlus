#include <iostream>

using namespace std;

int main()
{
	/* Задано послідовність чисел, що закінчується нулем.
	   Обчисліть середнє арифметичне послідовності.
	   Нуль не враховувати
	*/
	cout << " *** Task 1\n\n";
	cout << "Input a succession of numbers terminated by zero:\n";
	int a;      // член послідовності
	cin >> a;   // перший читаємо поза циклом
	int i = 0;  // кількість врахованих
	int S = 0;  // сума послідовності
	// кількість доданків наперед не відома, тому використаємо ітераційний цикл:
	// обчислення продовжуються, поки користувач вводить ненульові значення
	while (a != 0)
	{
		S += a;
		++i;
		cin >> a; // решта послідовності
	}
	if (i == 0)
	{
		cout << "The succession starts with zero.\n";
	}
	else
	{
		cout << "The average is equal to " << (double)S / i << endl;
	}
	system("pause");

	/* Задано послідовність не більше ніж п'ятдесяти чисел.
	   Знайдіть значення найбільшого з них.
	*/
	cout << "\n *** Task 2\n\n";
	const int n = 50; // Відому кількість позначимо константою
	cout << "Input up to " << n << " numbers: ";
	cin >> a;    // перший член послідовності
	int max = a; // може бути найбільшим
	int k = 1;   // кількість прочитаних
	// умова циклу містить оператор ведення!
	// якщо користувач увів число, cin перетвориться на true
	while (k <= n && cin >> a)
	{
		++k;
		if (a > max) max = a;
	}
	cout << "The maximal value among " << k << " integers is " << max << endl;
	// повертаємо потік уведення до робочого стану
	cin.clear();
	while (cin.get() != '\n') continue;
	system("pause");
	/* Задано дійсне число. Обчисліть корінь кубічний з нього за алгоритмом Ньютона.
	   Надрукуйте послідовність наближених до розв'язку значень.
	   Обчислення тривають, поки два послідовні наближення відрізняються більше ніж на 10^(-7)
	*/
	cout << "Input a number: ";
	double x;
	cin >> x;
	double r = 1.; // початкове наближення
	double p;      // p зберігає попереднє наближення
	do
	{
		p = r;
		cout << p << endl;
		r = (x / (p*p) + 2.*p) / 3.;
	} while (abs(p - r) > 1e-7);
	cout << "Cube root of " << x << " is equal to " << r << endl;
	system("pause");
	return 0;
}