#include "goods.h"
#include "functions.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<Goods> myGoods;
	myGoods.reserve(20);
	readVector<Goods>(myGoods, "goodsInfo.txt");
	cout << "My shop (of " << myGoods.size() << " goods)\n";
	printVectorIterator<Goods>(myGoods);
	cout << "______________________________________\n\n";

	vector<Goods> vegetablesGoods;
	vegetablesGoods.reserve(myGoods.size());
	string vegetable = "Vegetables";
	for (auto it = myGoods.cbegin(); it != myGoods.cend(); ++it)
	{
		if (it->getCategory() == vegetable)
		{
			vegetablesGoods.push_back(*it);
		}
	}
	cout << "\Shop of " << vegetable << " (" << vegetablesGoods.size() << " vegetables)\n";
	printCategory<Goods>(vegetablesGoods);
	totalPrice<Goods>(vegetablesGoods);
	cout << "______________________________________\n\n";

	vector<Goods> drinksGoods;
	drinksGoods.reserve(myGoods.size());
	string drinks = "Drinks";
	for (auto it = myGoods.cbegin(); it != myGoods.cend(); ++it)
	{
		if (it->getCategory() == drinks)
		{
			drinksGoods.push_back(*it);
		}
	}
	cout << "\Shop of " << drinks << " (" << drinksGoods.size() << " drinks)\n";
	printCategory<Goods>(drinksGoods);
	totalPrice<Goods>(drinksGoods);
	cout << "______________________________________\n\n";

	vector<Goods> fruitsGoods;
	fruitsGoods.reserve(myGoods.size());
	string fruits = "Fruits";
	for (auto it = myGoods.cbegin(); it != myGoods.cend(); ++it)
	{
		if (it->getCategory() == fruits)
		{
			fruitsGoods.push_back(*it);
		}
	}
	cout << "\Shop of " << fruits << " (" << fruitsGoods.size() << " fruits)\n";
	printCategory<Goods>(fruitsGoods);
	totalPrice<Goods>(fruitsGoods);
	cout << "______________________________________\n\n";

	vector<Goods> sweetsGoods;
	sweetsGoods.reserve(myGoods.size());
	string sweets = "Sweets";
	for (auto it = myGoods.cbegin(); it != myGoods.cend(); ++it)
	{
		if (it->getCategory() == sweets)
		{
			sweetsGoods.push_back(*it);
		}
	}
	cout << "\Shop of " << sweets << " (" << sweetsGoods.size() << " sweets)\n";
	printCategory<Goods>(sweetsGoods);
	totalPrice<Goods>(sweetsGoods);
	cout << "______________________________________\n\n";

	vector<Goods> cheesesGoods;
	cheesesGoods.reserve(myGoods.size());
	string cheeses = "Cheeses";
	for (auto it = myGoods.cbegin(); it != myGoods.cend(); ++it)
	{
		if (it->getCategory() == cheeses)
		{
			cheesesGoods.push_back(*it);
		}
	}
	cout << "\Shop of " << cheeses << " (" << cheesesGoods.size() << " cheeses)\n";
	printCategory<Goods>(cheesesGoods);
	totalPrice<Goods>(cheesesGoods);
	cout << "______________________________________\n\n";

	cout << "\n";
	system("pause");
	return 0;
}