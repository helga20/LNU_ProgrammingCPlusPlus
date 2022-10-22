#include "functions.h"
#include <cmath>

double maxAB(double a, double b)
   {
   if (a >= b)
      {
      return a;
      }
   return b;
   }

double calcSqrt(double a, double b)
   {
   double val = a*a + b*b;
   return sqrt(val);
   }

void task1_a()
   {
   cout << "Task 1 a\n";
   double x, y;
   cout << "Enter a: "; cin >> x;
   cout << "Enter b: "; cin >> y;
   double m = maxAB(x, y);
   double r = calcSqrt(x, y);
   cout << "Max:  " << m << "\n";
   cout << "Sqrt: " << r << "\n";
   cout << "\n";
   }

double calcPowX(double x, int n)
   {
   // 1*x^0 + 2*x^1 + 3*x^2 + ... + n*x^(n-1) + (n+1)*x^n
   double powX = 1.0;
   double sum = 1.0;
   for (int i = 1; i <= n; ++i)
      {
      powX *= x;
      sum += (i+1)*powX;
      }
   return sum;
   }

double calcSumEps(double x, double eps)
   {
   // sum((-1^k * x^2k)/((2k)!)), k = 1; +inf
   // k = 1: -1*x^2 / 2! = -x^2/(1*2)
   // k = 2: 1*x^4 / 4! = x^4/(1*2*3*4)
   // k = 3: -1*x^6 / 6! = -x^6/(1*2*3*4*5*6)
   // k = 4: 1*x^8 / 8! = x^8/(1*2*3*4*5*6*7*8)
   double coef = -1.0;
   double x_2 = x*x;
   double powX = x_2;
   double num = coef*powX;
   double fact = 1.0 * 2.0;
   double elem = num / fact;
   double prevSum = 0.0;
   double currSum = elem;
   double k = 2.0;
   cout << k-1 << ": " << currSum << "\n";
   while (abs(currSum - prevSum) > eps)
      {
      prevSum = currSum;
      powX *= x_2;
      coef *= -1.0;
      num = coef * powX;
      fact *= (k+1.0) * (k+2.0);
      elem = num / fact;
      currSum += elem;
      cout << k << ": " << currSum << "\n";
      k += 1.0;
      }
   return currSum;
   }

bool isArrayAscending(int* arr, size_t n)
   {
   // 1 2 3 4 5 6 -> true
   // 1 2 3 5 4 -> false
   // 2 5 8 10 44 -> true
   // 2 5 10 9 44 -> false
   for (size_t i = 0; i < n - 1; ++i)
      {
      if (arr[i] > arr[i + 1])
         {
         return false;
         }
      }
   return true;
   }

bool findValue(int* arr, size_t n, int val)
   {
   for (size_t i = 0; i < n; ++i)
      {
      if (arr[i] == val)
         {
         return true;
         }
      }
   return false;
   }

size_t findValueIndex(int* arr, size_t n, int val)
   {
   for (size_t i = 0; i < n; ++i)
      {
      if (arr[i] == val)
         {
         return i;
         }
      }
   return n;
   }

void task2()
   {
   cout << "Task 2\n";
   size_t n;
   cout << "Enter size of array: "; cin >> n;
   int * myArr = new int[n];
   cout << "Enter array of " << n << " integers.\n";
   for (size_t i = 0; i < n; ++i)
      {
      cout << i+1 << ": "; cin >> myArr[i];
      }
   cout << "\nArray: ";
   for (size_t i = 0; i < n; ++i)
      {
      cout << myArr[i] << " ";
      }
   cout << "\n";

   bool isSorted = isArrayAscending(myArr, n);
   if (isSorted)
      {
      cout << "Sorted ascending\n";
      }
   else
      {
      cout << "Not sorted.\n";
      }

   int fixedValue;
   cout << "Enter value to find: "; cin >> fixedValue;
   bool findRes = findValue(myArr, n, fixedValue);
   if (findRes)
      {
      cout << "Array contains this value.\n";
      }
   else
      {
      cout << "Value not found.\n";
      }

   size_t findIndex = findValueIndex(myArr, n, fixedValue);
   if (findIndex != n)
      {
      cout << "Value found at index: " << findIndex << "\n";
      }
   else
      {
      cout << "Value not found. (" << findIndex << ")\n";
      }

   cout << "\n";
   }
