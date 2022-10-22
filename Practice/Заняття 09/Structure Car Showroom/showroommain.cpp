#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
#include "carshowroom.h"
using namespace std;

int main()
{
	ifstream iFile("carinfo.txt");
	Car C1, C2, C3;
	iFile >> C1 >> C2 >> C3;
	iFile.close();
	cout << "\nCars(1)\n";
	cout << C1 << "\n" << C2 << "\n" << C3 << "\n\n";

	CarShowroom allCars("Lviv", 3);
	addCar(C1, allCars);
	addCar(C2, allCars);
	addCar(C3, allCars);
	printShowroom(allCars);
	cout << "Toral price: " << showroomPrice(allCars) << "\n\n";
	cout << "Average: " << showroomAverage(allCars) << "\n\n";


	CarShowroom FordCars("Ford", 6);
	addCar(C1, FordCars);
	addCar(C3, FordCars);
	printShowroom(FordCars);
	cout << "Toral price: " << showroomPrice(FordCars) << "\n\n";

	system("pause");
	return 0;
}
