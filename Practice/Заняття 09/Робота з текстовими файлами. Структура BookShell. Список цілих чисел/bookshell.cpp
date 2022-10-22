#include "bookshell.h"
#include <fstream>

void printShell(const BookShell& BS)
{
	cout << BS.genre << "\n";
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		cout << BS.shell[i] << "\n";
	}
}

void addBook(const Book& B, BookShell& BS)
{
	if (BS.nofBooks < BS.maxSize)
	{
		BS.shell[BS.nofBooks] = B;
		++BS.nofBooks;
	}
	else
	{
		cout << "Sorry. BookShell is full\n";
	}	
}

void readShellFromFile(const string& fileName, BookShell& BS)
{
	ifstream iFile(fileName);
	iFile >> BS.genre;
	iFile >> BS.nofBooks;
	BS.maxSize = BS.nofBooks * 2;
	BS.shell = new Book[BS.maxSize];
	
	// read Books
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		//Book B;
		//iFile >> B;
		//BS.shell[i] = B;

		iFile >> BS.shell[i];
	}

	iFile.close();
}

double shellPrice(const BookShell& BS)
{
	double sum = 0.0;
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		sum += BS.shell[i].price;
	}
	return sum;
}

void sortShell(BookShell& BS)
{
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		for (int j = i + 1; j < BS.nofBooks; ++j)
		{
			if (BS.shell[j] < BS.shell[i])
			{
				Book temp = BS.shell[i];
				BS.shell[i] = BS.shell[j];
				BS.shell[j] = temp;
			}
		}
	}
}

void sortShellByAuthor(BookShell& BS)
{
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		for (int j = i + 1; j < BS.nofBooks; ++j)
		{
			if (BS.shell[j].author < BS.shell[i].author)
			{
				Book temp = BS.shell[i];
				BS.shell[i] = BS.shell[j];
				BS.shell[j] = temp;
			}
		}
	}
}

void sortShellBy(BookShell& BS, bool (*fCompare)(const Book&, const Book&))
{
	for (int i = 0; i < BS.nofBooks; ++i)
	{
		for (int j = i + 1; j < BS.nofBooks; ++j)
		{
			if (fCompare(BS.shell[j], BS.shell[i]))
			{
				Book temp = BS.shell[i];
				BS.shell[i] = BS.shell[j];
				BS.shell[j] = temp;
			}
		}
	}
}