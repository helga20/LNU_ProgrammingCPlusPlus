#include <iostream>
#include "dialogue.h"
using namespace std;

void printTraffic(Traffic** allTraf, int n)
{
	cout << "\nAll transportation \n";

	for (int k = 0; k < n; ++k)
	{
		cout << *(allTraf[k]) << ". " << allTraf[k]->getPrice() << " hrn\n";
	}
}

Traffic* expensiveTraffic(Traffic** allTraf, int n)
{
	Traffic* maxTraffic = allTraf[0];
	for (int i = 0; i < n; ++i)
	{
		if (allTraf[i]->getPrice() > maxTraffic->getPrice())
		{
			maxTraffic = allTraf[i];
		}
	}
	return maxTraffic;
}