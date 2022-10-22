#pragma once
#include <iostream>
#include <string>
#include "car.h"
using namespace std;
struct CarShowroom
{
	string city;
	int maxSize;
	int nofCars;
	Car* showroom;

	CarShowroom() : city(), maxSize(0), nofCars(0), showroom(nullptr) {}
	CarShowroom(const string& type, int size) : city(type), maxSize(size), nofCars(0), showroom(new Car[size]) {}
	~CarShowroom()
	{
		if (showroom != nullptr)
		{
			delete[] showroom;
		}
	}

};
void printShowroom(const CarShowroom& CS);
void addCar(const Car& C, CarShowroom& CS);
void readShowroomFromFile(const string& fileName, CarShowroom& CS);
double showroomPrice(const CarShowroom& CS);
double showroomAverage(const CarShowroom& CS);