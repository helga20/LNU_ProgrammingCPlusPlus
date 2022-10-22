#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <fstream>
#include <algorithm>
#include <map>
#include "car.h"
#include "engines.h"
#include "enginecar.h"
using namespace std;

/*
pair

Sequence Containers
vector
list
queue
deque
priority_queue
stack

Associative Containers
set
multiset
map
multimap
*/

void printCar(const Car& car)
{
	car.print();
}

int main()
{
	// 1. pair
	pair<string, int> p1("Milka", 35);
	pair<string, int> p2 = make_pair("Roshen", 27);
	pair<string, int> p3;
	p3.first = "Svitoch";
	p3.second = 22;

	cout << "All chocolates\n";
	cout << p1.first << ": " << p1.second << "\n";
	cout << p2.first << ": " << p2.second << "\n";
	cout << p3.first << ": " << p3.second << "\n";
	cout << "Total price: " << p1.second + p2.second + p3.second << "\n\n";

	pair<int, Car> car1(2019, Car("Seat", 15090));
	pair<int, Car> car2 = make_pair(2020, Car("Audi", 25070));
	Car Tesla("Tesla", 45000);
	pair<int, Car> car3;
	car3.first = 2021;
	car3.second = Tesla;
	cout << "All cars\n";
	cout << car1.first << ": "; car1.second.print();
	cout << car2.first << ": "; car2.second.print();
	cout << car3.first << ": "; car3.second.print();
	cout << "Total price: " << car1.second.getPrice() + car2.second.getPrice() + car3.second.getPrice() << "\n\n";

	// 2. vector vs list
	vector<int> myV = { 1, 2, 3, 4, 5 };
	list<int> myL;
	myL.push_back(1); myL.push_back(2); myL.push_back(3);
	cout << myV[2] << "  " << myV.at(1) << "\n";
	cout << *(++myL.begin()) << "\n";

	// 3. queue
	queue<Car> myQ;
	myQ.push(car2.second);
	myQ.push(car1.second);
	myQ.push(Tesla);
	cout << "\nQueue of " << myQ.size() << " cars:\n";
	int totPrice = 0;
	while (!myQ.empty())
	{
		myQ.front().setDiscount(10);
		myQ.front().print();
		totPrice += myQ.front().getPrice();
		myQ.pop();
	}
	cout << "Total price:  " << totPrice << "\n\n";

	// 4. priority_queue
	priority_queue<Car> prioQ;
	prioQ.push(car2.second);
	prioQ.push(car1.second);
	prioQ.push(Tesla);
	cout << "Priority Queue of " << prioQ.size() << " cars:\n";
	while (!prioQ.empty())
	{
		prioQ.top().print();
		prioQ.pop();
	}
	cout << "\n";

	// 5. set vs multiset
	set<int> myS;
	multiset<int> multiS;
	ifstream iFile("numbers.txt");
	while (!iFile.eof())
	{
		int elem; iFile >> elem;
		myS.insert(elem);
		multiS.insert(elem);
	}
	iFile.close();

	cout << "Set of " << myS.size() << " integers\n";
	for (set<int>::iterator it = myS.begin(); it != myS.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << "\n";
	cout << "Lower bound (2): " << *(myS.lower_bound(2)) << "\n";
	cout << "Upper bound (5): " << *(myS.upper_bound(5)) << "\n\n";

	cout << "Multiset of " << multiS.size() << " integers\n";
	for_each(multiS.cbegin(), multiS.cend(), [](const int& elem) { cout << elem << "  "; });
	cout << "\n\n";

	set<Car> carSet;
	carSet.insert(car1.second);
	carSet.insert(car2.second);
	carSet.insert(Tesla);
	cout << "Set of " << carSet.size() << " cars\n";
	for_each(carSet.cbegin(), carSet.cend(), printCar);
	cout << "\n";
	cout << "Cheapest car: "; carSet.cbegin()->print();
	cout << "Most expensive car: "; carSet.crbegin()->print();
	cout << "\n\n";

	// 6. map
	map<string, Car> myM;
	myM["2019"] = Car("Fiat", 20050);
	myM["2018"] = car2.second;
	myM.emplace("2019", Car("Ferrari", 50090));
	myM["2019"] = Car("Ferrari", 50090);
	myM.emplace("2021", Tesla);
	totPrice = 0;
	for (map<string, Car>::const_iterator it = myM.cbegin(); it != myM.cend(); ++it)
	{
		cout << "Year: " << it->first << ". ";
		it->second.print();
		totPrice += it->second.getPrice();
	}
	cout << "Total price: " << totPrice << "\n\n";

	cout << "Check for 2016\n";
	if (myM.count("2016") > 0)
	{
		cout << "Car from 2016 exists\n";
		myM["2016"].print();
	}
	else
	{
		cout << "No car from 2016\n";
	}

	cout << "\nCheck for 2021\n";
	map<string, Car>::iterator findIt = myM.find("2021");
	if (findIt != myM.end())
	{
		cout << "Car from 2021 exists\n";
		findIt->second.setDiscount(10);
		findIt->second.print();
	}
	else
	{
		cout << "No car from 2021\n";
	}

	cout << "\n";

	// 2019 A1 A2 A3 -> price1
	// 2020 - - -  -> price2
	// 2021
	cout << "\n\n------------------------------------------------------------------\n\n";
	map<int, vector<Car>&> yearMap;
	vector<Car> cars2019 = { car1.second, car2.second, car3.second };
	vector<Car> cars2020 = { Car("Audi", 30500), Car("Lamborgini", 75800), Car("Renault", 35600) };
	vector<Car> cars2021 = { Car("Tesla", 89990), Car("BMW", 75300), Car("Mersedes", 65780) };

	cout << "Cars from 2019\n";
	totPrice = 0;
	for_each(cars2019.cbegin(), cars2019.cend(), [&totPrice](const Car& C) {
		C.print();
		totPrice += C.getPrice();
		});
	yearMap.emplace(totPrice, cars2019);
	cout << "Total price: " << totPrice << "\n\n";

	cout << "Cars from 2020\n";
	totPrice = 0;
	for_each(cars2020.cbegin(), cars2020.cend(), [&totPrice](const Car& C) {
		C.print();
		totPrice += C.getPrice();
		});
	yearMap.emplace(totPrice, cars2020);
	cout << "Total price: " << totPrice << "\n\n";

	cout << "Cars from 2021\n";
	totPrice = 0;
	for_each(cars2021.cbegin(), cars2021.cend(), [&totPrice](const Car& C) { 
		C.print();
		totPrice += C.getPrice();
		});
	yearMap.emplace(totPrice, cars2021);
	cout << "Total price: " << totPrice << "\n\n";

	cout << "All prices, sorted: ";
	for (auto it = yearMap.cbegin(); it != yearMap.cend(); ++it)
	{
		cout << it->first << "  ";
	}
	cout << "\n\n";

	cout << "Cheapest cars: \n";
	for (auto it = yearMap.begin()->second.begin(); it != yearMap.begin()->second.end(); ++it)
	{
		cout << it->getModel() << "  ";
	}
	cout << "\n\n";

	cout << "Most expensive cars with discount 10%\n";
	for (auto it = yearMap.rbegin()->second.begin(); it != yearMap.rbegin()->second.end(); ++it)
	{
		it->setDiscount(10);
		it->print();
	}
	cout << "\n\n";

	// Template + inheritance
	cout << "\n\n------------------------------------------------------------------\n\n";
	ElectroEngine engine1(16);
	ElectroEngine engine2(32);
	PetrolEngine petrol1("Diesel");
	PetrolEngine petrol2("A95 Pulls");
	EngineCar<ElectroEngine> Tesla1("Tesla", 89000, engine2);
	Tesla1.print();
	EngineCar<ElectroEngine> Nissan("Nissan", 43000, engine1);
	Nissan.print();
	EngineCar<PetrolEngine> BMW("BMW", 77000, petrol1);
	BMW.print();
	EngineCar<PetrolEngine> Seat("Seat", 17000, petrol2);
	Seat.print();
	cout << "Total price: " << Tesla1.getPrice() + Nissan.getPrice() + BMW.getPrice() + Seat.getPrice() << "\n\n";
	cout << "\n--------------------------\n";
	vector<Car*> allCars = { &Tesla1, &Nissan, &cars2020[1], &BMW, &Seat, &cars2020[0], new EngineCar<PetrolEngine>("Honda", 45600, petrol2) };
	for_each(allCars.cbegin(), allCars.cend(), [](const Car* elem) { elem->print(); cout << "\n"; });
	cout << "\n\n";

	cout << "\n";
	return 0;
}