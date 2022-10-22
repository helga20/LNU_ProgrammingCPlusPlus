#include <iostream>
#include <algorithm>
#include <vector>
#include "car.h"
#include "functions.h"
using namespace std;

int main()
{
	vector<int> myV = { 10, 20, 30, 40, 50 };
	vector<Car> myC; readCarsFromFile(myC, "cars.txt");

	PrintStruct printer;
	CarPrinterClass carPrinter;
	Modifier coefModifier(-10);

	/*
	// --- Non modifying sequence operations ---
	// for_each // [begin, end)
	for_each(myV.begin(), myV.end(), printFunction); cout << "\n";
	for_each(myV.begin(), myV.begin() + 3, printFunction); cout << "\n";
	for_each(myV.begin(), myV.end(), printer); cout << "\n";
	for_each(myV.begin(), myV.end(), [](int elem) { cout << elem; cout << ' '; }); cout << "\n";
	cout << "\n";
	
	for_each(myC.cbegin(), myC.cend(), printCar); cout << "\n";
	for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n";
	for_each(myC.cbegin(), myC.cend(), [](const Car& car) { cout << car << "\n"; }); cout << "\n";
	cout << "\n";
	
	cout << "Before: "; for_each(myV.begin(), myV.end(), printFunction); cout << "\n";
	for_each(myV.begin(), myV.end(), duplicateFucntion);
	cout << "After:  "; for_each(myV.begin(), myV.end(), printFunction); cout << "\n";
	for_each(myV.begin(), myV.end(), coefModifier);
	cout << "After:  "; for_each(myV.begin(), myV.end(), printFunction); cout << "\n";
	int coef;
	cout << "\nEnter coef: "; cin >> coef;
	coefModifier.setCoef(coef);
	for_each(myV.begin(), myV.end(), coefModifier);
	cout << "After:  "; for_each(myV.begin(), myV.end(), printFunction); cout << "\n\n";

	/*
	for_each(myC.begin(), myC.end(), [](Car& car) { car.setDiscount(10); });
	for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n";
	coef = 5;
	for_each(myC.begin(), myC.end(), [coef](Car& car) { car.setDiscount(coef); });
	for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n\n";
	*/

	/*
	// find
	int searchVal;
	for (int i = 0; i < 2; ++i)
	{
		cout << "Search: "; cin >> searchVal;
		vector<int>::iterator findIt = find(myV.begin(), myV.end(), searchVal);
		if (findIt != myV.end())
		{
			cout << "Element found: " << *findIt << "\n";
		}
		else
		{
			cout << "No such element found.\n";
		}
	}

	Car audiCar("Audi", 350950);
	auto carIt = find(myC.cbegin(), myC.cend(), audiCar);
	if (carIt != myC.cend())
	{
		cout << "\nCar found:\n";
		carIt->print();
	}
	else
	{
		cout << "\nNo Audi car.\n";
	}	

	// find_if
	carIt = find_if(myC.cbegin(), myC.cend(), carPriceGreater350);
	if (carIt != myC.cend())
	{
		cout << "\nCar found:\n";
		carIt->print();
	}
	else
	{
		cout << "\nNo car greater 350 000.\n";
	}

	// find_first_of
	// count
	// equal
	
	// count_if
	int nofAudi = count_if(myC.cbegin(), myC.cend(), [](const Car& car) { return car.getModel() == "Audi"; });
	cout << "Found " << nofAudi << " cars of model Audi.\n";
	*/

	// --- Modifying sequence operations ---
	// copy
	vector<int> copyV(myV.size());
	copy(myV.begin(), myV.end(), copyV.begin());
	for_each(copyV.begin(), copyV.end(), [](int& elem) { elem /= 2; });
	cout << "Vector 1: "; for_each(myV.begin(), myV.end(), printer); cout << "\n";
	cout << "Vector 2: "; for_each(copyV.begin(), copyV.end(), printer); cout << "\n\n";
	myV.resize(myV.size() * 2);
	copy(copyV.begin(), copyV.end(), myV.begin() + 5);
	cout << "Vector 1: "; for_each(myV.begin(), myV.end(), printer); cout << "\n";
	cout << "Vector 2: "; for_each(copyV.begin(), copyV.end(), printer); cout << "\n\n";

	// copy_if
	GreaterThen greater20(20);
	int greatCount = count_if(myV.begin(), myV.end(), greater20);
	vector<int> greatV(greatCount);
	copy_if(myV.begin(), myV.end(), greatV.begin(), greater20);
	cout << "Vector 1: "; for_each(myV.begin(), myV.end(), printer); cout << "\n";
	cout << "Vector 3: "; for_each(greatV.begin(), greatV.end(), printer); cout << "\n\n";

	string model = "Audi";
	int nofAudi = count_if(myC.cbegin(), myC.cend(), [model](const Car& car) { return car.getModel() == model; });
	cout << "Found " << nofAudi << " cars of model " << model << ".\n";
	vector<Car> audiCars(nofAudi);
	copy_if(myC.cbegin(), myC.cend(), audiCars.begin(), [model](const Car& car) { return car.getModel() == model; });
	for_each(audiCars.cbegin(), audiCars.cend(), carPrinter); cout << "\n\n";

	// copy_n
	// copy_backward
	
	// swap
	cout << "Before swap\n";
	cout << "Vector 2: "; for_each(copyV.begin(), copyV.end(), printer); cout << "\n";
	cout << "Vector 3: "; for_each(greatV.begin(), greatV.end(), printer); cout << "\n";
	swap(copyV, greatV);
	cout << "After swap\n";
	cout << "Vector 2: "; for_each(copyV.begin(), copyV.end(), printer); cout << "\n";
	cout << "Vector 3: "; for_each(greatV.begin(), greatV.end(), printer); cout << "\n\n";
	
	// transform
	// replace
	// replace_if
	
	// remove
	//cout << "Before remove 10\n";
	//cout << "Vector 1: "; for_each(myV.begin(), myV.end(), printer); cout << "\n";
	//auto endIt = remove(myV.begin(), myV.end(), 10);
	//cout << "After remove 10\n";
	//cout << "Vector 1: "; for_each(myV.begin(), endIt, printer); cout << "\n\n";

	// remove_if
	//auto carEndIt = remove_if(myC.begin(), myC.end(), [](Car& C) { return C.getPrice() < 230000; });
	//for_each(myC.begin(), carEndIt, carPrinter); cout << "\n\n";

	// --- Sorting ---
	// sort
	cout << "Vector: "; for_each(myV.begin(), myV.end(), printer); cout << "\n";
	sort(myV.begin(), myV.end());
	cout << "Sorted: "; for_each(myV.begin(), myV.end(), printer); cout << "\n\n";

	cout << "All cars\n";
	sort(myC.begin(), myC.end());
	for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n";

	cout << "Sorted by model\n";
	//sort(myC.begin(), myC.end(), compareCarsByModel);
	//for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n";
	sort(myC.begin(), myC.end(), [](const Car& car1, const Car& car2) { return car1.getModel() < car2.getModel(); });
	for_each(myC.cbegin(), myC.cend(), carPrinter); cout << "\n";

	// is_sorted
	
	// min, max
	cout << "Min(" << greatV[2] << "; " << greatV[0] << ") = " << min(greatV[2], greatV[0]) << "\n";
	auto& maxAudiCar = max(myC[0], myC[1]);
	cout << "Max Audi\n";
	maxAudiCar.print();
	cout << "\n";

	// min_element, max_element
	auto minIntElem = min_element(greatV.begin(), greatV.end());
	cout << "Min integer: " << *minIntElem << "\n";

	auto maxCarElem = max_element(myC.begin(), myC.end());
	cout << "Max Car\n";
	maxCarElem->print();
	cout << "\n";
	
	cout << "\n";
	return 0;
}