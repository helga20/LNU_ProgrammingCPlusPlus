#include "VolumeShapes.h"
#include <fstream>

int main()
{
	// випробування ієрархії об'ємних фігур
	std::cout << " * Volume shapes section *\n-----------------------\n";

	// Статичний масив
	VolShape* v[] = {
		new Parallelepiped(5., 6., 4.),
		new RectPiramid(7., 5., 5.),
		new TriPiramid(),
		new Cylinder(5., 4.),
		new Conus() };
	int m = sizeof v / sizeof *v;
	for (int i = 0; i < m; ++i)
		std::cout << *v[i] << "\n\tSo = " << v[i]->baseArea() << " \tV = " << v[i]->volume()
		<< "\n\tSb = " << v[i]->sideArea() << '\n';
	std::cin.get();
	// Глибоке копіювання
	Cylinder copyCyl;
	std::cout << "Before assignment " << copyCyl << '\n';
	copyCyl = *dynamic_cast<Cylinder*>(v[3]);
	std::cout << "And after: " << copyCyl << '\n';
	std::cin.get();
	// Завантаження з файла
	std::ifstream fin("volShapes.txt");
	int size;
	fin >> size;
	VolShape** VS = new VolShape*[size];
	for (int i = 0; i < size; ++i)
	{
		try
		{
			VS[i] = VolShape::MakeInstance(fin);
		}
		catch (VolShape::BadClassname& bcn)
		{
			std::cout << " !!! ERROR: Bad class name '" << bcn.what() << "' encountered at step #" << i + 1 << '\n';
			VS[i] = nullptr;
			while (fin.get() != '\n') continue;
		}
	}
	fin.close();
	std::cout << "\nLoaded shapes are:\n\n";
	for (int i = 0; i < size; ++i)
	{
		if (VS[i] != nullptr) std::cout << *VS[i] << '\n';
		else
		{
			std::cout << "Invalid shape\n";
			VS[i] = new Cylinder(copyCyl);
		}
	}
	system("pause");
	//відшукання фігури з найбільшим об'ємом
	//як це зробити за допомогою оператора > ?
	int maxNo = 0;
	for (int i = 1; i < size; ++i)
		if (VS[i]->volume() > VS[maxNo]->volume()) maxNo = i;
	std::cout << "\nThe volumest shape is " << *VS[maxNo] << "\n\n";
	system("pause");

	// Зберігання об'єктів до файла
	ofstream fout("storage.txt");
	for (int i = 0; i < size; ++i)
	{
		VS[i]->storeOn(fout);
		fout << '\n';
	}
	fout.close();
	// Очищення динамічної пам'яті
	for (int i = 0; i < size; ++i) delete VS[i];
	delete[] VS;
	return 0;
}