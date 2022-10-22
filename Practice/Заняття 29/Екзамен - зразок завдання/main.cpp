#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include "coffeepack.h"
#include "salepack.h"
using namespace std;

void printVector(const vector<CoffeePack*>& v)
{
	for (vector<CoffeePack*>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
	{
		cout << *(*it) << ". ";
		try
		{
			cout << (*it)->getPrice() << " uah\n";
		}
		catch (const CoffeePriceException& E)
		{
			E.printInfo();
		}
	}
	cout << "\n";
}

void doubleWeight(CoffeePack* item)
{
	item->increaseWeight(item->getWeight());
}

int main()
{
	map<string, int> pricesMap;
	pricesMap["Lavazza"] = 520;
	pricesMap["Dallmayr"] = 420;
	pricesMap.emplace("Nescafe", 560);
	pricesMap.emplace("Jacobs", 370);
	pricesMap.emplace("Tchibo", 310);

	//CoffeePack NoName(pricesMap);
	//NoName.initialize();
	CoffeePack Jac("Jacobs", 470, pricesMap);
	CoffeePack JacCopy(Jac);
	Jac.increaseWeight(Jac.getWeight());

	SalePack Lav("Lavazza", 500, 15, pricesMap);
	SalePack Tch("Tchibo", 370, 10, pricesMap);

	//cout << "Enter coffee info (producer, weight)\n";
	//cin >> NoName;

	//cout << "All packs\n";
	//cout << "\n" << Jac << "\n" << JacCopy << "\n" << Lav << "\n" << Tch << "\n\n";

	ifstream iFile("coffee_info.txt");
	int fileN; iFile >> fileN;
	int coffeeN = fileN + 2;
	CoffeePack* coffeeArr = new CoffeePack[coffeeN];
	coffeeArr[0] = Jac;
	coffeeArr[1] = JacCopy;
	for (int i = 0; i < fileN; ++i)
	{
		coffeeArr[i + 2].setPricesTable(pricesMap);
		iFile >> coffeeArr[i + 2];
	}
	iFile.close();
	cout << "Coffee\n";
	for_each(coffeeArr, coffeeArr + coffeeN, [](CoffeePack& item) {
		cout << item;
		try
		{
			cout << ". " << item.getPrice() << " uah\n";
		}
		catch (const CoffeePriceException& E)
		{
			cout << ". ";
			E.printInfo();
		}
		});

	iFile.open("sale_coffee.txt");
	int saleN; iFile >> saleN;
	SalePack* saleArr = new SalePack[saleN];
	for (int i = 0; i < saleN; ++i)
	{
		saleArr[i].setPricesTable(pricesMap);
		iFile >> saleArr[i];
	}
	iFile.close();
	cout << "\nCoffee on sale\n";
	for_each(saleArr, saleArr + saleN, [](SalePack& item) {
		cout << item;
		try
		{
			cout << ". " << item.getPrice() << " uah\n";
		}
		catch (const CoffeePriceException& E)
		{
			cout << ". ";
			E.printInfo();
		}
		});

	vector<CoffeePack*> auchan;
	for (int i = 0; i < coffeeN; ++i)
	{
		auchan.push_back(new CoffeePack(coffeeArr[i]));
	}
	for (int i = 0; i < saleN; ++i)
	{
		auchan.push_back(new SalePack(saleArr[i]));
	}
	sort(auchan.begin(), auchan.end(), [](CoffeePack* P1, CoffeePack* P2) { return (*P1) < (*P2); });
	cout << "\n\nAuchan coffee\n";
	printVector(auchan);

	/*
	cout << "Enter new Coffee Pack info\n";
	cout << "Enter type (C - regular pack, S - sale pack): ";
	char type; cin >> type;
	if (type == 'C')
	{
		CoffeePack* item = new CoffeePack(&pricesMap);
		item->initialize();
		auchan.push_back(item);
	}
	else if (type == 'S')
	{
		CoffeePack* item = new SalePack(&pricesMap);
		item->initialize();
		auchan.push_back(item);
	}
	else
	{
		cout << "Sorry. Wrong type.\n";
	}
	cout << "\n\nAuchan coffee\n";
	printVector(auchan);
	*/

	double totalPrice = 0.0;
	int saleCount = 0;
	for (vector<CoffeePack*>::const_iterator it = auchan.begin(); it != auchan.end(); ++it)
	{
		try
		{
			totalPrice += (*it)->getPrice();
		}
		catch (const CoffeePriceException& E)
		{
		}

		if ((*it)->getType() == 'S')
		{
			++saleCount;
		}
	}
	cout << "Total price: " << totalPrice << " uah.\n";
	cout << "Nof sale packs: " << saleCount << ".\n\n";

	for_each(auchan.begin(), auchan.end(), doubleWeight);
	ofstream oFile("auchan_coffee.txt");
	for_each(auchan.cbegin(), auchan.cend(), [&oFile](const CoffeePack* item) { oFile << (*item) << "\n"; });
	oFile.close();
	sort(auchan.begin(), auchan.end(), [](CoffeePack* P1, CoffeePack* P2) { return (*P2) < (*P1); });
	cout << "Top 3 coffee packs\n";
	for_each(auchan.cbegin(), auchan.cbegin() + 3, [](const CoffeePack* item) {
		cout << *item << ". ";
		try
		{
			cout << item->getPrice() << " uah.\n";
		}
		catch (const CoffeePriceException& E)
		{
			cout << "No price\n";
		}
		});

	vector<CoffeePack*> copyV;
	copyV.resize(auchan.size());
	copy(auchan.begin(), auchan.end(), copyV.begin());
	sort(copyV.begin(), copyV.end(), [](CoffeePack* P1, CoffeePack* P2) { return P1->getProducer() < P2->getProducer(); });
	cout << "\n\nBy Producers\n";
	printVector(copyV);
	vector<CoffeePack*>::iterator newEnd = unique(copyV.begin(), copyV.end(), [](CoffeePack* P1, CoffeePack* P2) { return P1->getProducer() == P2->getProducer(); });
	cout << "\n\nUnique Producers\n";
	for_each(copyV.begin(), newEnd, [](const CoffeePack* item) {
		cout << *item << ". ";
		try
		{
			cout << item->getPrice() << " uah.\n";
		}
		catch (const CoffeePriceException& E)
		{
			cout << "No price\n";
		}
		});


	delete[] coffeeArr;
	delete[] saleArr;
	return 0;
}