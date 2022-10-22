#include <iostream>
using std::cin;
using std::cout;
#include "stackPtn.h"
#include "stackDPtn.h"
#include "stackAPtn.h"
/*
ЗАДАЧА. Задано послідовність цілих чисел.
  Надрукуйте спочатку всі недодатні у зворотньому порядку,
  а потім - всі додатні, збільшені в два з половино рази.
ПОЯСНЕННЯ. Для обертання порядку чисел використаємо два стеки:
  стек цілих для всієї послідовності і стек дійсних для додатніх.
  Стеки оголосимо з використанням шаблона.
*/

int main()
{
//стеки фіксованого розміру 
	Stack<int> numb;
	Stack<double> posit;
	int x;
	while (!numb.isFull())
	{
		cout<<" ? x: "; cin>>x;
		numb.push(x);
	}
	cout << " Not positive numbers are:\n";
	while (!numb.isEmpty())
	{
		x = numb.pop();
		if (x > 0) posit.push(2.5*x);
		else cout << '\t' << x;
	}
	cout<<'\n';
	if (!posit.isEmpty()) cout<<" Positives * 2.5 are:\n";
	while (!posit.isEmpty()) cout <<'\t' << posit.pop();
	cout<<'\n';
//стеки з динамічним масивом	
	DStack<int> stA(5);
	int count=0;
	do
	{
		cout<<" ? x: "; cin>>x;
		if (x>0) count++;
	} while (stA.push(x));
	DStack<double> stB(count);
	cout<<x<<" is the terminal number!\n"
		<<"      other numbers:\n";
	while (stA.pop(x))
		if (x>0) stB.push(2.5*x);
		else cout<<x<<'\t';
	cout<<'\n';
	double a;
	if (!stB.isEmpty()) cout<<"     positives*2.5:\n";
	while (stB.pop(a)) cout<<a<<'\t';
	cout<<'\n';
//стеки заданого розміру
	AStack<int,7> all;
	AStack<double,9> plus;
	do
	{
		cout<<" ? x: "; cin>>x;
	} while (all.push(x));
	cout<<x<<" is the terminal number!\n"
		<<"      other numbers:\n";
	while (all.pop(x))
		if (x>0) plus.push(2.5*x);
		else cout<<x<<'\t';
	cout<<'\n';
	if (!plus.isEmpty()) cout<<"     positives*2.5:\n";
	while (plus.pop(a)) cout<<a<<'\t';
	cout<<'\n';
	return 0;
}