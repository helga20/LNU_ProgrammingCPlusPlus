#pragma once
#include <forward_list>
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include "fruit.h"
using namespace std;

template <typename TVal>
void printListInRow(const forward_list<TVal>& myList)
{
	for (auto it = myList.cbegin(); it != myList.cend(); ++it)
	{
		cout << *it << ' ';
	}
	cout << "\n";
}

template <typename TVal>
void modifyList(forward_list<TVal>& myList, TVal coef)
{
	for (auto it = myList.begin(); it != myList.end(); ++it)
	{
		(*it) *= coef;
	}
}

template <typename TVal>
void printStackInRow(stack<TVal>& myStack)
{
	while (!myStack.empty())
	{
		cout << myStack.top() << ' ';
		myStack.pop();
	}
	cout << "\n";
}

template <typename TVal>
void readStackFromFile(stack<TVal>& myStack, const string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		TVal temp; iFile >> temp;
		myStack.push(temp);
	}
	iFile.close();
}

void printFruitsBasket(const forward_list<Fruit*>& basket)
{
	for (auto it = basket.cbegin(); it != basket.cend(); ++it)
	{
		(*it)->print();
		cout << "\n";
	}
	cout << "\n";
}