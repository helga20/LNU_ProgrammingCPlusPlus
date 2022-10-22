#include "Shapes3D.h"

int main()
{
	// Масив паралелепіпедів і пірамід
	Shape3D* R[] = {
		new Parallelepiped(5., 6., 4.),
		new RectangularPyramid(7., 5., 5.),
		new RectangularPyramid(),
		new Parallelepiped(5., 4., 6.),
		new Parallelepiped() };
	const int n = sizeof R / sizeof *R;
	for (int i = 0; i < n; ++i)
		std::cout << *R[i] << "\n\tSo = " << R[i]->baseSquare()
			<< " \tV = " << R[i]->volume()
			<< "\n\tSb = " << R[i]->sideSquare() << '\n';
	std::cin.get();

	// Зберігання об'єктів до файла і вилученя з пам'яті
	ofstream fout("storage.txt");
	for (int i = 0; i < n; ++i)
	{
		R[i]->storeOn(fout);
		fout << '\n';
		delete R[i];
		R[i] = nullptr;
	}
	fout.close();

	// Завантаження з файла - відновлення
	std::ifstream fin("storage.txt");
	for (int i = 0; i < n; ++i)
	{
		try
		{
			R[i] = Shape3D::MakeInstance(fin);
		}
		catch (std::domain_error& err)
		{
			std::cout << " !!! ERROR reading file '" << err.what() << "' encountered at step #" << i + 1 << '\n';
			R[i] = nullptr;
			while (fin.get() != '\n') continue;
		}
	}
	fin.close();
	std::cout << "\nLoaded shapes are:\n\n";
	for (int i = 0; i < n; ++i)
	{
		if (R[i] != nullptr) std::cout << *R[i] << '\n';
		else
		{
			std::cout << "Invalid shape\n";
			R[i] = new Parallelepiped();
		}
	}
	system("pause");
	//відшукання фігури з найбільшим об'ємом
	int maxNo = 0;
	for (int i = 1; i < n; ++i)
		if (*R[i] > *R[maxNo]) maxNo = i;
	std::cout << "\nThe volumest shape is " << *R[maxNo] << "\n\n";
	
	std::cout << "Bye!\n";
	system("pause");
	return 0;
}