#pragma once
#include <iostream>
#include <string>
using namespace std;

class Author
   {
   private:
      string name;
      string surname;
      string country;

   public:
      Author(const string &nm = "", const string &srnm = "", const string &cntr = "");
      Author(const Author &A);
      ~Author();

      void print() const;
      void readFrom(istream &in);
      void writeTo(ostream &out) const;

      string getCountry() const;
   };

istream& operator>>(istream &in, Author &A);
ostream& operator<<(ostream &out, const Author &A);
