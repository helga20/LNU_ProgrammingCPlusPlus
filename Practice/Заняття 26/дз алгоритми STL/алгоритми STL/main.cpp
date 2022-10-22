#include <iostream>
#include "goods.h"
#include <vector>
#include <algorithm>
#include "functions.h"
#include <map>
using namespace std;

int main()
{
	vector<Goods> myGoods; readGoodsFromFile(myGoods, "goodsInfo.txt");

	GoodsPrinterClass goodsPrinter;

	for_each(myGoods.cbegin(), myGoods.cend(), printGoods); cout << "\n";
	for_each(myGoods.cbegin(), myGoods.cend(), goodsPrinter); cout << "\n";
	for_each(myGoods.cbegin(), myGoods.cend(), [](const Goods& goods) { cout << goods << "\n"; }); cout << "\n";
	cout << "______________________________________\n\n";

	GoodsCategoryPrinterClass categoryPrinter;

	string vegetable = "Vegetables";
	int nofVegetables = count_if(myGoods.cbegin(), myGoods.cend(), [vegetable](const Goods& goods) { return goods.getCategory() == vegetable; });
	cout << "Shop of " << nofVegetables << " vegetables. \n" << vegetable << ".\n";


	vector<Goods> vegetablesGoods(nofVegetables);
	copy_if(myGoods.cbegin(), myGoods.cend(), vegetablesGoods.begin(), [vegetable](const Goods& goods) { return goods.getCategory() == vegetable; });
	for_each(vegetablesGoods.cbegin(), vegetablesGoods.cend(), categoryPrinter);  cout << "\n";

	double vegetablesPrice = 0.0;
	for_each(vegetablesGoods.begin(), vegetablesGoods.end(), [&](const Goods& goods) { vegetablesPrice += goods.getPrice(); });
	cout << "Total price: " << vegetablesPrice << " hrn.\n";
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	string fruits = "Fruits";
	int nofFruits = count_if(myGoods.cbegin(), myGoods.cend(), [fruits](const Goods& goods) { return goods.getCategory() == fruits; });
	cout << "Shop of " << nofFruits << " fruits. \n" << fruits << ".\n";

	vector<Goods> fruitsGoods(nofFruits);
	copy_if(myGoods.cbegin(), myGoods.cend(), fruitsGoods.begin(), [fruits](const Goods& goods) { return goods.getCategory() == fruits; });
	for_each(fruitsGoods.cbegin(), fruitsGoods.cend(), categoryPrinter); cout << "\n";


	double fruitsPrice = 0.0;
	for_each(fruitsGoods.begin(), fruitsGoods.end(), [&](const Goods& goods) { fruitsPrice += goods.getPrice(); });
	cout << "Total price: " << fruitsPrice << " hrn.\n";
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	string sweets = "Sweets";
	int nofSweets = count_if(myGoods.cbegin(), myGoods.cend(), [sweets](const Goods& goods) { return goods.getCategory() == sweets; });
	cout << "Shop of " << nofSweets << " sweets. \n" << sweets << ".\n";

	vector<Goods> sweetsGoods(nofSweets);
	copy_if(myGoods.cbegin(), myGoods.cend(), sweetsGoods.begin(), [sweets](const Goods& goods) { return goods.getCategory() == sweets; });
	for_each(sweetsGoods.cbegin(), sweetsGoods.cend(), categoryPrinter); cout << "\n";

	double sweetsPrice = 0.0;
	for_each(sweetsGoods.begin(), sweetsGoods.end(), [&](const Goods& goods) { sweetsPrice += goods.getPrice(); });
	cout << "Total price: " << sweetsPrice << " hrn.\n";
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	cout << "\nSorted by category: \n";
	sort(myGoods.begin(), myGoods.end(), compareGoodsByCategory);
	for_each(myGoods.cbegin(), myGoods.cend(), goodsPrinter); cout << "\n";
	cout << "______________________________________\n\n";

	if (vegetablesPrice < fruitsPrice && vegetablesPrice < sweetsPrice)
	{
		cout << "\nThe cheapest category : \n";
		for_each(vegetablesGoods.cbegin(), vegetablesGoods.cend(), goodsPrinter); cout << "\n";
		for_each(vegetablesGoods.begin(), vegetablesGoods.end(), [](Goods& goods) { goods.getDiscountMin(); });

		cout << "\nSorted by name:\n";
		sort(vegetablesGoods.begin(), vegetablesGoods.end(), compareGoodsByName);
		for_each(vegetablesGoods.begin(), vegetablesGoods.end(), categoryPrinter); cout << "\n";
	}
	else if (vegetablesPrice > fruitsPrice && vegetablesPrice > sweetsPrice)
	{
		cout << "\nThe most expensive category : \n";
		for_each(vegetablesGoods.cbegin(), vegetablesGoods.cend(), goodsPrinter); cout << "\n";
		for_each(vegetablesGoods.begin(), vegetablesGoods.end(), [](Goods& goods) { goods.getDiscountMax(); });

		cout << "\nSorted by price:\n";
		sort(vegetablesGoods.begin(), vegetablesGoods.end(), compareGoodsByPrice);
		for_each(vegetablesGoods.begin(), vegetablesGoods.end(), categoryPrinter); cout << "\n";
	}
	else
	{
		auto result = minmax_element(vegetablesGoods.begin(), vegetablesGoods.end());
		cout << "Min: " << *result.first;	cout << "\n";
		cout << "Max: " << *result.second;
	}
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	if (fruitsPrice < vegetablesPrice && fruitsPrice < sweetsPrice)
	{
		cout << "\nThe cheapest category : \n";
		for_each(fruitsGoods.cbegin(), fruitsGoods.cend(), goodsPrinter); cout << "\n";
		for_each(fruitsGoods.begin(), fruitsGoods.end(), [](Goods& goods) { goods.getDiscountMin(); });

		cout << "\nSorted by name:\n";
		sort(fruitsGoods.begin(), fruitsGoods.end(), compareGoodsByName);
		for_each(fruitsGoods.begin(), fruitsGoods.end(), goodsPrinter); cout << "\n";
	}
	else if (fruitsPrice > vegetablesPrice && fruitsPrice > sweetsPrice)
	{
		cout << "\nThe most expensive category : \n";
		for_each(fruitsGoods.cbegin(), fruitsGoods.cend(), goodsPrinter); cout << "\n";
		for_each(fruitsGoods.begin(), fruitsGoods.end(), [](Goods& goods) { goods.getDiscountMax(); });

		cout << "\nSorted by price:\n";
		sort(fruitsGoods.begin(), fruitsGoods.end(), compareGoodsByPrice);
		for_each(fruitsGoods.begin(), fruitsGoods.end(), goodsPrinter); cout << "\n";
	}
	else
	{
		auto result = minmax_element(fruitsGoods.begin(), fruitsGoods.end());
		cout << "Min: " << *result.first;	cout << "\n";
		cout << "Max: " << *result.second;
	}
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	if (sweetsPrice < fruitsPrice && sweetsPrice < vegetablesPrice)
	{
		cout << "\nThe cheapest category : \n"; 
		for_each(sweetsGoods.cbegin(), sweetsGoods.cend(), goodsPrinter); cout << "\n";
		for_each(sweetsGoods.begin(), sweetsGoods.end(), [](Goods& goods) { goods.getDiscountMin(); });

		cout << "\nSorted by name:\n";
		sort(sweetsGoods.begin(), sweetsGoods.end(), compareGoodsByName);
		for_each(sweetsGoods.begin(), sweetsGoods.end(), goodsPrinter); cout << "\n";
	}
	else if (sweetsPrice > fruitsPrice && sweetsPrice > vegetablesPrice)
	{
		cout << "\nThe most expensive category : \n";
		for_each(sweetsGoods.cbegin(), sweetsGoods.cend(), goodsPrinter); cout << "\n";
		for_each(sweetsGoods.begin(), sweetsGoods.end(), [](Goods& goods) { goods.getDiscountMax(); });

		cout << "\nSorted by price:\n";
		sort(sweetsGoods.begin(), sweetsGoods.end(), compareGoodsByPrice);
		for_each(sweetsGoods.begin(), sweetsGoods.end(), goodsPrinter); cout << "\n";
	}
	else
	{
		auto result = minmax_element(sweetsGoods.begin(), sweetsGoods.end());
		cout << "Min: " << *result.first;	cout << "\n";
		cout << "Max: " << *result.second;
	}	
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	cout << "\n";
	system("pause");
	return 0;
}