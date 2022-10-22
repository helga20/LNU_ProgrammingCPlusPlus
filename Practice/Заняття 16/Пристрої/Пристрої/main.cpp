#include <iostream>
#include "device.h"
#include "monitor.h"
#include "printer.h"
#include <fstream>

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

	cout << "................................\n";
	ifstream iFile("devices.txt");
	int n; iFile >> n;
	Device** arr = new Device * [n];
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		char code;
		iFile >> code;
		if (code == 'M')
		{
			arr[k] = new Monitor();
		}
		else if (code == 'P')
		{
			arr[k] = new Printer();
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
	cout << "\nAll devices\n";
	for (int i = 0; i < k; ++i)
	{
		arr[i]->printDeviceInfo();
		cout << "\n";
	}
	cout << "\n";

	delete[] arr;

	system("pause");
	return 0;
}