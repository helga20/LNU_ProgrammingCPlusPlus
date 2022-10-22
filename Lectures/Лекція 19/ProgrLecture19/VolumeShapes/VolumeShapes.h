/*
Об'ємна фігура складається з висоти і основи - плоскої фігури. Базовий
  VolShape задає протокол взаємодії: обчислення площ основи та бічної
  поверхні, об'єму, друкування фігури. Підкласи базового - PiramidalShape
  i DirectShape - визначають способи обчислення площ і об'єму відповідних
  груп об'ємних фігур: конуса і піраміди та циліндра і прямої призми. А вже
  їхні підкласи визначають створення відповідних різновидів призм, пірамід
  тощо. Окрема увага методові обчислення площі бічної поверхні в ієрархії
  PiramidalShape: кожен з підкласів перевизначає його.

Друкування об'єкта в потік - відповідальність "проміжних" класів Пряма/Конічна Фігура
 pRintOn(потік) надає зовнішнє зображення об'єкта
Зберігання об'Єкта - виведення в потік даних про об'єкт у викляді, зручному для
 наступного зчитування і створення об'єкта. Метод storeOn(потік) можна визначити
 вже в абстрактному базовому класі, заховавши попередньо у віртуальному методі
 getClassName() отримання інфи про клас екземпляра (цю роботу виконує стандартна
 функція typeid(pointer), яка не може бути віртуальною).

Статичні методи (методи класу) виконують роботу класу щодо коректного створення
 екземплярів своїх об'єктів при копіюванні за поліморфним вказівником чи при
 завантаженні з файла
*/
#ifndef _VolumeShapeHeader_
#define _VolumeShapeHeader_

#include "..\FlatShapes\FlatShapes.h"
#include <exception>

// --------------------- абстрактний базовий клас
class VolShape
{
protected:
	double h;
	Shape* base;
	string baseToStr() const { return base->toStr(); }
public:
	// клас для опису винятка, що сигналізує про неправильне задання імені класу
	class BadClassname : public std::exception
	{
	public:
		BadClassname(const char* mess) :exception(mess){};
	};
	// методи класу відповідають за копіювання та створення екземплярів
	static VolShape* CopyInstance(VolShape*);
	static VolShape* MakeInstance(std::ifstream&);

	VolShape(double high=1., Shape* s=0) : h(high), base(s) {}
	virtual ~VolShape() { delete base; }
	virtual double baseArea() const { return base->area(); }
	virtual double sideArea() const = 0;
	virtual double surfaceArea() const = 0;
	virtual double volume() const = 0;
	// виведення в потік зовнішнього вигляду об'єкта
	virtual void printOn(ostream&) const = 0;
	// зберігання об'єкта до файла у вигляді, придатному для створення
	virtual void storeOn(ofstream&) const;
	// ім'я класу потрібне для методу зберігання до файла
	virtual const char * getClassName() const { return typeid(this).name(); }
};

ostream& operator<<(ostream& os, const VolShape& s);

// --------------------- ієрархія прямих фігур
// DirectShape може виконати всю роботу. Навіть надрукувати (в загальному вигляді).
// В підкласах потрібно тільки правильно сконструювати об'єкти

class DirectShape : public VolShape
{
public:
	DirectShape(double high=1., Shape* s=0) : VolShape(high,s) {}
	virtual double sideArea() const
	{
		return base->perim() * h;
	}
	virtual double surfaceArea() const
	{
		return baseArea() * 2 + sideArea();
	}
	virtual double volume() const
	{
		return base->area() * h;
	}
	virtual void printOn(ostream&) const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

// Підкласи фіксують потрібний тип основи, створюють відповідний об'єкт
class Cylinder : public DirectShape
{
public:
	Cylinder(double high=1., double radius=1.): DirectShape(high)
	{
		base = new Circle(radius);
	}
	Cylinder(const Cylinder& c): DirectShape(c)
	{
		base = new Circle(*static_cast<Circle*>(c.base));
	}
	Cylinder& operator=(const Cylinder& c);
	virtual const char * getClassName() const { return typeid(this).name(); }
};

class Parallelepiped : public DirectShape
{
public:
	Parallelepiped(double high=1., double sideA=1., double sideB=1.): DirectShape(high)
	{
		base = new Rectangle(sideA,sideB);
	}
	Parallelepiped(const Parallelepiped& p): DirectShape(p)
	{
		base = new Rectangle(*dynamic_cast<Rectangle*>(p.base));
	}
	Parallelepiped& operator=(const Parallelepiped& p);
	virtual const char * getClassName() const { return typeid(this).name(); }
};

class TriPrizm : public DirectShape
{
public:
	TriPrizm(double high=1., double sideA=3., double sideB=4., int angle=90): DirectShape(high)
	{
		base = new Triangle(sideA,sideB,angle);
	}
	TriPrizm(const TriPrizm& t): DirectShape(t)
	{
		base = new Triangle(*dynamic_cast<Triangle*>(t.base));
	}
	TriPrizm& operator=(const TriPrizm& t);
	virtual const char * getClassName() const { return typeid(this).name(); }
};

// --------------------- ієрархія конічних фігур
// PiramidalShape може надрукувати та обчислити об'єм,
// але бічна поверхня залежить від типу фігури, тому - в підкласах.
// Як і в прямих фігурах, конструктори підкласів відповідальні за правильне створення основи.
// Але знищенням основи займається деструктор базового класу - це просто інший спосіб організації роботи

class PiramidalShape : public VolShape
{
public:
	PiramidalShape(double high=1., Shape* s=0) : VolShape(high,s) {}
	virtual double surfaceArea() const
	{
		return baseArea() + sideArea();
	}
	virtual double volume() const
	{
		return base->area() * h/3.;
	}
	virtual void printOn(ostream&) const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

class Conus : public PiramidalShape
{
public:
	Conus(double high=1., double radius=1.)
		: PiramidalShape(high, new Circle(radius)) {}
	Conus(const Conus& c): PiramidalShape(c)
	{
		base = new Circle(*dynamic_cast<Circle*>(c.base));
	}
	virtual double sideArea() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

// Клас Rectangle не має методів доступу до своїх полів даних - сторін прямокутника,
// а вони потрібні для обчислень. Тому оголошено підклас, який таку функціональність
// підтримує. Такий підклас потрібен тільки піраміді, тому оголошення розташовано
// всередині RectPiramid
class RectPiramid : public PiramidalShape
{
	class RectAB : public Rectangle
	{
	public:
		RectAB(double sideA=1., double sideB=1.) : Rectangle(sideA,sideB) {}
		double getA() const { return a; }
		double getB() const { return b; }
	};
public:
	RectPiramid(double high=1., double sideA=1., double sideB=1.)
		: PiramidalShape(high, new RectAB(sideA,sideB)) {}
	RectPiramid(const RectPiramid& p): PiramidalShape(p)
	{
		base = new Rectangle(*dynamic_cast<Rectangle*>(p.base));
	}
	virtual double sideArea() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

class TriPiramid : public PiramidalShape
{
public:
	TriPiramid(double high=1., double sideA=3., double sideB=4., int angle=90)
		: PiramidalShape(high, new Triangle(sideA,sideB,angle)) {}
	TriPiramid(const TriPiramid& t): PiramidalShape(t)
	{
		base = new Triangle(*dynamic_cast<Triangle*>(t.base));
	}
	virtual double sideArea() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

#endif