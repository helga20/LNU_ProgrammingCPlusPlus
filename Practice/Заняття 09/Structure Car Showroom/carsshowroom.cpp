#include "carshowroom.h"
#include <fstream>

void printShowroom(const CarShowroom& CS)
{
	cout << CS.city << "\n";
	for (int i = 0; i < CS.nofCars; ++i)
	{
		cout << CS.showroom[i] << "\n";
	}
	cout << "\n";
}
void addCar(const Car& C, CarShowroom& CS)
{
	if (CS.nofCars < CS.maxSize)
	{
		CS.showroom[CS.nofCars] = C;
		++CS.nofCars;
	}
	else
	{
		cout << "Sorry. Showroom is full\n";
	}
}

void readShowroomFromFile(const string& fileName, CarShowroom& CS)
{
	ifstream iFile(fileName);
	iFile >> CS.city;
	iFile >> CS.nofCars;
	CS.maxSize = CS.nofCars * 2;
	CS.showroom = new Car[CS.maxSize];

	for (int i = 0; i < CS.nofCars; ++i)
	{
		iFile >> CS.showroom[i];
	}

	iFile.close();
}
double showroomPrice(const CarShowroom& CS)
{
	double sum = 0.0;
	for (int i = 0; i < CS.nofCars; ++i)
	{
		sum += CS.showroom[i].price;
	}
	return sum;
}
double showroomAverage(const CarShowroom& CS)
{
	double sum = 0.0;
	float avg = 0;
	for (int i = 0; i < CS.nofCars; ++i)
	{
		sum += CS.showroom[i].price;
		avg = sum / CS.nofCars;
	}
	return avg;;
}