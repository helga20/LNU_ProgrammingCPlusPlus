#pragma once
#include <iostream>
using std::ostream;

class Rectangle
{
private:
	double a, b;
	// залежне поле даних
	double s;
	// реалізація значення залежного поля
	void calculateArea() { s = a*b; }
protected:
	// доступ до поля потрібен у підкласах
	double getA() const { return a; }
public:
	Rectangle() :a(3.), b(4.) { calculateArea(); }
	Rectangle(double x, double y);
	// базовий клас майже завжди має віртуальний деструктор
	virtual ~Rectangle() {}
	// для виведення потрібен віртуальний метод
	// методи, які не змінюють стану об'єкта, роблять константними
	virtual void printOn(ostream&) const;
	double area() const { return s; }
	double perim() const { return 2.*(a + b); }
};

// Квадрат - це прямоуктник, у якого всі сторони рівні
class Square :public Rectangle
{
public:
	// саме конструктор описує рівність сторін
	Square() :Rectangle(1., 1.) {}
	Square(double x) :Rectangle(x, x) {}
	// виведення треба перевизначити
	virtual void printOn(ostream&) const;
	// обчислення площі та периметра наслідується
};

// єдиний оператор для виведення всієї ієрархії
ostream& operator<<(ostream& os, const Rectangle& R);

template <typename T>
class Show
{
	T obj;
public:
	Show(T x) :obj(x){}
	void show() const { cout << "Show : ";  obj.printOn(cout); cout << '\n'; }
};