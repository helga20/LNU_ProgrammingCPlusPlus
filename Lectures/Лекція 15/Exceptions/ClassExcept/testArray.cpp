#include <iostream>
#include "arraydbl.h"
using namespace std;

int main()
{
	int Players = -3;
	ArrayDbl Points(1);
rep:
	try {
		ArrayDbl Team(Players);
		cout << "Enter percentages for your " << Players
			<< " top players as a decimal fraction:\n";
		int player;
		for (player = 0; player < Players; ++player)
		{
			cout << "Player " << (player + 1) << " % = ";
			cin >> Team[player];
		}
		cout << Team << "max = " << Team.max() << "\naverage = " << Team.average() << "\n\n";
		Points = Team;

		cout.precision(1);
		cout.setf(ios_base::showpoint);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << "Recapitulating, here are the percentages:\n";
		for (player = 0; player <= Players + 1; ++player)
			cout << "Player #" << (player + 1) << ": " << 100.0*Team[player] << "%\n";
	}
	catch (ArrayDbl::BadIndex & bi)
	{
		cout << "\nArrayDbE exception: " << bi.badInd << " is a bad index value\n"
			<< "Information from the exception object:\n";
		bi.report();
		cout << "--------------\n";
	}
	catch (ArrayDbl::BadSize)
	{
		cout << "\nArrayDbE exception: bad size of the array.\nEnter a valid size: ";
		cin >> Players; goto rep;
	}
	Points.resize(Players + 1);
	for (int player = 0; player <= Players; ++player)
		cout << "Player #" << (player + 1) << ": " << 100.0*Points[player] << "%\n";
	cout.precision(2);
	cout << "\nmax = " << Points.max() << "\naverage = " << Points.average() << '\n';

	cout << "Bye!\n";
	system("pause");
	return 0;
}