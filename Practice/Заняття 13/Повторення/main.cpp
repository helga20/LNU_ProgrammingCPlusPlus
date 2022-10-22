#include <iostream>
#include "functions.h"
#include "card.h"
using namespace std;

int main()
   {
   //task1_a();

   // task1_b
   //cout << "Task 1 b\n";
   //double x; int n;
   //cout << "Enter x: "; cin >>x;
   //cout << "Enter n: "; cin >> n;
   //double res = calcPowX(x, n);
   //cout << "Result: " << res << "\n\n";

   // task 1_c
   //cout << "Task 1 c\n";
   //double x, eps;
   //cout << "Enter x: "; cin >> x;
   //cout << "Enter eps: "; cin >> eps;
   //double res = calcSumEps(x, eps);
   //cout << "Result: " << res << "\n\n";

   //task2();

   Card H_6("Heart", 6);
   Card H_K("Heart", 'K');
   Card H_9("Heart", 9);
   Card P_V("Pika", 'V');
   Card P_8("Pika", 6);
   Card B_A("Bubna", 'A');
   cout << "Two cards\n";
   const size_t n = 6;
   Card cards[n] = {H_6, P_8, H_9, B_A, H_K, P_V};
   printCardsArray(cards, n);
   cout << "Sort...\n";
   sortCardsArray(cards, n);
   printCardsArray(cards, n);

//   cout << H_6.type << ": " << H_6.value << ";  ";
//   cout << H_K.type << ": " << H_K.value << "\n";
   //printCard(H_6); cout << ";   ";
   //printCard(test1); cout << ";   ";
   //printCard(test2); cout << ";   ";
   //printCard(H_K); cout << "\n";

   cout << "\n";
   return 0;
   }
