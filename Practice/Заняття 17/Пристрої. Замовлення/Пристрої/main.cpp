#include <iostream>
#include "device.h"
#include "monitor.h"
#include "printer.h"
#include <fstream>
#include "order.h"

using namespace std;

int main()
{
	Monitor HPV("HPM194", 2000, 18.5);
	HPV.printDeviceInfo();
	HPV.deviceInfo();
	cout << "\n";

	Printer HPL("HPP107a", 4000, 20);
	HPL.printDeviceInfo();
	HPL.deviceInfo();
	cout << "\n";

	//cout << "................................\n";
	//ifstream iFile("devices.txt");
	//int n; iFile >> n;
	//Device** arr = new Device * [n];
	//int k = 0;
	//for (int i = 0; i < n; ++i)
	//{
	//	char code;
	//	iFile >> code;
	//	if (code == 'M')
	//	{
	//		arr[k] = new Monitor();
	//	}
	//	else if (code == 'P')
	//	{
	//		arr[k] = new Printer();
	//	}
	//	else
	//	{
	//		iFile.ignore(256, '\n');
	//		continue;
	//	}
	//	iFile >> *(arr[k]);
	//	++k;
	//}
	//iFile.close();
	//cout << "\nAll devices\n";
	//for (int i = 0; i < k; ++i)
	//{
	//	arr[i]->printDeviceInfo();
	//	cout << "\n";
	//}
	//cout << "\n";

	/*Замовлення*/

	cout << "----------------------------\n";

	Monitor M1("Samsung", 3200, 24);
	Monitor M2("ViewSonic", 2600, 18);
	Printer P1("Dell", 3350, 26);
	Device* P2 = new Printer("Canon", 4000, 23);

	Order O1;
	Order O2(1, &M1);
	Order O2_1(2, new Monitor("Acer", 2600, 21.5));
	Order O3(3, &P1);
	Order O3_1(4, P2);

	cout << "All orders\n";
	O1.printInfo(); cout << "\n";
	O2.printInfo(); cout << "\n";
	O2_1.printInfo(); cout << "\n";
	O3.printInfo(); cout << "\n";

	cout << "****************************\n";
	cout << "Updenting:\n";
	cout << "\n";

	O3_1.printInfo(); cout << "\n";
	cout << "\n";

	O3_1.setOrder(0);
	O3_1.printInfo(); cout << "\n";
	cout << "\n";

	O3_1.setOrder(6);
	O3_1.printInfo(); cout << "\n";
	cout << "\n";

	O3_1.setDevice(&M2);
	O3_1.printInfo(); cout << "\n";
	cout << "\n";

	O3_1.setDevice(nullptr);
	cout << "\n";

	O3_1.setDevice(new Monitor("QUBE", 5800, 27));
	O3_1.printInfo(); cout << "\n";
	cout << "\n";

	Device*& D3_1 = O3_1.getDevice();
	D3_1 = &M2;
	O3_1.printInfo(); cout << "\n";
	cout << "\n";
	cout << "****************************\n";

	cout << "Monitor Info: \n";
	O2.printOrderInfo();
	cout << "\n";
	cout << "Printer Info: \n";
	O3.printOrderInfo();
	cout << "\n";

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Printer:\n";
	Device* D3 = O3.getDevice();
	if (D3 != nullptr)
	{
		cout << D3->getModel() << " ";
		D3->deviceInfo();
	}
	else
	{
		cout << "No device\n";
	}
	cout << "\n";

	cout << "_______________________________\n";

	ifstream iFile("order.txt");
	int m; iFile >> m;
	Order* arr1 = new Order [m];
	for (int i = 0; i < m; ++i)
	{
		iFile >> arr1[i];
	}
	iFile.close();

	ofstream oFile("order_copy.txt");
	oFile << m << "\n";

	cout << "Orders from file: \n";
	for (int i = 0; i < m; ++i)
	{
		arr1[i].printInfo();
		cout << "\n";
		oFile << arr1[i] << "\n";
	}
	iFile.close();

	int k = 0;
	for (int i = 0; i < m; ++i)
	{
		k = k + arr1[i].getPrice();
	}
	cout << "Total price = " << k << " hrn\n";

	int g = 0;
	for (int i = 0; i < m; ++i)
	{
		g = arr1[i].minOrder(arr1, m);
	}
	cout << "The smallest order number: " << g << "\n";
	cout << "\n";


	cout << "\n";
	delete[] arr1;
	//delete[] arr;

	system("pause");
	return 0;
}