#include <iostream>
#include "functions.h"
#include "book.h"
#include "intvector.h"
using namespace std;

int main()
   {
   IntVector myV(5);
   myV.pushBack(3);
   myV.pushBack(9);
   myV.pushBack(6);
   myV.pushBack(1);
   myV.pushBack(8);
   cout << "Max size: " << myV.getSize() << "\n";
   cout << "Current lenght: " << myV.getLenght() << "\n";
   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
      {
      cout << myV.at(i) << " ";
      }
   cout << "\n";


   try
      {
      cout << "\nAdd one more element: ";
      int a; cin >> a;
      myV.pushBack(a);
      }
   catch (FullVectorException e)
      {
      e.report();
      }

   cout << "\nLets delete 3 last elements: " << myV.popBack() << " " << myV.popBack() << " " <<  myV.popBack() << "\n";
   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
      {
      cout << myV.at(i) << " ";
      }
   cout << "\n";

   try
      {
      cout << "\nTry access 5th element: ";
      cout << myV.at(5);
      }
   catch (InvalidIndexException e)
      {
      e.report();
      }

   try
      {
      cout << "\nTest pop 3 more ";
      cout << myV.popBack() << " " <<  myV.popBack() << " " <<  myV.popBack();
      }
   catch (EmptyVectorException e)
      {
      e.report();
      }

   cout << "\n-----------------------\n";
   cout << "Max size: " << myV.getSize() << "\n";
   cout << "Current lenght: " << myV.getLenght() << "\n";






















   /*
   Book B1("Prata", "C++", 366.5);
   cout << "B1: " << B1 << '\n';

   cout << "\nTest set author\n";
   try
      {
      B1.setAuthor("");
      cout << "New B1: " << B1 << "\n";
      }
   catch (BookEmptyFieldException BE)
      {
      BE.report();
      }

   cout << "\nTest set title\n";
   try
      {
      B1.setTitle("");
      cout << "New B1: " << B1 << "\n";
      }
   catch (BookEmptyFieldException BE)
      {
      BE.report();
      }

   cout << "\nTest set price\n";
   try
      {
      B1.setPrice(-50);
      cout << "New B1: " << B1 << "\n";
      }
   catch (BookPriceException BP)
      {
      BP.report();
      }

   cout << "After all B1: " << B1 << "\n";


   */




   /*
   double x, y;
   cout << "Enter two doubles\n";
   cin >> x >> y;

   cout << "\nTry divide\n";
   try
      {
      double f = getFraction(x, y);
      cout << "Divide: " << f << '\n';
      }
   catch (const char *err)
      {
      cout << "ERROR. " << err << "\n";
      }
   catch (DivisionException DE)
      {
      DE.report();
      }
   catch (...)
      {
      cout << "Unknown ERROR...\n";
      }

   cout << "\nTry average\n";
   try
      {
      double avg = getAverage(x, y);
      cout << "Average: " << avg << "\n";
      }
   catch (const char *err)
      {
      cout << "ERROR. " << err << "\n";
      }
   catch (ArgumentException AE)
      {
      AE.report();
      }
   //catch (double val)
   //   {
   //   cout << "ERROR. Operand value " << val << " is not accepted\n";
   //   }
   */

   cout << "\n";
   system("pause");
   return 0;
   }
