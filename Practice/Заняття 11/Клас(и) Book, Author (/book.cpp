#include "book.h"

Book::Book()
   : writer(), title(), price(0.0)
   {
   //cout << "Default Book\n";
   }

Book::Book(const Author& auth, const string& ttl, double prc)
   : writer(auth), title(ttl), price(prc)
   {
   //cout << "Parameters Book\n";
   }

Book::Book(const Book& B)
   : writer(B.writer), title(B.title), price(B.price)
   {
   //cout << "Copy Book\n";
   }

Book::~Book()
   {
   //cout << "Destroy Book: " << author << "\n";
   }

Author Book::getAuthor() const
   {
   return this->writer;
   //return author; // повертаємо значення поля author
   }

string Book::getTitle() const
   {
   return title;
   }

double Book::getPrice() const
   {
   return price;
   }

void Book::printInfo() const
   {
   //cout << "Book info\n";
   writer.print();
   cout << title << ". " << price << " uah\n";
   }

Author& Book::getAuthor()
   {
   return writer;
   }

string& Book::getTitle()
   {
   return title;
   }

double& Book::getPrice()
   {
   return price;
   }

void Book::setAuthor(const Author& writerValue)
   {
   writer = writerValue;
   }

void Book::setTitle(const string& titleValue)
   {
   if (titleValue.empty())
      {
      cout << "Error: title cannnot be empty.\n";
      return;
      }

   title = titleValue;
   }

void Book::setPrice(double priceValue)
   {
   if (priceValue < 0)
      {
      cout << "Error: price " << priceValue << " not accepted\n";
      return;
      }

   price = priceValue;
   }

void Book::readFrom(istream& in)
   {
   in >> writer >> title >> price;
   }

void Book::writeTo(ostream& out) const
   {
   out << writer << ' ' << title << ' ' << price;
   }

bool Book::operator<(const Book& B) const
   {
   return price < B.getPrice();
   }

istream& operator>>(istream& in, Book& B)
   {
   // option 1 - via setter
   /*
   string auth; in >> auth; B.setAuthor(auth);
   string ttl; in >> ttl; B.setTitle(ttl);
   double prc; in >> prc; B.setPrice(prc);
   */

   // option 2 - via getter
   //in >> B.getAuthor() >> B.getTitle() >> B.getPrice();

   // option 3 - via method
   B.readFrom(in);
   return in;
   }

ostream& operator<<(ostream& out, const Book& B)
   {
   // option 1 - via getters
   //out << B.getAuthor() << ' ' << B.getTitle() << ' ' << B.getPrice();

   // option 2 - via method
   B.writeTo(out);
   return out;
   }

void printBookArray(Book* arr, int n)
   {
   cout << "Array of Books\n";
   cout << "----------------------------------\n";
   for (int i = 0; i < n; ++i)
      {
      arr[i].printInfo();
      cout << "\n";
      }
   cout << "----------------------------------\n";
   }

double totalBookPrice(Book* arr, int n)
   {
   double sum = 0;
   for (int i = 0; i < n; ++i)
      {
      sum += arr[i].getPrice();
      }
   return sum;
   }

Book maxBook(Book* arr, int n)
   {
   Book maxB = arr[0];
   for (int i = 1; i < n; ++i)
      {
      //if (maxB.getPrice() < arr[i].getPrice())
      if (maxB < arr[i])
         {
         maxB = arr[i];
         }
      }
   return maxB;
   }
