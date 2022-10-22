#include <iostream>
#include"car.h"
#include"sportCar.h"
#include"truck.h"
#include <fstream>
#include"CarsArray.h"
using namespace std;

int main()
{
	/*cout << "\t";
	cout << "Cars\n";
	Car C1("Audi", 15000);
	Car C2("BMW", 22000);
	cout << C1 << "\n";
	cout << C2 << "\n";
	cout << "\n";*/

	cout << "\t";
	cout << "Sports cars\n";
	sportCar S3("Nissan", 18000, 175);
	sportCar S4("Porshe", 26000, 195);
	cout << S3 << "\n";
	cout << S4 << "\n";
	cout << "\n";
	cout << "Max speed is less than 180 km/h: " << S3.getPrice() << " USD\n";
	cout << "Max speed is more than 180 km/h: " << S4.getPrice() << " USD\n";
	cout << "\n";

	cout << "\t";
	cout << "Sport car\n";
	sportCar Kia("Kia", 28000, 195);
	Kia.printCarInfo();
	cout << "\n";

	cout << "\t";
	cout << "Trucks\n";
	Truck T3("TGX", 9100, 230);
	Truck T4("DAF", 5000, 280);
	cout << T3 << "\n";
	cout << T4 << "\n";
	cout << "\n";
	cout << "Max lifting is less than 250 kg: " << T3.getPrice() << " USD\n";
	cout << "Max lifting is more than 250 kg: " << T4.getPrice() << " USD\n";
	cout << "\n";

	cout << "\t";
	cout << "Truck\n";
	sportCar Man("MAN TGL", 13000, 230);
	Man.printCarInfo();
	cout << "\n";

	sportCar S1("Nissan", 18000, 175);
	sportCar S2("Porshe", 26000, 195);
	Truck T1("TGX", 9100, 230);
	Truck T2("DAF", 5000, 280);

	cout << "................................\n";
	ifstream iFile("cars.txt");
	int n; iFile >> n;
	Car** arr = new Car * [n];
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		char code;
		iFile >> code;
		if (code == 'T')
		{
			arr[k] = new Truck();
		}
		else if (code == 'S')
		{
			arr[k] = new sportCar();
		}
		else
		{
			iFile.ignore(256, '\n');
			continue;
		}
		iFile >> *(arr[k]);
		++k;
	}
	iFile.close();
	cout << "\nAll cars\n";
	for (int i = 0; i < k; ++i)
	{
		arr[i]->printCarInfo();
		cout << "\n";
	}
	cout << "\n";

	cout << "______ Cars array ______\n";
	cout << "\n";

	CarsArray CA1;
	CA1.readCarsFromFile("allCars.txt");
	CA1.printArrayInfo();	

	cout << "Total price: " << CA1.totalPrice() << "\n";
	cout << "\n";

	cout << "\tThe cheapest Sport car\n";
	try
	{
		CA1.getMinSportCar()->printCarInfo();
	}
	catch (const char* msg)
	{
		cout << "ERROR. " << msg << "\n";
	}
	cout << "\n";

	cout << "\tThe most expensive truck\n";
	try
	{
		CA1.getMaxTruck()->printCarInfo();
	}
	catch (const char* msg)
	{
		cout << "ERROR. " << msg << "\n";
	}

	cout << "\n";
	delete[] arr;

	system("pause");
	return 0;
}