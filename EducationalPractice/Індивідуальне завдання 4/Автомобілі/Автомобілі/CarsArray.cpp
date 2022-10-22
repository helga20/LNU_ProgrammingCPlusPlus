#include"CarsArray.h"
#include<iostream>
#include<string>
#include <fstream>
#include"sportCar.h"
#include "truck.h"

using namespace std;

CarsArray::CarsArray()
	: trCar(nullptr), arrSize(0), arrCount(0)
{}

CarsArray::CarsArray(int size)
	: arrSize(size), arrCount(0), trCar(new Car* [size])
{}

CarsArray::~CarsArray()
{
	if (trCar != nullptr)
	{
		delete[] trCar;
	}
}

void CarsArray::addElem(Car* elem)
{
	if (arrSize == 0)
	{
		arrSize = 5;
		arrCount = 0;
		trCar = new Car * [arrSize];
	}

	else if (arrCount == arrSize)
	{
		int tempSize = arrSize + 5;
		Car** tempArray = new Car * [tempSize];
		for (arrCount = 0; arrCount < arrSize; ++arrCount)
		{
			tempArray[arrCount] = trCar[arrCount]->clone(); 
		}
		delete[] trCar;
		trCar = tempArray;
	}

	trCar[arrCount] = elem;
	++arrCount;
}

void CarsArray::printArrayInfo() const
{
	cout << "Cars array:\n";
	cout << "Elements (" << arrCount << "):\n";
	for (int i = 0; i < arrCount; ++i)
	{
		if (trCar[i] != nullptr)
		{
			trCar[i]->printCarInfo();
			cout << "\n";
		}
	}
	cout << "\n";
}

void CarsArray::readCarsFromFile(const std::string& fileName)
{
	ifstream iFile(fileName);
	iFile >> arrCount;
	arrSize = arrCount + 5;
	trCar = new Car * [arrCount];
	int k = 0;
	for (int i = 0; i < arrCount; ++i)
	{
		char code;
		iFile >> code;
		if (code == 'T')
		{
			trCar[k] = new Truck();
		}
		else if (code == 'S')
		{
			trCar[k] = new sportCar();
		}
		else
		{
			iFile.ignore(256, '\n');
			continue;
		}
		iFile >> *(trCar[k]);
		++k;
	}
	iFile.close();
}

double CarsArray::totalPrice()
{
	if (arrCount == 0)
	{
		throw "Empty elements list!";
	}
	double total = 0.0;
	for (int i = 0; i < arrCount; ++i)
	{
		total += trCar[i]->getPrice();
	}
	return total;
}

Car* CarsArray::getMinSportCar()
{
	if (arrCount == 0)
	{
		throw "Empty elements list!";
	}

	int min = 0;
	for (int j = 0; j < arrCount; ++j)
	{
		if (trCar[j]->getType() == 'S')
		{
			min = j; break;
		}
	}
	for (int i = 0; i < arrCount; ++i)
	{
		if (trCar[i]->getPrice() < trCar[min]->getPrice() && trCar[i]->getType() == 'S')
		{
			min = i; 
		}
	}
	if (min == 0)
	{
		throw "Error! No Sport car";
	}
	return trCar[min];
}

Car* CarsArray::getMaxTruck()
{
	if (arrCount == 0)
	{
		throw "Empty elements list!";
	}

	int max = 0;
	for (int i = 0; i < arrCount; ++i)
	{
		if (trCar[i]->getType() == 'T')
		{
			max = i; break;
		}
	}
	if (max == 0)
	{
		throw "Error! No trucks";
	}
	for (int j = 0; j < arrCount; ++j)
	{
		if (trCar[j]->getPrice() > trCar[max]->getPrice() && trCar[j]->getType() == 'T')
		{
			max = j;
		}
	}
	return trCar[max];
}

