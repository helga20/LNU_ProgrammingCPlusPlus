#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "book.h"
using namespace std;

void printVector(const vector<int>& myV)
{
	for (size_t i = 0; i < myV.size(); ++i)
	{
		cout << myV.at(i) << ' ';
		//cout << myV[i] << ' ';
	}
	cout << "\n";
}

template <typename T>
void printVectorIterator(const vector<T>& myV)
{
	//for (vector<int>::const_iterator it = myV.cbegin(); it != myV.cend(); ++it)
	for (auto it = myV.cbegin(); it != myV.cend(); ++it)
	{
		cout << *it << "\n";
	}
	cout << "\n---------------------------------------\n";
}

void printReverse(const vector<int>& myV)
{
	//for (vector<int>::const_reverse_iterator rIt = myV.crbegin(); rIt != myV.crend(); ++rIt)
	for (auto rIt = myV.crbegin(); rIt != myV.crend(); ++rIt)
	{
		cout << *rIt << ' ';
	}
	cout << "\n";
}

void readVectorFixedSize(vector<int>& myV, const string& fileName)
{
	ifstream iFile(fileName);
	size_t n; iFile >> n;
	myV.resize(n);
	//for (size_t i = 0; i < n; ++i)
	//{
	//	iFile >> myV[i];
	//}

	for (auto it = myV.begin(); it != myV.end(); ++it)
	{
		iFile >> *it;
	}

	iFile.close();
}

template <typename TVal>
void readVector(vector<TVal>& myV, const string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		TVal val; iFile >> val;
		myV.push_back(val);
	}
	iFile.close();
}


vector<Book>::iterator findMaxBook(vector<Book>& myV)
{
	size_t maxIndex = 0;
	for (size_t i = 1; i < myV.size(); ++i)
	{
		if (myV[i].getPrice() > myV[maxIndex].getPrice())
		{
			maxIndex = i;
		}
	}
	return myV.begin() + maxIndex;
}

