#pragma once
#include <string>
using namespace std;

// 6-10, V (11), D (12), K (13), A (14)
struct Card
   {
   string type;
   int value;

   Card(const string& cardType, int cardValue)
      : type(cardType), value(cardValue)
      {
      }
   Card(const string& cardType, char cardValue)
      : type(cardType)
      {
      switch (cardValue)
         {
         case 'V':
            {
            value = 11;
            break;
            }
         case 'D':
            {
            value = 12;
            break;
            }
         case 'K':
            {
            value = 13;
            break;
            }
         case 'A':
            {
            value = 14;
            break;
            }
         default:
            {
            value = 0;
            break;
            }
         }
      }
   Card(const Card& C)
      : type(C.type), value(C.value)
      {
      }
   ~Card()
      {
      }
   };

void printCard(const Card& C)
   {
   if (C.value <= 0 || C.value >= 15)
      {
      cout << "Invalid card.";
      return;
      }

   cout << C.type << ": ";
   if (C.value <= 10)
      {
      cout << C.value;
      }
   else if (C.value == 11)
      {
      cout << "Valet";
      }
   else if (C.value == 12)
      {
      cout << "Dama";
      }
   else if (C.value == 13)
      {
      cout << "Korol";
      }
   else
      {
      cout << "Ass";
      }
   }

void sortCardsArray(Card* arr, size_t n)
   {
   // sort by type
   for (size_t i = 0; i < n; ++i)
      {
      for (size_t j = i; j < n; ++j)
         {
         if (arr[j].type <= arr[i].type)
            {
            Card temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
         }
      }

   // then sort each type by value
   for (size_t i = 0; i < n; ++i)
      {
      for (size_t j = i; j < n; ++j)
         {
         if (arr[j].type == arr[i].type && arr[j].value <= arr[i].value)
            {
            Card temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
         }
      }
   }

void printCardsArray(Card* arr, size_t n)
   {
   for (size_t i = 0; i < n; ++i)
      {
      printCard(arr[i]);
      cout << "\n";
      }
   cout << "-------------------------------------\n";
   }
