#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Car
{
	string  brand;
	string model;
	double price;

	Car() : brand("No brand"), model("No model"), price(0.0) {}

	Car(string brnd, string mdl, double prc) : brand(brnd), model(mdl), price(prc) {}

	Car(const Car& C) : brand(C.brand), model(C.model), price(C.price) {}

	~Car() {}
};

istream& operator>>(istream& in, Car& C);
ostream& operator<<(ostream& out, const Car& C);
bool operator<(const Car& C1, const Car& C2);
