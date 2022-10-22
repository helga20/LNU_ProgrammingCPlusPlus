#pragma once
#include <iostream>
using namespace std;

class DivisionException
   {
   public:
      void report() const { cout << "Divide by zero not allowed."; }
   };

class ArgumentException
   {
   private:
      double argValue;
   public:
      ArgumentException(double val) : argValue(val){}
      void report() const { cout << "Argument value: " << argValue << " is not allowed.\n"; }
   };

double getFraction(double num, double denom) /*throw (const char*)*/
   {
   //if (denom == 0)
   //   {
   //   throw "Divide by zero not allowed.";
   //   }
   if (denom == 0)
      {
      throw DivisionException();
      }

   return num / denom;
   }

double getAverage(double a, double b)
   {
   if (a == 0)
      {
      throw "First operand is zero.";
      }
   if (b == 0 || b == -1)
      {
      //throw 0.0;
      throw ArgumentException(b);
      }

   return (a + b) / 2.0;
   }
