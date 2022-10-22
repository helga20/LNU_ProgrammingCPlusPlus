#include <iostream>
#include <fstream>
#include "tree.h"
#include "apple.h"
#include "apricot.h"
using namespace std;

int main()
{
	//cout << "Apple 2 years: " << F1.getWeight() << " kg\n";
	//cout << F1 << "\n";
	//cout << "Apple 5 years: " << F2.getWeight() << " kg\n";
	//cout << F2 << "\n";
	//F1.addOneYear();
	//F2.addOneYear();
	//cout << "\nAfter 1 year\n";
	//cout << "Apple 3 years: " << F1.getWeight() << " kg\n";
	//cout << "Apple 6 years: " << F2.getWeight() << " kg\n";

	//FruitTree F("Pear", 5, 1.2, 7);
	//AppleTree A("Golden Apple", 7, 1.5, 12, "Golden");
	//ApricotTree P1("Red Apricot", 5, 1.7, 10, false);
	//ApricotTree P2("Red Apricot", 7, 2.1, 25, true);

	//cout << "First year\n";
	//cout << "Pear: " << " " << F.getWeight() << " kg\n";
	//cout << "Apple: " <<  A.getWeight() << " kg\n";
	//cout << "Apricot: " << P1.getWeight() << " kg\n";
	//cout << "Apricot: " << P2.getWeight() << " kg\n\n";

	//F.addOneYear();
	//A.addOneYear();
	//P1.addOneYear(); P1.setFreeze(false);
	//P2.addOneYear(); P2.setFreeze(false);

	//cout << "Second year\n";
	//cout << "Pear: " << " " << F.getWeight() << " kg\n";
	//cout << "Apple: " << A.getWeight() << " kg\n";
	//cout << "Apricot: " << P1.getWeight() << " kg\n";
	//cout << "Apricot: " << P2.getWeight() << " kg\n\n";

	//cout << "All fruits\n";
	//cout << F << "\n" << A << "\n" << P1 << "\n" << P2 << "\n\n";

	ifstream applesFile("apples.txt");
	int nApples; applesFile >> nApples;
	AppleTree* apples = new AppleTree[nApples];
	for (int i = 0; i < nApples; ++i)
	{
		applesFile >> apples[i];
	}
	applesFile.close();

	ifstream apricotsFile("apricots.txt");
	int nApricots; apricotsFile >> nApricots;
	ApricotTree* apricots = new ApricotTree[nApricots];
	for (int i = 0; i < nApricots; ++i)
	{
		apricotsFile >> apricots[i];
	}
	apricotsFile.close();

	cout << "Apples\n";
	for (int i = 0; i < nApples; ++i)
	{
		cout << apples[i] << ". " << apples[i].getWeight() << " kg\n";
	}

	cout << "\nApricots\n";
	for (int i = 0; i < nApricots; ++i)
	{
		cout << apricots[i] << ". " << apricots[i].getWeight() << " kg\n";
	}

	cout << "\n";

	int nAll = nApples + nApricots;
	FruitTree** fruits = new FruitTree * [nAll];
	int kFruits = 0;
	for (int i = 0; i < nApples; ++i)
	{
		fruits[kFruits] = &apples[i];
		kFruits += 1;
	}
	for (int j = 0; j < nApricots; ++j)
	{
		fruits[kFruits] = &apricots[j];
		kFruits += 1;
	}

	cout << "\n--------------------------\n";
	cout << "All fruits\n";
	for (int k = 0; k < nAll; ++k)
	{
		cout << *(fruits[k]) << "\n";
	}
	cout << "\n--------------------------\n";

	for (int k = 0; k < nAll; ++k)
	{
		fruits[k]->addOneYear();
	}

	cout << "\n--------------------------\n";
	ofstream oFile("allfruits.txt");
	cout << "After one year\n";
	for (int k = 0; k < nAll; ++k)
	{
		cout << *(fruits[k]) << "\n";
		oFile << *(fruits[k]) << '\n';
	}
	cout << "\n--------------------------\n";
	oFile.close();

	delete[] fruits;

	system("pause");
	return 0;
}