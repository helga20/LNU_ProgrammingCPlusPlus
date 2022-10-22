#include <iostream>
#include "book.h"
using namespace std;

int main()
{
	Book B1; // конструктор за замовчуванням
	printBook(B1);
	cout << "\n";

	B1.author = "Steven Prata";
	B1.title = "C++";
	B1.price = 156.5;
	printBook(B1);
	cout << "\n\n";
		
//	{
		Book B3("Brius Ekkel", "Program in C++", 355.); // конструктор за значенням
		printBook(B3);	
//	}

//	{
		cout << "\n\n";
		Book B4(B1); // конструктор копіювання
		B4.author = "Steven Prata";
		printBook(B4);
//	}
	cout << "\n\n";


	cout << "\nNew book\n";
	Book B2;
	readBook(B2);
	//cout << "Enter author: ";
	//cin >> B2.author;
	//cout << "Enter title: ";
	//cin >> B2.title;
	//cout << "Enter price: ";
	//cin >> B2.price;
	printBook(B2);


	// читання-виведення на екран екземплярів типу Book
	cout << "\nRead-Write Book\n";
	Book B5;
	cout << "Enter Book\n";
	cin >> B5;
	cout << "Your Book: " << B5 << "\n";

	cout << "\n\n";
	const int n = 5;
	Book shop[n] = { B1, B2, B3, B4, B5 };
	printBookArray(shop, n);
	cout << "Total price: " << totalPrice(shop, n) << "\n";
	cout << "Most expensive Book: " << mostExpensiveBook(shop, n) << "\n";
	cout << "Cheapest Book:       " << cheapestBook(shop, n) << "\n";
	cout << "Books of Prata: " << totalAuthorPrice("Steven Prata", shop, n) << "\n\n";

	system("pause");
	return 0;
}