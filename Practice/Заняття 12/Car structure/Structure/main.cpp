//#include <iostream>
//#include "cars.h"
//
//int main()
//{
//	Car C1; 
//	printCar(C1);
//	cout << "\n";
//
//	C1.brand = "Ford";
//	C1.model = "Ranger";
//	C1.price = 39000;
//	printCar(C1);
//	cout << "\n\n";
//	
//	Car C3("Nissan", "Navara", 33000.); 
//	printCar(C3);
//	cout << "\n\n";
//	Car C4(C1); 
//	C4.brand = "Ford";
//	printCar(C4);
//	cout << "\n\n";
//
//	cout << "\nNew car\n";
//	Car C2;
//	readCar (C2);
//	printCar(C2);
//
//	cout << "\nRead-Write Car\n";
//	Car C5;
//	cout << "Enter Car \n";
//	cin >> C5;
//	cout << "Your Car: " << C5 << "\n";
//
//	cout << "\n\n";
//	const int n = 5;
//	Car shop[n] = { C1, C2, C3, C4, C5 };
//	printCarArray(shop, n);
//	cout << "Total price: " << totalPrice(shop, n) << "\n";
//	cout << "Most expensive Car: " << mostExpensiveCar(shop, n) << "\n";
//	cout << "Cheapest Car:       " << cheapestCar(shop, n) << "\n";
//	cout << "Cars of Ford: " << totalBrandPrice("Ford", shop, n) << "\n\n";
//
//	system("pause");
//	return 0;
//}
#include<iostream>
#include"car.h"
using namespace std;

int main()
{
	Car C1;
	Car C2("Ford", "Ranger", 39000);
	Car C3(C2);
	cout << "\n";

	cout << "Car info\n";
	cout << C2.getBrand() << " " << C2.getModel() << " " << C2.getPrice() << " " << "\n";
	C1.printInfo();
	C3.printInfo();

	cout << "\nVia getters\n";
	C1.getBrand() = "Nissan";
	C1.getModel() = "Navara";
	C1.getPrice() = 33000;
	C1.printInfo();
	cout << "\n";

	C3.setBrand("Kia");
	C3.setModel("Sonet");
	C3.setPrice(51000);
	C3.printInfo();

	double p;
	cout << "\nPlease, enter new price: ";
	cin >> p;
	C3.setPrice(p);
	C3.printInfo();

	Car C4;
	cout << "\nPlease, enter car info:\n";
	cin >> C4;
	cout << "Here is your car\n" << C4 << "\n";

	cout << "\n";
	return 0;
}
