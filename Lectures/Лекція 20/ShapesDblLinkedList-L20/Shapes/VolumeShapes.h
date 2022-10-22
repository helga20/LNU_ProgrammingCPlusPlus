/*
��'���� ������ ���������� � ������ � ������ - ������ ������. �������
  VolShape ���� �������� �����䳿: ���������� ���� ������ �� ����
  �������, ��'���, ���������� ������. ϳ������ �������� - PiramidalShape
  i DirectShape - ���������� ������� ���������� ���� � ��'��� ���������
  ���� ��'����� �����: ������ � ������ �� ������� � ����� ������. � ���
  ��� ������� ���������� ��������� ��������� �������� �����, �����
  ����. ������ ����� ������� ���������� ����� ���� ������� � ��������
  PiramidalShape: ����� � ������� ����������� ����.

���������� ��'���� � ���� - ������������� "��������" ����� �����/������ Գ����
 pRintOn(����) ���� ������ ���������� ��'����
��������� ��'���� - ��������� � ���� ����� ��� ��'��� � ������, �������� ���
 ���������� ���������� � ��������� ��'����. ����� storeOn(����) ����� ���������
 ��� � ������������ �������� ����, ��������� ���������� � ����������� �����
 getClassName() ��������� ���� ��� ���� ���������� (�� ������ ������ ����������
 ������� typeid(pointer), ��� �� ���� ���� ����������).

������� ������ (������ �����) ��������� ������ ����� ���� ���������� ���������
 ���������� ���� ��'���� ��� �������� �� ���������� ���������� �� ���
 ����������� � �����
*/
#ifndef _VolumeShapeHeader_
#define _VolumeShapeHeader_

#include "FlatShapes.h"
#include <exception>

// --------------------- ����������� ������� ����
class VolShape
{
protected:
	double h;
	Shape* base;
	string baseToStr() const { return base->toStr(); }
public:
	// ���� ��� ����� �������, �� �������� ��� ����������� ������� ���� �����
	class BadClassname : public std::exception
	{
	public:
		BadClassname(const char* mess) :exception(mess){};
	};
	// ������ ����� ���������� �� ��������� �� ��������� ����������
	static VolShape* CopyInstance(VolShape*);
	static VolShape* MakeInstance(std::ifstream&);

	VolShape(double high=1., Shape* s=0) : h(high), base(s) {}
	virtual ~VolShape() { delete base; }
	virtual double baseSquare() const { return base->square(); }
	virtual double sideSquare() const = 0;
	virtual double surfaceSquare() const = 0;
	virtual double volume() const = 0;
	// ��������� � ���� ���������� ������� ��'����
	virtual void printOn(ostream&) const = 0;
	// ��������� ��'���� �� ����� � ������, ���������� ��� ���������
	virtual void storeOn(ofstream&) const;
	// ��'� ����� ������� ��� ������ ��������� �� �����
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual VolShape* clone() = 0;
};

ostream& operator<<(ostream& os, const VolShape& s);

// --------------------- �������� ������ �����
// DirectShape ���� �������� ��� ������. ����� ����������� (� ���������� ������).
// � �������� ������� ����� ��������� ������������� ��'����

class DirectShape : public VolShape
{
public:
	DirectShape(double high=1., Shape* s=0) : VolShape(high,s) {}
	virtual double sideSquare() const
	{
		return base->perim() * h;
	}
	virtual double surfaceSquare() const
	{
		return baseSquare() * 2 + sideSquare();
	}
	virtual double volume() const
	{
		return base->square() * h;
	}
	virtual void printOn(ostream&) const;
	virtual const char * getClassName() const { return typeid(this).name(); }
};

// ϳ������ �������� �������� ��� ������, ��������� ��������� ��'���
class Cylinder : public DirectShape
{
public:
	Cylinder(double high=1., double radius=1.): DirectShape(high)
	{
		base = new Circle(radius);
	}
	Cylinder(const Cylinder& c): DirectShape(c)
	{
		base = new Circle(*dynamic_cast<Circle*>(c.base));
	}
	Cylinder& operator=(const Cylinder& c);
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual Cylinder* clone() { return new Cylinder(*this); }
};

class Paralelepiped : public DirectShape
{
public:
	Paralelepiped(double high=1., double sideA=1., double sideB=1.): DirectShape(high)
	{
		base = new Rectangle(sideA,sideB);
	}
	Paralelepiped(const Paralelepiped& p): DirectShape(p)
	{
		base = new Rectangle(*dynamic_cast<Rectangle*>(p.base));
	}
	Paralelepiped& operator=(const Paralelepiped& p);
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual Paralelepiped* clone() { return new Paralelepiped(*this); }
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
	// ������� *��������*
	virtual TriPrizm* clone() { return new TriPrizm(*this); }
};

// --------------------- �������� ������� �����
// PiramidalShape ���� ����������� �� ��������� ��'��,
// ��� ���� �������� �������� �� ���� ������, ���� - � ��������.
// �� � � ������ �������, ������������ ������� ���������� �� ��������� ��������� ������.
// ��� ��������� ������ ��������� ���������� �������� ����� - �� ������ ����� ����� ���������� ������

class PiramidalShape : public VolShape
{
public:
	PiramidalShape(double high=1., Shape* s=0) : VolShape(high,s) {}
	virtual double surfaceSquare() const
	{
		return baseSquare() + sideSquare();
	}
	virtual double volume() const
	{
		return base->square() * h/3.;
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
	virtual double sideSquare() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual Conus* clone() { return new Conus(*this); }
};

// ���� Rectangle �� �� ������ ������� �� ���� ���� ����� - ����� ������������,
// � ���� ������ ��� ���������. ���� ��������� ������, ���� ���� ���������������
// �������. ����� ������ ������� ����� �����, ���� ���������� �����������
// �������� RectPiramid
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
		base = new RectAB(*dynamic_cast<RectAB*>(p.base));
	}
	virtual double sideSquare() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual RectPiramid* clone() { return new RectPiramid(*this); }
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
	virtual double sideSquare() const;
	virtual const char * getClassName() const { return typeid(this).name(); }
	// ������� *��������*
	virtual TriPiramid* clone() { return new TriPiramid(*this); }
};

#endif