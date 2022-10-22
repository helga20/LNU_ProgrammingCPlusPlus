#pragma once
// Декартові координати точки на площині
struct CPoint
{
	double x;
	double y;
};
// Полярні координати точки на площині
// кут задано в градусах
struct PPoint
{
	double ro;
	double phi;
};
// Відстань між точками на декартовій площині
double Distance(const CPoint& a, const CPoint& b);
// Перетворення між системами координат
PPoint CartToPolar(CPoint c);
CPoint PolarToCart(PPoint p);