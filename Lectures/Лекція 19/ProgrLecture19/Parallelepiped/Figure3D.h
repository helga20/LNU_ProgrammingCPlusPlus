#pragma once

#include "..\FlatShapes\FlatShapes.h"

/* Паралелепіпед містить об'єкт прямокутник і дійсне число - основу і висоту.
   Паралелепіпед не наслідує інтерфейс прямокутника, натомість він отримує
   його реалізацію для власних потреб.
*/
class Parapd
{
private:
	Rectangle base;  // тут міститимуться сторони основи паралелепіпеда
	double h;        // тут - сторона, перпендикулярна до основи
public:
	// синтаксис ініціалізатора основи в конструкторах паралелепіпеда
	// подібний до оголошення об'єкта-прямокутника, при цьому працюють
	// конструктори класу Rectangle
	Parapd() :base(), h(1.) {}
	Parapd(double a, double b, double c) :base(a, b), h(c) {}
	void printOn(ostream& os) const
	{
		os << "Parallelepiped(" << h << " x " << base << ')';
	}
	// Про площу основи паралелепіпед питає свою основу. Таку поведінку
	// називають делегуванням
	double baseArea() const { return base.area(); }
	// Інші обчислення дещо складніші. Вони також використовують функціонал основи
	double volume() const { return base.area()*h; }
	double sideArea() const { return base.perim()*h; }
	// Площа поверхні залежить від площ частин.
	double totalArea() const { return this->baseArea()*2. + this->sideArea(); }
};
ostream& operator<<(ostream& os, const Parapd& p)
{
	p.printOn(os); return os;
}