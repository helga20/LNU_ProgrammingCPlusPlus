#include<iostream>
#include "traffic.h"
#include "air_traffic.h"
#include "rail_traffic.h"
#include <fstream>

using namespace std;

int main()
{
	/*{
		Traffic T1;
		Traffic T2("Yavoriv - ", "Lviv", 15, 50);
		Traffic T3(T2);
		cout << "\n";

		AirTraffic A1;
		cout << "\n";
		AirTraffic A2("Lviv - ", "Kyiv", 30, 1500, 200);
		cout << "\n";
		AirTraffic A3(A2);
		cout << "\n";
		cout << "\n";
	}*/

	cout << "\t";
	cout << "Transportation\n";
	Traffic T1("Yavoriv - ", "Lviv", 9, 50);
	Traffic T2("Yavoriv - ", "Lviv", 15, 50);
	cout << "9th place: " << T1.getPrice() << " hrn\n";
	cout << "15th place: " << T2.getPrice() << " hrn\n";
	cout << T1 << "\n";
	cout << T2 << "\n";
	cout << "\n";

	cout << "\t";
	cout << "Air transportation\n";
	AirTraffic A1("Lviv - ", "Kyiv", 30, 1500, false);
	AirTraffic A2("Lviv - ", "Kyiv", 30, 1500, true);
	cout << "Lviv - Kyiv (without a snack) " << A1.getPrice() << " hrn\n";
	cout << "Lviv - Kyiv (with a snack) " << A2.getPrice() << " hrn\n";
	cout << "\n";

	cout << "\t";
	cout << "Rail transportation\n";
	RailTraffic R1("Lviv - ", "Kyiv", 12, 300, 6);
	RailTraffic R2("Lviv - ", "Kyiv", 12, 300, 13);
	cout << "Lviv - Kyiv " << R1.getPrice() << " hrn\n";
	cout << "Lviv - Kyiv " << R2.getPrice() << " hrn\n";
	cout << "\n";

	ifstream airFile("air_traffic.txt");
	int nAir; airFile >> nAir;
	AirTraffic* air_traffic = new AirTraffic[nAir];
	for (int i = 0; i < nAir; ++i)
	{
		airFile >> air_traffic[i];
	}
	airFile.close();

	ifstream railFile("rail_traffic.txt");
	int nRail; railFile >> nRail;
	RailTraffic* rail_traffic = new RailTraffic[nRail];
	for (int i = 0; i < nRail; ++i)
	{
		railFile >> rail_traffic[i];
	}
	railFile.close();

	cout << "\t";
	cout << "Air transportation from file\n";
	for (int i = 0; i < nAir; ++i)
	{
		cout << air_traffic[i] << "\n";
	}
	cout << "\n";
	cout << "Total price = " << totalPrice(air_traffic, nAir) << " hrn\n";

	cout << "\n\t";
	cout << "Rail transportation from file\n";
	for (int i = 0; i < nRail; ++i)
	{
		cout << rail_traffic[i] << "\n";
	}
	cout << "\n";
	cout << "Total price = " << totalPrice(rail_traffic, nRail) << " hrn\n";

	int nAll = nAir + nRail;
	Traffic** allTraffic = new Traffic * [nAll];
	int kTraffic = 0;
	for (int i = 0; i < nAir; ++i)
		{
		allTraffic[kTraffic] = &air_traffic[i];
		kTraffic += 1;
		}
	for (int j = 0; j < nRail; ++j)
	{
		allTraffic[kTraffic] = &rail_traffic[j];
		kTraffic += 1;
	}

	cout << "\nAll transportation \n";
	ofstream oFile("all_traffic.txt");
	for (int k = 0; k < nAll; ++k)
	{
		cout << *(allTraffic[k]) << "\n";
		oFile << *(allTraffic[k]) << "\n";
	}
	oFile.close();


	delete[] allTraffic;

	cout << "\n";
	system("pause");
	return 0;
}
