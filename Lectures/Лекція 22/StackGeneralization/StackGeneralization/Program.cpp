#include <iostream>
#include "stack.h"
#include "stackPtn.h"
#include "stackAPtn.h"
#include "stackDPtn.h"

using std::cin;
using std::cout;


int main()
{
	const int n = 4;
	Item A[n] = { 4, 25, 39, 478 };
	stack s;
	cout << " --- Source data:\n";
	for (int i = 0; i < n; ++i)
	{
		s.push(A[i]);
		std::cout << '\t' << A[i];
	}
	cout << '\n';
	cout << " --- Data from the stack:\n";
	while (!s.isEmpty()) cout << '\t' << s.pop();
	cout << '\n';
	system("pause");

	/*
	ЗАДАЧА. Задано послідовність цілих чисел.
	Надрукуйте спочатку всі недодатні у зворотньому порядку,
	а потім - всі додатні, збільшені в два з половино рази.
	ПОЯСНЕННЯ. Для обертання порядку чисел використаємо два стеки:
	стек цілих для всієї послідовності і стек дійсних для додатніх.
	Стеки оголосимо з використанням шаблона.
	*/

	// У всіх трьох випадках введення чисел відбувається до заповнення стека
	//стеки фіксованого розміру 
	Stack<int> numb;
	Stack<double> posit;
	int x;
	while (!numb.isFull())
	{
		cout << " ? x: "; cin >> x;
		numb.push(x);
	}
	cout << " Not positive numbers are:\n";
	while (!numb.isEmpty())
	{
		x = numb.pop();
		if (x > 0) posit.push(2.5*x);
		else cout << '\t' << x;
	}
	cout << '\n';
	if (!posit.isEmpty()) cout << " Positives * 2.5 are:\n";
	while (!posit.isEmpty()) cout << '\t' << posit.pop();
	cout << '\n';
	system("pause");

	//стеки з динамічним масивом	
	DStack<int> Numbers(5);
	//розмір стека дійсних чисел можна обчислити
	int count = 0;
	do
	{
		cout << " ? x: "; cin >> x;
		if (x > 0) count++;
	} while (Numbers.push(x));
	DStack<double> Positives(count);
	cout << x << " is the terminal number!\n"
		<< "      other numbers:\n";
	while (Numbers.pop(x))
	{
		if (x > 0) Positives.push(2.5*x);
		else cout << x << '\t';
	}
	cout << '\n';
	double a;
	if (!Positives.isEmpty()) cout << "     positives*2.5:\n";
	while (Positives.pop(a)) cout << a << '\t';
	cout << '\n';
	system("pause");

	//стеки заданого розміру
	AStack<int, 7> all;
	AStack<double, 7> plus;
	do
	{
		cout << " ? x: "; cin >> x;
	} while (all.push(x));
	cout << x << " is the terminal number!\n"
		<< "      other numbers:\n";
	while (all.pop(x))
	{
		if (x > 0) plus.push(2.5*x);
		else cout << x << '\t';
	}
	cout << '\n';
	if (!plus.isEmpty()) cout << "     positives*2.5:\n";
	while (plus.pop(a)) cout << a << '\t';
	cout << '\n';
	system("pause");
	return 0;
}