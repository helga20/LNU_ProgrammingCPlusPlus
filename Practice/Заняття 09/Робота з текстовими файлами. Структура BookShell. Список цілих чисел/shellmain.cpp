//#include <iostream>
//#include <fstream>
//#include <string>
//#include "book.h"
//#include "bookshell.h"
//using namespace std;
//
//int main()
//{
//	ifstream iFile("bookinfo.txt");
//	Book B1, B2, B3;
//	iFile >> B1 >> B2 >> B3;
//	iFile.close();
//
//	// Put books on a shell
//	BookShell allBooks("All", 3);
//	//allBooks.shell[0] = B1; allBooks.nofBooks += 1;
//	//allBooks.shell[1] = B2; allBooks.nofBooks += 1;
//	//allBooks.shell[2] = B3; allBooks.nofBooks += 1;
//	addBook(B1, allBooks);
//	addBook(B2, allBooks);
//	addBook(B3, allBooks);
//	addBook(B1, allBooks); // error
//	printShell(allBooks);
//	cout << "Total price: " << shellPrice(allBooks) << "\n\n";
//
//	// Only programming books
//	BookShell progBooks("Programming", 5);
//	//progBooks.shell[0] = B2; progBooks.nofBooks += 1;
//	//progBooks.shell[1] = B3; progBooks.nofBooks += 1;
//	addBook(B2, progBooks);
//	addBook(B3, progBooks);
//	printShell(progBooks);
//	cout << "Total price: " << shellPrice(progBooks) << "\n\n";
//
//	// Shell from file
//	BookShell fileShell;
//	readShellFromFile("univerbooks.txt", fileShell);
//	cout << "\n   Books from file\n";
//	printShell(fileShell);
//	cout << "Total price: " << shellPrice(fileShell) << "\n\n";
//
//	// Sort shells
//	sortShell(fileShell);
//	cout << "\n   Sorted shell\n";
//	printShell(fileShell);
//	cout << "\n";
//	sortShellByAuthor(fileShell);
//	printShell(fileShell);
//	cout << "\n";
//
//	// Sort by
//	cout << "\n   By Title\n";
//	sortShellBy(fileShell, compareTitles);
//	printShell(fileShell);
//
//	cout << "\n   By Price\n";
//	sortShellBy(fileShell, comparePrices);
//	printShell(fileShell);
//
//	cout << "\n   By Author\n";
//	sortShellBy(fileShell, compareAuthors);
//	printShell(fileShell);
//	cout << "\n";
//
//	system("pause");
//	return 0;
//}