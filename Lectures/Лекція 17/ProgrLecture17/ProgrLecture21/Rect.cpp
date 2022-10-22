#include "Rect.h"

// конструктор перевіряє параметри
Rect::Rect(double x, double y)
{
	a = (x > 0.1) ? x : 0.1;
	b = (y > 0.1) ? y : 0.1;
}

void Rect::printOn(std::ostream& os)
{
	os << "Rect ( " << a << " x " << b << " )";
}