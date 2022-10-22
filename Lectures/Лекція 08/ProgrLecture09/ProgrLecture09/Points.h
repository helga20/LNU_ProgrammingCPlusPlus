#pragma once
// �������� ���������� ����� �� ������
struct CPoint
{
	double x;
	double y;
};
// ������ ���������� ����� �� ������
// ��� ������ � ��������
struct PPoint
{
	double ro;
	double phi;
};
// ³������ �� ������� �� ��������� ������
double Distance(const CPoint& a, const CPoint& b);
// ������������ �� ��������� ���������
PPoint CartToPolar(CPoint c);
CPoint PolarToCart(PPoint p);