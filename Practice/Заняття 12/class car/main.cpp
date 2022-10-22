#include<iostream>
#include "car.h"
using namespace std;

int main()
{
	Car C1("Ford", "Ranger", 39000);

	cout << "Car: " << C1 << '\n';
	cout<<"\nNew brand values" << '\n';
	try
	{
		C1.setBrand("");
		cout << "New car: " << C1 << '\n';
	}
	catch (CarEmptyFieldException CE)
	{
		CE.report();
	}

	cout << "\nNew model values" << '\n';
	try
	{
		C1.setModel("");
		cout << "New car: " << C1 << '\n';
	}
	catch (CarEmptyFieldException CE)
	{
		CE.report();
	}

	cout << "\nNew price values" << '\n';
	try
	{
		C1.setPrice(-1);
		cout << "New car: " << C1 << '\n';
	}
	catch (CarPriceException CP)
	{
		CP.report();
	}

	cout << "\nAfter all car: " << C1 << '\n';

	cout << "\n";
	return 0;
}
