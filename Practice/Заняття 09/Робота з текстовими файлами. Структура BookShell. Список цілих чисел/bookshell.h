#pragma once
#include "book.h"
#include <iostream>
#include <string>
using namespace std;

struct BookShell
{
	string genre;
	int maxSize;  // total possible size
	int nofBooks; // number of filled in books
	Book* shell;

	BookShell() : genre(), maxSize(0), nofBooks(0), shell(nullptr) {}
	BookShell(const string &type, int size) : genre(type), maxSize(size), nofBooks(0), shell(new Book[size])
	{
		//shell = new Book[size];
	}
	~BookShell()
	{
		if (shell != nullptr)
		{
			delete[] shell;
		}
	}
};

void printShell(const BookShell& BS);
void addBook(const Book& B, BookShell& BS);
void readShellFromFile(const string& fileName, BookShell& BS);
double shellPrice(const BookShell& BS);
void sortShell(BookShell& BS); // sort Books by default (operator <)
void sortShellByAuthor(BookShell& BS);
void sortShellBy(BookShell& BS, bool (*fCompare)(const Book&, const Book&));