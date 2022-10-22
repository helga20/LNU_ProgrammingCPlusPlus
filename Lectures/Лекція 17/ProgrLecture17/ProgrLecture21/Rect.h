#pragma once
#include <iostream>

// ���� ����������� ������ ������, �������� ����� �� ��������, �� ������ ����� �� ��������� ������
class Rect
{
private:
	double a, b;
public:
	Rect() :a(3.), b(4.) {}
	Rect(double x, double y);
	void printOn(std::ostream&);
	double area() { return a*b; }
	double perim() { return 2.*(a + b); }
};