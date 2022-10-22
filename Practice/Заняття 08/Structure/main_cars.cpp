#include <iostream>
#include "cars.h"

int main()
{
	Car C1; 
	printCar(C1);
	cout << "\n";

	C1.brand = "Ford";
	C1.model = "Ranger";
	C1.price = 39000;
	printCar(C1);
	cout << "\n\n";
	
	Car C3("Nissan", "Navara", 33000.); 
	printCar(C3);
	cout << "\n\n";
	Car C4(C1); 
	C4.brand = "Ford";
	printCar(C4);
	cout << "\n\n";

	cout << "\nNew car\n";
	Car C2;
	readCar (C2);
	printCar(C2);

	cout << "\nRead-Write Car\n";
	Car C5;
	cout << "Enter Car \n";
	cin >> C5;
	cout << "Your Car: " << C5 << "\n";

	cout << "\n\n";
	const int n = 5;
	Car shop[n] = { C1, C2, C3, C4, C5 };
	printCarArray(shop, n);
	cout << "Total price: " << totalPrice(shop, n) << "\n";
	cout << "Most expensive Car: " << mostExpensiveCar(shop, n) << "\n";
	cout << "Cheapest Car:       " << cheapestCar(shop, n) << "\n";
	cout << "Cars of Ford: " << totalBrandPrice("Ford", shop, n) << "\n\n";

	system("pause");
	return 0;
}
