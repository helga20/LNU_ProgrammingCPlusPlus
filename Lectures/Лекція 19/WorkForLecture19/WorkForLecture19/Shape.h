#pragma once

#define _USE_MATH_DEFINES
#include <iostream>

/*Завдання. Оголосіть ієрархію класів, що моделюють сутності
  «прямокутник», «квадрат», «круг», «трикутник».
  Усі фігури повідомляють свої площу і периметр,
  вміють будувати своє зображення рядком літер.*/

class FlatShape abstract
{
public:
	virtual double area() const abstract;
	virtual double perim() const abstract;
	virtual void printOn(std::ostream& os) const abstract;

	bool operator>(const FlatShape& other) const
	{
		return this->area() > other.area();
	}
};
class Rect: public FlatShape
{
protected:
	double a, b;
	double s;
	void calculateArea() { s = a * b; }
public:
	Rect() :a(3), b(4) { calculateArea(); }
	Rect(double x, double y) 
	{
		a = (x > 0.01) ? x : 0.01;
		b = (x > 0.01) ? x : 0.01;
		calculateArea();
	}
	void setA(double x)
	{
		a = (x > 0.01) ? x : 0.01;
		calculateArea();
	}
	void setB(double x)
	{
		b = (x > 0.01) ? x : 0.01;
		calculateArea();
	}

	double area() const override { return s; }
	double perim() const override { return 2 * (a + b); }
	virtual void printOn(std::ostream& os) const override;
	virtual ~Rect() {}
};

class Square :public Rect
{
public:
	Square(double x) : Rect(x, x){}
	virtual void printOn(std::ostream& os) const override;
};

class Circle : public FlatShape
{
private:
	double r;
public:
	Circle(double x = 1.0) :r(x) {}
	virtual double area() const override;
	double length() const;
	virtual double perim() const override { return this->length(); }
	virtual void printOn(std::ostream& os) const override;
};

std::ostream& operator<<(std::ostream& os, const FlatShape& R);

/*
Rect T = aSquare;  //перетворення типу
Rect& R = aSquare; //поліморфне посилання
Rect* P = &aSquare;//поліморфний вказівник
*/
