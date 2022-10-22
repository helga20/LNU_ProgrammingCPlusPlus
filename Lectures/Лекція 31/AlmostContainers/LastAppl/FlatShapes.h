/*
��������: ���������� ����� ���������� ������ (�����������, �������, ����, ���������)
   ���� ����� ���� ������, ����� ��������� ���� �� ���������� ����� ����� �� ��������.
 в�����: ��������� �������� �����, �� ��������� ������ ������. ������� ����������� ���� Shape ����
   ��������� ���������. ϳ������ Rectangle, Circle, Triangle ��������� ��� ������. ������� - �� ���������
   �����������, ������� "�" ����������� � ������ ���������, ���� Square - ������ Rectangle
*/
#ifndef _FlatShapesHeader_
#define _FlatShapesHeader_

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
using std::ostream;
using std::ofstream;

// ����������� ���� ���������, �� ����� ������ (������ ����) ���� �������
// ���������� ��������� ����������, ��� �� ����������� ���� ����������� � ��������� ���������
//   � ���������� ���������
class Shape
{
public:
	virtual ~Shape() {}
	virtual double square() const = 0;
	virtual double perim() const = 0;
	virtual void printOn(ostream&) const = 0;
	virtual void storeOn(ofstream&) const = 0;
	virtual char * toStr() const = 0;
	virtual void multBy(double) = 0;
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
	virtual ~Rectangle() { this->printOn(std::cout); std::cout << " said 'Bye!'\n"; }
	virtual double square() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
	virtual char * toStr() const;
	virtual void multBy(double x) { a *= x; b *= x; }
};

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double radius=1.) : r(radius) {}
	virtual ~Circle() { this->printOn(std::cout); std::cout << " said 'Bye!'\n"; }
	virtual double square() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
	virtual char * toStr() const;
	double radius() const { return r; }
	virtual void multBy(double x) { r *= x; }
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
	virtual ~Triangle() { this->printOn(std::cout); std::cout << " said 'Bye!'\n"; }
	virtual double square() const;
	virtual double perim() const;
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
	virtual char * toStr() const;
	virtual void multBy(double x) { a *= x; b *= x; }
};

// ���������� �������� � ������ ������������� �� �� ��������� �� ����
class Square : public Rectangle
{
public:
	Square(double side=1.) : Rectangle(side,side) {};
	virtual ~Square() { this->printOn(std::cout); std::cout << " said 'Bye!'\n\t"; }
	virtual void printOn(ostream&) const;
	virtual void storeOn(ofstream&) const;
	virtual char * toStr() const;
};

#endif