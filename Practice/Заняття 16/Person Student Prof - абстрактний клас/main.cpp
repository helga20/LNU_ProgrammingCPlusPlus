#include <iostream>
#include <fstream>
#include "person.h"
#include "student.h"
#include "prof.h"
using namespace std;

int main()
{
	Student Andr("Andriy", "Paliy", 19, "PMI-31");
	Andr.printPersonInfo();
	Andr.workInfo();
	cout << Andr << "\n";
	cout << "\n";

	Prof Tar("Sviatoslav", "Tarasiuk", 50, "MatAn");
	Tar.printPersonInfo();
	Tar.workInfo();
	cout << Tar << "\n";
	cout << "\n";

	cout << "\n-------------------------------------------\n";
	ifstream iFile("people.txt");
	int n; iFile >> n;
	Person** arr = new Person*[n];
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		char code; iFile >> code;
		if (code == 'S')
		{
			arr[k] = new Student();
		}
		else if (code == 'P')
		{
			arr[k] = new Prof();
		}
		else
		{
			iFile.ignore(256, '\n');
			continue;
			// TODO: дочитати до кінця рядка в текстовому файлі
			// перейти на новий рядок в текстовому файлі
		}
		iFile >> *(arr[k]);
		++k;
	}
	iFile.close();

	cout << "All People\n";
	for (int i = 0; i < k; ++i)
	{
		arr[i]->printPersonInfo();
		cout << "\n";
	}
	cout << "\n";

	delete[] arr;
	system("pause");
	return 0;
}