#include "book.h"
#include <iostream>
using namespace std;

void readBook(Book& B)
{
	cout << "Enter book info\n";
	cout << "Enter author: "; cin >> B.author;
	cout << "Enter title: "; cin >> B.title;
	cout << "Enter price: "; cin >> B.price;
}

void printBook(const Book& B)
{
	cout << "Book info\n";
	cout << "Author: " << B.author << "\n";
	cout << "Title: " << B.title << "\n";
	cout << "Price: " << B.price << "\n";
}

istream& operator>>(istream& in, Book& B)
{
	in >> B.author >> B.title >> B.price;
	return in;
}

ostream& operator<<(ostream& out, const Book& B)
{
	out << B.author << ' ' << B.title << ' ' << B.price;
	return out;
}

bool operator<(const Book& B1, const Book& B2)
{
	return B1.price < B2.price;
}

void printBookArray(Book* arr, const int n)
{
	cout << "Books array\n";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\n";
	}
	cout << "\n";
}

double totalPrice(Book* arr, const int n)
{
	double totalSum = 0.;
	for (int i = 0; i < n; ++i)
	{
		totalSum += arr[i].price;
	}
	return totalSum;
}

Book mostExpensiveBook(Book* arr, const int n)
{
	Book maxBook = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].price > maxBook.price)
		{
			maxBook = arr[i];
		}
	}
	return maxBook;
}

Book cheapestBook(Book* arr, const int n)
{
	Book minBook = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < minBook)
		{
			minBook = arr[i];
		}
	}
	return minBook;
}

double totalAuthorPrice(string auth, Book* arr, const int n)
{
	double totalSum = 0.;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].author == auth)
		{
			totalSum += arr[i].price;
		}
	}
	return totalSum;
}
