#ifndef _TIME_H_1
#define _TIME_H_1

#include <iostream>
using std::cout;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();		// **конструктор за замовчуванням - спробуйте використати список ініціалізації
	Time(int h, int m);		// **конструктор з параметрами
	Time(const Time& t);	// **конструктор копіювання
	Time& operator=(const Time&);	// оператор присвоєння у парі з конструктором копіювання
	Time& AddMin(int m);		// методи міняють значення полів отримувача - випробуйте їхню дію
	Time& AddHr(int h);
	void Reset(int h = 0, int m = 0);//***
	Time Sum(const Time& t) const;	// додавання можна виконувати звичайним методом
	Time operator+(const Time & t) const;	// або оператором
	bool operator>(const Time& t) const;	// об'єкти можна порівнювати
	Time operator*(double n) const;	// час можна множити на число і ...
	
	void Show(std::ostream&) const;		// **об'єкт вміє себе друкувати в потік
	// Навчити потік друкувати об'єкт допоможе звичайна функція.
	// Якщо їй потрібен доступ до полів (див. реалізацію), функцію можна оголосити дружньою
	friend std::ostream & operator<<(std::ostream & os, const Time & t);

	// взаємні перетворення час - число
	Time (int t);			// **конструктор з одним параметром перетворює int на Time
	operator int() const;	// спеціальний оператор перетворення Time на int
};

Time operator*(double n, const Time & t); // ... число множити на час

#endif