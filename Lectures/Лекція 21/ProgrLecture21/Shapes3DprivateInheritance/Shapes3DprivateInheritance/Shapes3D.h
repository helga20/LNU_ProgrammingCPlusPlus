#pragma once

#include "FlatShapes.h"

/*��������� ������������ ������� ���������� ��'����� �����. ����� ����������� ������� ���� �� ������ ����� ���� �����,
  �� ���� ���� �������� �����䳿. ������ ������ ������ � ����� ����� ������ ��������� � ��������, ������� ������� ��
  ������ ���������: �� ��������� ��������� � �� ��������� ��������� �����������.*/

// --------------------- ����������� ������� ����
class Shape3D
{
public:
	virtual ~Shape3D() {}
	static Shape3D* MakeInstance(std::ifstream&);

	virtual double baseSquare() const = 0;
	virtual double sideSquare() const = 0;
	virtual double surfaceSquare() const = 0;
	virtual double volume() const = 0;
	// ��������� � ���� ���������� ������� ��'����
	virtual void printOn(ostream&) const = 0;
	// ��������� ��'���� �� ����� � ������, ���������� ��� ���������
	virtual void storeOn(ofstream&) const = 0;
};

ostream& operator<<(ostream& os, const Shape3D& s);
bool operator>(const Shape3D& a, const Shape3D& b);

/* ������������ ������ ��'��� ����������� � ����� ����� - ������ � ������.
   ������������ �� ������ ��������� ������������, �������� �� ������
   ���� ��������� ��� ������� ������.
*/
class Parallelepiped : public Shape3D
{
private:
	Rectangle base;  // ��� ������������ ������� ������ �������������
	double h;        // ��� - �������, ��������������� �� ������
public:
	// ��������� ������������ ������ � ������������� �������������
	// ������� �� ���������� ��'����-������������, ��� ����� ��������
	// ������������ ����� Rectangle
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

	// ��� ����� ������ ������������ ���� ���� ������. ���� ��������
	// ��������� ������������
	virtual double baseSquare() const { return base.square(); }
	// ���� ���������� ���� ��������. ���� ����� �������������� ���������� ������
	virtual double volume() const { return base.square()*h; }
	virtual double sideSquare() const { return base.perim()*h; }
	// ����� ������� �������� �� ���� ������.
	virtual double surfaceSquare() const { return this->baseSquare()*2. + this->sideSquare(); }
};

/*����������� ������ ��������� ����������� (������) � ������ ����� ����� (������).
  ϳ����� �� ������ ��������� ������������, �������� ���� ������ ���� ���������
  ��� ������� ������. ����� ������� � �������� �� ����� ������������, �� ��� ��������.
*/
class RectangularPyramid : private Rectangle, public Shape3D
{
private:
	double h;
public:
	// ����� ������ ����������� ������������ ��������, ��������, �� ��� ����������
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
	// ����� ������ ������ ���� ��������� ������������ �����
	virtual double baseSquare() const { return this->square(); }
	// ���� ���������� ���� ��������. ���� ����� �������������� ������������ ����������
	virtual double volume() const { return square() * h / 3.; }
	// ����� ������� �������� �� ���� ������.
	virtual double surfaceSquare() const { return this->baseSquare() + this->sideSquare(); }

	// ϳ����� �� ������������ ������ �� ���� �������� ����� - ������������
	virtual double sideSquare() const
	{
		return a*sqrt(h*h + b*b*0.25) + b*sqrt(h*h + a*a*0.25);
	}
};