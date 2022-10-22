#pragma once
#include <string>
#include "car.h"

class CarsArray
{
private:
	Car** trCar;
	int arrSize;
	int arrCount;
public:
	CarsArray();
	CarsArray(int size);
	~CarsArray();

	void addElem(Car* elem);
	void printArrayInfo() const;
	void readCarsFromFile(const std::string& fileName);
	double totalPrice();

	Car* getMaxTruck();
	Car* getMinSportCar();
};