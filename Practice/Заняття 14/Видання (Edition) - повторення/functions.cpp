#include "functions.h"
#include <iostream>
using namespace std;

void printEditions(const Edition* arr, int n)
{
	cout << "All Editions\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i].print();
	}
	cout << "\n";
}

void printEditionsByAuthor(const Edition *arr, int n, const std::string& authorName)
{
	cout << "Editions of author " << authorName << "\n";
	bool hasAuthor = false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].getAuthor() == authorName)
		{
			hasAuthor = true;
			arr[i].print();
		}		
	}
	if (!hasAuthor)
	{
		cout << "Sorry. No editions found.\n";
	}
	cout << "\n";
}

void printEditionsByPagePrice(const Edition* arr, int n, double pagePrice)
{
	cout << "Editions with page price greater than " << pagePrice << "\n";
	bool editionFound = false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].pagePrice() >= pagePrice)
		{
			editionFound = true;
			arr[i].print();
		}
	}
	if (!editionFound)
	{
		cout << "Sorry. No editions found.\n";
	}
	cout << "\n";
}

double totalPrice(const Edition* arr, int n)
{
	double totPrice = 0.;
	for (int i = 0; i < n; ++i)
	{
		totPrice += arr[i].getPrice();
	}
	return totPrice;
}

const Edition& findMostExpensiveEdition(const Edition* arr, int n)
{
	int maxIndex = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}
	return arr[maxIndex];
}

int findCheapestEditionByPagePrice(const Edition* arr, int n)
{
	int minIndex = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].pagePrice() < arr[minIndex].pagePrice())
		{
			minIndex = i;
		}
	}
	return minIndex;
}

void sortByPrice(Edition* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[i]) // arr[j].getPrice() < arr[i].getPrice()
			{
				Edition temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void sortByAuthor(Edition* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j].getAuthor() < arr[i].getAuthor())
			{
				Edition temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}