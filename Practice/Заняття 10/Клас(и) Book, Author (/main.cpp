#include <iostream>
#include <fstream>
#include "book.h"
#include "author.h"
using namespace std;

int main()
   {
   /*
   Author A1("Sviatoslav", "Tarasiuk", "Ukraine");
   //A1.print();
   //cout << "\nEnter author\n";
   Author A2("Serhii", "Yaroshko", "Ukraine");
   //cin >> A2;
   //cout << A2;

   Book B1;
   Book B2(A2, "Programming", 100.0);
   Book B3(B2);
   cout << "\n";

   // виводимо інформацію про книжки на екран
   cout << "Book info\n";
   // спосіб 1 - через get-ери
   cout << B2.getAuthor() << " " << B2.getTitle() << ". " << B2.getPrice() << "\n";
   // спосіб 2 - через метод
   B1.printInfo();
   B3.printInfo();

   cout << "\nTry getters\n";
   B1.getAuthor() = A1;
   B1.getTitle() = "MatAn";
   B1.getPrice() = 150;
   B1.printInfo();

   B3.setTitle("Algorithms");
   B3.setPrice(90);
   B3.printInfo();

//   double prc;
//   cout << "\nEnter new price: "; cin >> prc;
//   B3.setPrice(prc);
//   B3.printInfo();


   // read/write to/from streams
   Book B4(Author("Yurii", "Shcherbyna", "Ukraine"), "Dyskretna", 156);
   //cout << "\nEnter book info:\n";
   //cin >> B4;
   //cout << "Here is your Book\n" << B4 << "\n";

   // робота з масивами
   cout << "\n\n";
   const int n = 4;
   Book myArray[4] = {B1, B2, B3, B4};
   printBookArray(myArray, n);
   double totalPrice = totalBookPrice(myArray, n);
   cout << "Total price: " << totalPrice << "\n";
   Book B5 = maxBook(myArray, n);
   cout << "Most expensive ";
   B5.printInfo();
   */

   // читання з файлу
   ifstream iFile("books_info.txt");
   int size; iFile >> size;
   Book *fileArray = new Book[size];
   for (int i = 0; i < size; ++i)
      {
      //iFile >> fileArray[i];
      fileArray[i].readFrom(iFile);
      }
   iFile.close();
   cout << "\nBooks from file\n";
   printBookArray(fileArray, size);

   // записати книжку у відаповідний файл. який визначається країною походження автора книжки
   ofstream ukFile("UK_books.txt");
   ofstream usaFile("USA_books.txt");
   ofstream ukraineFile("Ukraine_books.txt");
   for (int i = 0; i < size; ++i)
      {
      Author currAuth = fileArray[i].getAuthor();
      string currCountry = currAuth.getCountry();
      //string temp = fileArray[i].getAuthor().getCountry();
      if (fileArray[i].getAuthor().getCountry() == "UK")
         {
         fileArray[i].writeTo(ukFile);
         ukFile << "\n";
         }
      else if (currCountry == "USA")
         {
         usaFile<< fileArray[i] << "\n";
         }
      else
         {
         fileArray[i].writeTo(ukraineFile);
         ukraineFile << "\n";
         }
      }
   cout << "\nCheck the files\n";


   ukFile.close();
   usaFile.close();
   ukraineFile.close();
   
   delete [] fileArray;

   cout << "\n";
   return 0;
   }
