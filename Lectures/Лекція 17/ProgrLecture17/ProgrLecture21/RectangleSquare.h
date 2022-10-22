#pragma once
#include <iostream>
using std::ostream;

class Rectangle
{
private:
	double a, b;
	// ������� ���� �����
	double s;
	// ��������� �������� ��������� ����
	void calculateArea() { s = a*b; }
protected:
	// ������ �� ���� ������� � ��������
	double getA() const { return a; }
public:
	Rectangle() :a(3.), b(4.) { calculateArea(); }
	Rectangle(double x, double y);
	// ������� ���� ����� ������ �� ���������� ����������
	virtual ~Rectangle() {}
	// ��� ��������� ������� ���������� �����
	// ������, �� �� ������� ����� ��'����, ������� ������������
	virtual void printOn(ostream&) const;
	double area() const { return s; }
	double perim() const { return 2.*(a + b); }
};

// ������� - �� �����������, � ����� �� ������� ���
class Square :public Rectangle
{
public:
	// ���� ����������� ����� ������ �����
	Square() :Rectangle(1., 1.) {}
	Square(double x) :Rectangle(x, x) {}
	// ��������� ����� �������������
	virtual void printOn(ostream&) const;
	// ���������� ����� �� ��������� ����������
};

// ������ �������� ��� ��������� �񳺿 ��������
ostream& operator<<(ostream& os, const Rectangle& R);

template <typename T>
class Show
{
	T obj;
public:
	Show(T x) :obj(x){}
	void show() const { cout << "Show : ";  obj.printOn(cout); cout << '\n'; }
};