#include "book.h"

BookEmptyFieldException::BookEmptyFieldException(const string &field)
   : fieldName(field)
   {}

void BookEmptyFieldException::report() const
   {
   cout << "Book Exception. The field " << fieldName << " cannot be empty.\n";
   }

// ------------------------------------------------------ //

BookPriceException::BookPriceException(double price)
   : priceValue(price)
   {}

void BookPriceException::report() const
   {
   cout << "Book Exception. Price value: " << priceValue << " is invalid.\n";
   }

// ------------------------------------------------------ //

Book::Book(const string &auth, const string &ttl, double prc)
   : author(auth), title(ttl), price(prc)
   {}

void Book::setAuthor(const string& writerValue) //throw (BookEmptyFieldException)
   {
   if (writerValue.empty())
      {
      throw BookEmptyFieldException("Author");
      }

   author = writerValue;
   }

void Book::setTitle(const string& titleValue) //throw (BookEmptyFieldException)
   {
   if (titleValue.empty())
      {
      throw BookEmptyFieldException("Title");
      }

   title = titleValue;
   }

void Book::setPrice(double priceValue) // throw (BookPriceException)
   {
   if (priceValue <= 0)
      {
      throw BookPriceException(priceValue);
      }

   price = priceValue;
   }

void Book::readFrom(istream& in)
   {
   in >> author >> title >> price;
   }

void Book::writeTo(ostream& out) const
   {
   out << author << ' ' << title << ' ' << price;
   }

istream& operator>>(istream &in, Book &B)
   {
   B.readFrom(in);
   return in;
   }

ostream& operator<<(ostream &out, const Book &B)
   {
   B.writeTo(out);
   return out;
   }
