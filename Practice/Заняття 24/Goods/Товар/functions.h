#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "goods.h"
using namespace std;

template <typename Prod>
void readVector(vector<Prod>& myG, const string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		Prod val;
		iFile >> val;
		myG.push_back(val);
	}
	iFile.close();
}

template <typename Prod>
void printVectorIterator(const vector<Prod>& myG)
{
	for (auto it = myG.cbegin(); it != myG.cend(); ++it)
	{
		cout << *it << "\n";
	}
	cout << "\n";
}

template <typename Prod>
void totalPrice(vector<Prod>& myG)
{
    double total_price = 0;
    for (size_t i = 0; i < myG.size(); ++i)
    {
        Prod obj(myG[i]);
        total_price += obj.getPrice();
    }
    if (total_price)
    {
        cout << "Total price: " << total_price << " hrn" << endl;
    }
    else
    {
        cout << "There are no goods." << endl;
    }
}

template <typename Prod>
void printCategory(const vector<Goods>& myG)
{
	cout << "\n";
	for (size_t i = 0; i < myG.size(); ++i)
	{
		myG[i].printCategoryInfo();
	}
}

