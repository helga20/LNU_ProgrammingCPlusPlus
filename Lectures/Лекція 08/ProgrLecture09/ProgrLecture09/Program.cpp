#include "Fraction.h"
#include "Points.h"
#include "Time.h"

int main()
{
	// Вузли ламаної
	const int m = 5;
	CPoint chain[m] = { { 0, 0 }, { 2, 0 }, { 2, 2 }, { -1, 5 }, { -3, 3 } };
	// Довжина ламаної
	double Len = 0.0;
	for (int i = 1; i < m; ++i)
		Len += Distance(chain[i - 1], chain[i]);
	std::cout << " Length = " << Len << '\n';
	std::cin.get();
	// Перетворення координат
	PPoint R = CartToPolar(chain[2]);
	std::cout << "Cartezian point (" << chain[2].x << ',' << chain[2].y << ") in polar is: ro "
		<< R.ro << ", phi " << R.phi << " degrees\n";
	std::cin.get();
	// Обчислення в множині раціональних чисел
	const int n = 4;
	Fraction P[n] = { { 1, 1 }, Fraction(3, 4), Fraction(-1, 2), Fraction(7, 6) };
	std::cout << " P =";
	for (int i = 0; i < n; ++i)
	{
		std::cout << ' ' << P[i];
	//	PrintFraction(P[i]);
	}
	std::cout << '\n';
	char yes = 'y';
	while (yes == 'y')
	{
		Fraction x;
		std::cout << "Input a Fraction: ";  ReadFraction(x);
		Fraction S = P[0];
		for (int i = 1; i < n; ++i)
		{
			S = Mult(S, x);
			S = Add(S, P[i]);
		}
		std::cout << "S = "; PrintFraction(S);
		std::cout << '\n';
		std::cout << "Do you want to continue (y/n)? ";
		std::cin >> yes;
	}
	system("pause");

	// Експерименти з часом
	Time Lecture(1, 20);
	Time Break(20);
	Time shortBreak(15);
	Time Day = Lecture * 4 + Break * 2 + shortBreak;
	std::cout << "Student's learning day is " << Day << " long.\n";
	if (Day > 360) // 6 год. == 360 хв.
		std::cout << "It is longer then 6 hours.\n";
	else
		std::cout << "It's no so long.\n";
	system("pause");
	return 0;
}
