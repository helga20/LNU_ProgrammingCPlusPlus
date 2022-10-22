////#include "cars.h"
////#include <iostream>
////using namespace std;
////
////void readCar(Car& C)
////{
////	cout << "Enter car info\n";
////	cout << "Enter brand: "; cin >> C.brand;
////	cout << "Enter model: "; cin >> C.model;
////	cout << "Enter price: "; cin >> C.price;
////}
////
////void printCar(const Car& C)
////{
////	cout << "Car info\n";
////	cout << "Brand: " << C.brand << "\n";
////	cout << "Model: " << C.model << "\n";
////	cout << "Price: " << C.price << "\n";
////}
////
////istream& operator>>(istream& in, Car& C)
////{
////	in >> C.brand >> C.model >> C.price;
////	return in;
////}
////
////ostream& operator<<(ostream& out, const Car& C)
////{
////	out << C.brand << ' ' << C.model << ' ' << C.price;
////	return out;
////}
////
////bool operator<(const Car& C1, const Car& C2)
////{
////	return C1.price < C2.price;
////}
////
////void printCarArray(Car* arr, const int n)
////{
////	cout << "Cars array\n";
////	for (int i = 0; i < n; ++i)
////	{
////		cout << arr[i] << "\n";
////	}
////	cout << "\n";
////}
////
////double totalPrice(Car* arr, const int n)
////{
////	double totalSum = 0.;
////	for (int i = 0; i < n; ++i)
////	{
////		totalSum += arr[i].price;
////	}
////	return totalSum;
////}
////
////Car mostExpensiveCar(Car* arr, const int n)
////{
////	Car maxCar = arr[0];
////	for (int i = 1; i < n; ++i)
////	{
////		if (arr[i].price > maxCar.price)
////		{
////			maxCar = arr[i];
////		}
////	}
////	return maxCar;
////}
////
////Car cheapestCar(Car* arr, const int n)
////{
////	Car minCar = arr[0];
////	for (int i = 1; i < n; ++i)
////	{
////		if (arr[i] < minCar)
////		{
////			minCar = arr[i];
////		}
////	}
////	return minCar;
////}
////
////double totalBrandPrice(string brnd, Car* arr, const int n)
////{
////	double totalSum = 0.;
////	for (int i = 0; i < n; ++i)
////	{
////		if (arr[i].brand == brnd)
////		{
////			totalSum += arr[i].price;
////		}
////	}
////	return totalSum;
////}
//#include "car.h"
//
//Car::Car() : brand(), model(), price()
//{
//	//cout << "Default Car\n";
//}
//
//Car::Car(const string& brnd, const string& mdl, const double& prc) : brand(brnd), model(mdl), price(prc)
//{
//	//cout << "Parameters Car\n";
//}
//
//Car::Car(const Car& C) : brand(C.brand), model(C.model), price(C.price)
//{
//	//cout << "Copy Car\n";
//}
//
//Car::~Car()
//{
//	//cout << "Destroy Car\n"<< brand <<"\n";
//}
//
//string Car::getBrand() const
//{
//	return this->brand;
//}
//
//string Car::getModel() const
//{
//	return this->model;
//}
//
//double Car::getPrice() const
//{
//	return this->price;
//}
//
//void Car::printInfo() const
//{
//	cout << "Car info: ";
//	cout << brand << " " << model << " " << price << " \n";
//}
//
//string& Car::getBrand()
//{
//	return brand;
//}
//
//string& Car::getModel()
//{
//	return model;
//}
//
//double& Car::getPrice()
//{
//	return price;
//}
//
//void Car::setBrand(const string& brandValue)
//{
//	brand = brandValue;
//}
//
//void Car::setModel(const string& modelValue)
//{
//	model = modelValue;
//}
//
//void Car::setPrice(const double& priceValue)
//{
//	if (priceValue <= 0)
//	{
//		cout << "Error! Price " << priceValue << " cannot be\n";
//		return;
//	}
//	price = priceValue;
//}
//
//istream& operator>>(istream& in, Car& C)
//{
//	in >> C.getBrand() >> C.getModel() >> C.getPrice();
//	return in;
//}
//
//ostream& operator<<(ostream& out, const Car& C)
//{
//	out << "\nYour brand: " << C.getBrand() << "\nYour model: " << C.getModel() << "\nYour price: " << C.getPrice();
//	return out;
//}
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	string  brand;
	string model;
	double price;

public:
	Car();
	Car(const string& brnd, const string& mdl, const double& prc);
	Car(const Car& C);
	~Car();

	string getBrand() const;
	string getModel() const;
	double getPrice() const;

	void printInfo() const;

	string& getBrand();
	string& getModel();
	double& getPrice();

	void setBrand(const string& brandValue);
	void setModel(const string& modelValue);
	void setPrice(const double& priceValue);

	void readFrom(istream& in);
	void writeTo(ostream& out);
};

istream& operator>>(istream& in, Car& C);
ostream& operator<<(ostream& out, const Car& C);



