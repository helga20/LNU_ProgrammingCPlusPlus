#include "Figure3D.h"

int main()
{
	// Випробуємо складний об'єкт
	Parapd R(2, 3, 4), P;
	std::cout << R << "\n V = " << R.volume()
		<< "\n So = " << R.baseArea()
		<< "\n Sb = " << R.sideArea()
		<< "\n S = " << R.totalArea() << '\n';
	P.printOn(std::cout);
	std::cout << "\n V = " << P.volume() << '\n';
	system("pause");
	return 0;
}