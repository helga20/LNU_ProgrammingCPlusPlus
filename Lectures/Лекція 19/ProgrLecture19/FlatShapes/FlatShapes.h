/*
��������: ���������� ����� ���������� ������ (�����������, �������, ����, ���������)
   ���� ����� ���� ������, ����� ��������� ���� �� ���������� ����� ����� �� ��������.
 в�����: ��������� �������� �����, �� ��������� ������ ������. ������� ����������� ���� Shape ����
   ��������� ���������. ϳ������ Rectangle, Circle, Triangle ��������� ��� ������. ������� - �� ���������
   �����������, ������� "�" ����������� � ������ ���������, ���� area - ������ Rectangle
*/
#ifndef _FlatShapesHeader_
#define _FlatShapesHeader_

#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <cmath>
using std::ostream;
using std::ofstream;
using std::string;

// ����������� ���� ���������, �� ����� ������ (������ ����) ���� �������
// ���������� ��������� ����������, ��� �� ����������� ���� ����������� � ��������� ���������
//   � ���������� ���������
class Shape
{
public:
	virtual ~Shape() {}
	virtual double area() const = 0;
	virtual double perim() const = 0;
	virtual void printOn(ostream&) const = 0;
	virtual void storeOn(ofstream&) const = 0;
	virtual string toStr() const;
	bool operator>(const Shape& s)
	{
		return this->area() > s.area();
	}
};

// ������ �������� ��������� ��� �񳺿 ��������
ostream& operator<<(ostream& os, const Shape& s);

// ����������� � �����������, � ����� �� ��������� ����� �������� �� �����������,
//   ��� ����� � ������������� �� �����������
class Rectangle : public Shape
{
protected:
	double a;
	double b;
public:
	Rectangle(double sideA=1., double sideB=1.) : a(sideA), b(sideB) {}
	virtual double area() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
};

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double radius=1.) : r(radius) {}
	virtual double area() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
	double radius() const { return r; }
};

class Triangle : public Shape
{
private:
	double a; // ������� ����������
	double b;
	int y;    // � ��� � ��������
	double angle() const { return M_PI*y/180; }
public:
	Triangle(double sideA=3., double sideB=4., int angle=90) : a(sideA), b(sideB), y(angle) {}
	virtual double area() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
};

// ���������� �������� � ������ ������������� �� �� ��������� �� ����
class area : public Rectangle
{
public:
	area(double side=1.) : Rectangle(side,side) {};
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
};

#endif