#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Book
{
	string author;
	string title;
	double price;

	// конструктори
	// за замовчуванням
	Book() : author("No author"), title("No title"), price(0.0)
	{
		//cout << "Book. Default\n";
	}

	// з параметрами == за значенням
	Book(string auth, string ttl, double prc) : author(auth), title(ttl), price(prc)
	{
		//cout << "Book. Parameter\n";
	}

	// копіювання
	Book(const Book& B) : author(B.author), title(B.title), price(B.price)
	{
		//cout << "Book. Copy\n";
	}

	~Book()
	{
		//cout << "Book. Destructor\n";
	}
};

void readBook(Book& B);
void printBook(const Book& B);

istream& operator>>(istream& in, Book &B);
ostream& operator<<(ostream& out, const Book& B);
bool operator<(const Book& B1, const Book& B2);

void printBookArray(Book* arr, const int n);
double totalPrice(Book* arr, const int n);
Book mostExpensiveBook(Book* arr, const int n);
Book cheapestBook(Book* arr, const int n);
double totalAuthorPrice(string auth, Book* arr, const int n);