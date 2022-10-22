// Оголошення для доступу до математичних констант
// ВАЖЛИВО: define має бути в ПЕРШОМУ рядку!
#define _USE_MATH_DEFINES 
#include <cmath>

#include <iostream>
using namespace std;

int main()
{
	/* Задано два різні цілі числа.
	   Надрукувати значення більшого з них (не використовуючи інструкцію if)
	*/
	cout << "Input two different integers: ";
	int s, t;
	cin >> s >> t;
	int m = s > t ? s : t;
	cout << "max(" << s << ',' << t << ")=" << m << endl;
	system("pause");

	/* Задано натуральне чотирицифрове число.
	   Чи є воно паліндромом?
	   Паліндром читається однаково зліва направо і справа наліво.
	*/
	cout << "Input a four-digit number: ";
	int k;
	cin >> k;
	int left = k / 100;  // виділення двох старших цифр
	int right = k % 100; // виділення двох молодших цифр
	cout << (left / 10 == right % 10 && left % 10 == right / 10 ? "Yes! It is a polindrome.\n" : "NO, it is not.\n");
	system("pause");

	/* Задано довжини катетів прямокутного трикутника.
	   Обчислити його площу, периметр, радіуси вписаного та описаного кіл, величини гострих кутів у градусах.
	*/
	cout << "Input legs of the right triangle: ";
	double a, b;
	cin >> a >> b;
	// Площа
	double S = a*b*0.5;
	// гіпотенуза потрібн адля обчислень периметра і радіусів
	double c = sqrt(a*a + b*b);
	// Периметр
	double P = a + b + c;
	// Радіус описаного кола
	double R = c*0.5;
	// Радіус вписаного кола
	double r = (a + b - c) / 2.;
	// Величини кострих кутів
	double alpha = atan(a / c) / M_PI * 180;
	double betha = 90 - alpha;
	cout << "All about the " << a << " x " << b << " right triangle:\n"
		<< " S = " << '\t' << S << "\n P = " << '\t' << P
		<< "\n R = " << '\t' << R << "\n r = " << '\t' << r << '\n';
	cout << "The anles are (in degree): " << alpha << " and " << betha << '\n';
	system("pause");
	return 0;
}