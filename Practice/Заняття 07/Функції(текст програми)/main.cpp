//#include <iostream>
//#include "functions.h"
//using namespace std;
//
//// <тип><ім"я>(<список параметрів>) 
////{
//// тіло функції
////}
//// ім"я ф-ї !*: //_azAZ09 //printArray // print_array
//// тип: нічого не повертає (void, або return; або не пишемо) повертає результат певного типу int, double, int*, bool + return!!!
//// список параметрів: <тип> <ім"я>
//// <тип>: за значенням (int), вказівник (int*), посилання (int&)
//
//void sayHi()
//{
//	cout << "Good morning!\n";
//}
//
//void sayHiNTimes(int n);
//void printInfo(const char* name, int age);
//
//int main()
//{
//	//sayHi();
//	//cout << "\n";
//	//int n1; cin >> n1;
//	//sayHiNTimes(n1);
//	//cout << "\n";
//
//	//printInfo("Oksana", 29);
//	//printInfo("Iryna", -5);
//
//	//double x, y;
//	//cout << "Enter x: "; cin >> x;
//	//cout << "Enter y: "; cin >> y;
//	//double xySum = sum(x, y);
//	//cout << "Sum: " << xySum << "\n";
//	//cout << "Sum: " << sum(x, y) << "\n";
//	//double xyMin = min(x, y);
//	//cout << "Min: " << xyMin << "\n";
//	//cout << "Max: " << max(x, y) << "\n";
//
//	//cout << "\nEnter rectangle\n";
//	//cout << "Side 1: "; cin >> x;
//	//cout << "Side 2: "; cin >> y;
//	//double p = perimOfRectangle(x, y);
//	//double s = squareOfRectangle(x, y);
//	//cout << "Perimeter: " << p << "\nSquare: " << s << "\n";
//
//	//int k; cin >> k;
//	//cout << "Before: " << k << "\n";
//	//multFive(k);
//	//cout << "After: " << k << "\n";
//
//	double x, y;
//	cin >> x >> y;
//	cout << "Before: " << x << ' ' << y << "\n";
//	swapValues(x, y);
//	cout << "After: " << x << ' ' << y << "\n";
//
//	system("pause");
//	return 0;
//}
//
//void sayHiNTimes(int n2) // параметр за значенням
//{
//	for (int i = 0; i < n2; ++i)
//	{
//		cout << "Good morning!\n";
//	}
//}
//
//void printInfo(const char* name, int age)
//{
//	if (age < 0)
//	{
//		cout << "Sorry, " << name << ". Age is wrong!\n";
//		return;
//	}
//
//	cout << "Hi! My name is " << name << ". My age is " << age << ".\n";
//}