#pragma once
#include <iostream>
#include "goods.h"
using namespace std;

void printGoods(const Goods& goods)
{
	cout << goods << '\n';
}

class GoodsPrinterClass
{
public:
	void operator() (const Goods& goods)
	{
		goods.printInfo();
	}
};

class GoodsCategoryPrinterClass
{
public:
	void operator() (const Goods& goods)
	{
		goods.printCategoryInfo();
	}
};

bool compareGoodsByCategory(const Goods& goodsLeft, const Goods& goodsRight)
{
	return goodsLeft.getCategory() < goodsRight.getCategory();
}

bool compareGoodsByPrice(const Goods& goodsLeft, const Goods& goodsRight)
{
	return goodsLeft.getPrice() < goodsRight.getPrice();
}

bool compareGoodsByName(const Goods& goodsLeft, const Goods& goodsRight)
{
	return goodsLeft.getName() < goodsRight.getName();
}
