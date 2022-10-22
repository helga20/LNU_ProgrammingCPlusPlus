#pragma once

#include "FlatShapes.h"

/*Випробуємо альтернативні способи визначення об'ємних фігур. Тепер абстрактний базовий клас не містить ніяких полів даних,
  він лише задає протокол взаємодії. Плоску фігуру основу і дійсне число висоту оголосимо в підкласах, причому зробимо це
  різними способами: за допомогою включення і за допомогою закритого наслідування.*/

// --------------------- абстрактний базовий клас
class Shape3D
{
public:
	virtual ~Shape3D() {}
	static Shape3D* MakeInstance(std::ifstream&);

	virtual double baseSquare() const = 0;
	virtual double sideSquare() const = 0;
	virtual double surfaceSquare() const = 0;
	virtual double volume() const = 0;
	// виведення в потік зовнішнього вигляду об'єкта
	virtual void printOn(ostream&) const = 0;
	// зберігання об'єкта до файла у вигляді, придатному для створення
	virtual void storeOn(ofstream&) const = 0;
};

ostream& operator<<(ostream& os, const Shape3D& s);
bool operator>(const Shape3D& a, const Shape3D& b);

/* Паралелепіпед містить об'єкт прямокутник і дійсне число - основу і висоту.
   Паралелепіпед не наслідує інтерфейс прямокутника, натомість він отримує
   його реалізацію для власних потреб.
*/
class Parallelepiped : public Shape3D
{
private:
	Rectangle base;  // тут міститимуться сторони основи паралелепіпеда
	double h;        // тут - сторона, перпендикулярна до основи
public:
	// синтаксис ініціалізатора основи в конструкторах паралелепіпеда
	// подібний до оголошення об'єкта-прямокутника, при цьому працюють
	// конструктори класу Rectangle
	Parallelepiped() :base(), h(1.) {}
	Parallelepiped(double a, double b, double c) :base(a, b), h(c) {}
	virtual void printOn(ostream& os) const
	{
		os << "Parallelepiped(" << h << " x " << base << ')';
	}
	virtual void storeOn(ofstream& fout) const
	{
		fout << "Parallelepiped " << h << ' ';
		this->base.storeOn(fout);
	}

	// Про площу основи паралелепіпед питає свою основу. Таку поведінку
	// називають делегуванням
	virtual double baseSquare() const { return base.square(); }
	// Інші обчислення дещо складніші. Вони також використовують функціонал основи
	virtual double volume() const { return base.square()*h; }
	virtual double sideSquare() const { return base.perim()*h; }
	// Площа поверхні залежить від площ частин.
	virtual double surfaceSquare() const { return this->baseSquare()*2. + this->sideSquare(); }
};

/*Чотирикутна піраміда успадковує прямокутник (основу) і містить дійсне число (висоту).
  Піраміда не наслідує інтерфейс прямокутника, натомість вона отримує його реалізацію
  для власних потреб. Менше проблем з доступом до сторін прямокутника, ніж при включенні.
*/
class RectangularPyramid : private Rectangle, public Shape3D
{
private:
	double h;
public:
	// тепер основу ініціалізують конструктори надкласу, викликані, як при наслідуванні
	RectangularPyramid() : Rectangle(), h(1.) {}
	RectangularPyramid(double a, double b, double c) : Rectangle(a, b), h(c) {}
	virtual void printOn(ostream& os) const
	{
		os << "RectangularPyramid(" << h << " x ";
		Rectangle::printOn(os);
		os << ')';
	}
	virtual void storeOn(ofstream& fout) const
	{
		fout << "RectangularPyramid " << h << ' ';
		Rectangle::storeOn(fout);
	}
	// Площу основи піраміди може обчислити успадкований метод
	virtual double baseSquare() const { return this->square(); }
	// Інші обчислення дещо складніші. Вони також використовують успадкований функціонал
	virtual double volume() const { return square() * h / 3.; }
	// Площа поверхні залежить від площ частин.
	virtual double surfaceSquare() const { return this->baseSquare() + this->sideSquare(); }

	// Піраміда має безпосередній доступ до полів базового класу - прямокутника
	virtual double sideSquare() const
	{
		return a*sqrt(h*h + b*b*0.25) + b*sqrt(h*h + a*a*0.25);
	}
};