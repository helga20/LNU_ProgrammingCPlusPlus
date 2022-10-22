#include <iostream>
#include <fstream>
#include "sportsman.h"
#include "footballer.h"
#include "tennis_player.h"
using namespace std;

int main()
{
	TennisPlayer TP1("Dolhopolov", 20000, 11);
	TennisPlayer TP2("Svitolina", 20000, 9);

	TP1.printSportsmanInfo();
	cout << TP1.incomeInfo();
	cout << "\n";
	cout << TP1 << "\n";
	cout << "\n";

	TP2.printSportsmanInfo();
	cout << TP2.incomeInfo();
	cout << "\n";
	cout << TP2 << "\n";
	cout << "\n";
	system("pause");

	cout << "\nRating change\n";
	TP1.setRating(2);
	TP1.setRating(-5);
	TP1.printSportsmanInfo();
	cout << TP1.incomeInfo();
	cout << "\n";
	cout << TP1 << "\n";
	cout << "\n";
	system("pause");

	Footballer F1("Shevchenko", 120);
	Footballer F2("Tymoshchuk", 250);

	F1.printSportsmanInfo();
	cout << F1.incomeInfo();
	cout << "\n";
	cout << F1 << "\n";
	cout << "\n";

	F2.printSportsmanInfo();
	cout << F2.incomeInfo();
	cout << "\n";
	cout << F2 << "\n";
	cout << "\n";
	system("pause");

	cout << "\nChanging the number of goals\n";
	F2.setGoals(320);
	F2.setGoals(-20);
	F2.printSportsmanInfo();
	cout << F2.incomeInfo();
	cout << "\n";
	cout << F2 << "\n";
	cout << "\n";
	system("pause");

	ifstream iFile("sportsmen.txt");
	int n; iFile >> n;
	Sportsman** arr = new Sportsman * [n];
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		char code;
		iFile >> code;
		if (code == 'T')
		{
			arr[k] = new TennisPlayer();
		}
		else if (code == 'F')
		{
			arr[k] = new Footballer();
		}
		else
		{
			iFile.ignore(256, '\n');
			continue;
		}
		iFile >> *(arr[k]);
		++k;
	}
	iFile.close();
	cout << "\nAll sportsmen\n";
	for (int i = 0; i < k; ++i)
	{
		arr[i]->printSportsmanInfo();
		cout << "\n";
	}
	cout << "\n";

	int total = 0;
	for (int i = 0; i < k; ++i)
	{
		total = total + arr[i]->incomeInfo();
		arr[i]->printSportsmanInfo();
		cout << "\n";
	}
	cout << "Total price = " << total << " hrn\n";

	delete[] arr;
	system("pause");
	return 0;
}

