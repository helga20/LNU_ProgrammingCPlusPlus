#include <iostream>
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
      cout << "\nAdd one more back element: ";
      int a; cin >> a;
      myV.pushBack(a);
      }
   catch (FullVectorException e)
      {
      e.report();
      }
   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
   {
       cout << myV.at(i) << " ";
   }
   cout << "\n";

   try
   {
       cout << "\nAdd one more front element: ";
       int b; cin >> b;
       myV.pushFront(b);
   }
   catch (FullVectorException e)
   {
       e.report();
   }
   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
   {
       cout << myV.at(i) << " ";
   }
   cout << "\n";

   cout << "\nLets delete first element: "; myV.popFront();

   cout << "\nVector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
   {
       cout << myV.at(i) << " ";
   }
   cout << "\n";

   cout << "\nLets delete 2 last elements: " << myV.popBack() << " " << myV.popBack() << "\n";

   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
      {
      cout << myV.at(i) << " ";
      }
   cout << "\n";

   try
   {
       cout << "\nAdd one more back element: ";
       int d; cin >> d;
       myV.pushBack(d);
   }
   catch (FullVectorException e)
   {
       e.report();
   }
   cout << "Vector: ";
   for (size_t i = 0; i < myV.getLenght(); ++i)
   {
       cout << myV.at(i) << " ";
   }
   cout << "\n";

   try
   {
       cout << "\nAdd one more front element: ";
       int c; cin >> c;
       myV.pushFront(c);
   }
   catch (FullVectorException e)
   {
       e.report();
   }
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
      cout << "\nTest pop 5 more\n";
      cout << myV.popBack() << " " <<  myV.popBack() << " " <<  myV.popBack() << " " << myV.popBack() << " " << myV.popBack();
      }
   catch (EmptyVectorException e)
      {
      e.report();
      }

   try
   {
       cout << "\n Pop front from empty vector\n";
       myV.popBack();
   }
   catch (EmptyVectorException e)
   {
       e.report();
   }

   cout << "\n-----------------------\n";
   cout << "Max size: " << myV.getSize() << "\n";
   cout << "Current lenght: " << myV.getLenght() << "\n";

   cout << "\n";
   system("pause");
   return 0;
   }
