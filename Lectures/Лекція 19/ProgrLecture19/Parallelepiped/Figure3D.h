#pragma once

#include "..\FlatShapes\FlatShapes.h"

/* ������������ ������ ��'��� ����������� � ����� ����� - ������ � ������.
   ������������ �� ������ ��������� ������������, �������� �� ������
   ���� ��������� ��� ������� ������.
*/
class Parapd
{
private:
	Rectangle base;  // ��� ������������ ������� ������ �������������
	double h;        // ��� - �������, ��������������� �� ������
public:
	// ��������� ������������ ������ � ������������� �������������
	// ������� �� ���������� ��'����-������������, ��� ����� ��������
	// ������������ ����� Rectangle
	Parapd() :base(), h(1.) {}
	Parapd(double a, double b, double c) :base(a, b), h(c) {}
	void printOn(ostream& os) const
	{
		os << "Parallelepiped(" << h << " x " << base << ')';
	}
	// ��� ����� ������ ������������ ���� ���� ������. ���� ��������
	// ��������� ������������
	double baseArea() const { return base.area(); }
	// ���� ���������� ���� ��������. ���� ����� �������������� ���������� ������
	double volume() const { return base.area()*h; }
	double sideArea() const { return base.perim()*h; }
	// ����� ������� �������� �� ���� ������.
	double totalArea() const { return this->baseArea()*2. + this->sideArea(); }
};
ostream& operator<<(ostream& os, const Parapd& p)
{
	p.printOn(os); return os;
}