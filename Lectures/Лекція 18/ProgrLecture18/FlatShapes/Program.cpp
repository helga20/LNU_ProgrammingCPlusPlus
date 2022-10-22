#include "FlatShapes.h"
#include <sstream>
#include <string>

	// випробування ієрархії плоских фігур
int main()
{
	std::cout << " * Static array *\n-----------------------\n";
	Shape* s[] = {
		new Rectangle(6., 4.),
		new Square(5.),
		new Triangle(),
		new Circle(5.),
		new Square() };
	const int n = sizeof s / sizeof *s;
	for (int i = 0; i < n; ++i)
		std::cout << *s[i] << "\n\tS = " << s[i]->area() << "  \tP = " << s[i]->perim() << '\n';
	std::cin.get();

	std::cout << "\nShapes as strings\n\n";

	std::ostringstream ostr;
	std::string lines[n];
	for (int i = 0; i < n; ++i)
	{
		ostr << *s[i];
		lines[i] = ostr.str();
		ostr.str("");
		std::cout << lines[i] << '\n';
	}
	std::cout << '\n';
	for (int i = 0; i < n; ++i)	std::cout << s[i]->toStr() << '\n';
	system("pause");

	std::cout << "\n\nCompareing shapes\n";
	int maxNo = 0;
	for (int i = 1; i < n; ++i)
	{
		if (s[i] > s[maxNo]) maxNo = i;
	}
	std::cout << "\nThe largest shape is " << *s[maxNo] << '\n';
	system("pause");

	std::cout << "\n\n Storeing and loading shapes to a dynamic array\n";
	// зберігання фігур до файла
	ofstream fout("Shapes.txt");
	// кількість фігур
	fout << n + 2 << '\n';
	// зберігання масиву
	Triangle rt(3.5, 3.5, 60); rt.storeOn(fout); fout << '\n';
	for (int i = 0; i < n; ++i)
	{
		s[i]->storeOn(fout); fout << '\n';
	}
	// зберігання окремих об'єктів
	Triangle tt(3, 5, 120); tt.storeOn(fout); fout << '\n';
	fout.close();
	std::cout << "\nShapes are stored\n";

	// завантаження об'єктів з файла
	std::ifstream fin("Shapes.txt");
	// створення масиву відповідного розміру
	int N;
	fin >> N; fin.get();
	Shape ** D = new Shape*[N];
	// завантаження даних, розпізнавання типу фігури, створення об'єкта
	for (int i = 0; i < N; ++i)
	{
		double x, y; int g;
		char type; fin >> type;
		switch (type)
		{
		case 'R': fin >> x >> y; fin.get();
			D[i] = new Rectangle(x, y); break;
		case 'C': fin >> x; fin.get();
			D[i] = new Circle(x); break;
		case 'T': fin >> x >> y >> g; fin.get();
			D[i] = new Triangle(x, y, g); break;
		case 'S': fin >> x; fin.get();
			D[i] = new Square(x);
		}
	}
	// контрольне виведення на екран
	for (int i = 0; i < N; ++i)
	{
		std::cout << *D[i] << '\n';
	}
	system("pause");
	return 0;
}