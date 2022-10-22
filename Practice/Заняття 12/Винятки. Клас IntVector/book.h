#pragma once
#include <iostream>
#include <string>
using namespace std;

class BookEmptyFieldException
   {
   private:
      string fieldName;
   public:
      BookEmptyFieldException(const string &field);
      void report() const;
   };

class BookPriceException
   {
   private:
      double priceValue;
   public:
      BookPriceException(double price);
      void report() const;
   };

class Book
   {
   private:
      string author;
      string title;
      double price;

   public:
      Book(const string &auth, const string &ttl, double prc);

      // методи модифікації значення полів - "сетери"
      void setAuthor(const string& writerValue); /* throw (BookEmptyFieldException);*/
      void setTitle(const string& titleValue); //throw (BookEmptyFieldException);
      void setPrice(double priceValue); //throw (BookPriceException);

      // методи роботи з потоками
      void readFrom(istream &in);
      void writeTo(ostream &out) const;
   };

istream& operator>>(istream &in, Book &B);
ostream& operator<<(ostream &out, const Book &B);


