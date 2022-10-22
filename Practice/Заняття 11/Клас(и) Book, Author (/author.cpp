#include "author.h"

Author::Author(const string& nm, const string& srnm, const string& cntr)
   : name(nm), surname(srnm), country(cntr)
   {
   }

Author::Author(const Author& A)
   : name(A.name), surname(A.surname), country(A.country)
   {
   }

Author::~Author()
   {
   }

void Author::print() const
   {
   cout << "Author: " << name << " " << surname << " (" << country << ")\n";
   }

void Author::readFrom(istream& in)
   {
   in >> name >> surname >> country;
   }

void Author::writeTo(ostream& out) const
   {
   out << name << ' ' << surname << ' ' << country;
   }

string Author::getCountry() const
   {
   return country;
   }

istream& operator>>(istream& in, Author& A)
   {
   A.readFrom(in);
   return in;
   }

ostream& operator<<(ostream& out, const Author& A)
   {
   A.writeTo(out);
   return out;
   }
