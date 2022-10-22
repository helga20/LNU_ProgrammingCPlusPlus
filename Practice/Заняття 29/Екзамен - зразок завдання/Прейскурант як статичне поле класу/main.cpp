#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "coffeepack.h"
#include "salecoffeepack.h"
using namespace std;

int main()
{
	cout << "Auchan Coffee\n";

	CoffeePack::s_prices.emplace("Lavazza", 520);
	CoffeePack::s_prices["Dallmayr"] = 420;
	CoffeePack::s_prices.emplace("Nescafe", 560);
	CoffeePack::s_prices.emplace("Jacobs", 370);
	CoffeePack::s_prices.emplace("Tchibo", 310);

	int coffeeSize = 4;
	CoffeePack* coffeeArr = new CoffeePack[coffeeSize];
	coffeeArr[0] = CoffeePack("Jacobs", 350);
	ifstream iFile("coffee_info.txt");
	for (int i = 1; i < coffeeSize; ++i)
	{
		CoffeePack pack; iFile >> pack;
		coffeeArr[i] = pack;
	}
	iFile.close();
	cout << "Regular coffee packs\n";
	for_each(coffeeArr, coffeeArr + coffeeSize, [](const CoffeePack& pack) { cout << pack << "\n"; });
	cout << "\n";

	int saleCoffeeSize;
	iFile.open("sale_coffee.txt");
	iFile >> saleCoffeeSize;
	SaleCoffeePack* saleArr = new SaleCoffeePack[saleCoffeeSize];
	for (int i = 0; i < saleCoffeeSize; ++i)
	{
		iFile >> saleArr[i];
	}
	iFile.close();
	cout << "\nSale coffee packs\n";
	for_each(saleArr, saleArr + saleCoffeeSize, [](const SaleCoffeePack& pack) { cout << pack << "\n"; });
	cout << "\n";

	vector<CoffeePack*> auchan;
	auchan.reserve(coffeeSize + saleCoffeeSize);
	for_each(coffeeArr, coffeeArr + 4, [&auchan](const CoffeePack& pack) { auchan.push_back(new CoffeePack(pack)); });
	for_each(saleArr, saleArr + 4, [&auchan](const SaleCoffeePack& pack) { auchan.push_back(new SaleCoffeePack(pack)); });
	cout << "\nAll Auchan coffee\n";
	sort(auchan.begin(), auchan.end(), [](const CoffeePack* p1, const CoffeePack* p2) { return *p1 < *p2; });
	for_each(auchan.cbegin(), auchan.cend(), [](const CoffeePack* pack) {cout << *pack << ". Price: " << pack->getPrice() << "\n"; });
	cout << "\n";

	delete[] coffeeArr;
	delete[] saleArr;
	return 0;
}