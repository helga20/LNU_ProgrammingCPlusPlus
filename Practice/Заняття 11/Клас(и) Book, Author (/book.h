#pragma once
#include <iostream>
#include <string>
#include "author.h"
using namespace std;

class Book
   {
   private:
      //string author;
      Author writer;
      string title;
      double price;

   public:
      Book();
      Book(const Author &auth, const string &ttl, double prc);
      Book(const Book &B);
      ~Book();

      // методи доступу до значень полів - "гетери"
      Author getAuthor() const;
      string getTitle() const;
      double getPrice() const;
      // методи доступу до самих полів
      Author &getAuthor();
      string &getTitle();
      double &getPrice();
      // методи модифікації значення полів - "сетери"
      void setAuthor(const Author& writerValue);
      void setTitle(const string& titleValue);
      void setPrice(double priceValue);

      void printInfo() const;

      // методи роботи з потоками
      void readFrom(istream &in);
      void writeTo(ostream &out) const;

      // оператори
      bool operator<(const Book &B) const;
   };

istream& operator>>(istream &in, Book &B);
ostream& operator<<(ostream &out, const Book &B);

void printBookArray(Book *arr, int n);
double totalBookPrice(Book *arr, int n);
Book maxBook(Book *arr, int n);

