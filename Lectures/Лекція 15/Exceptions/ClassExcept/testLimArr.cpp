#include <iostream>
#include "arraydbe.h"
#include "limarre.h"
using namespace std;
const int Years = 3;
const int FirstYear = 2007;

int main()
{
	int year;
	double total = 0.0;
	LimitArE income(Years,FirstYear);
	cout<<"Enter your income for the last "<<Years<<" years:\n";
	try {
		for (year=FirstYear; year<FirstYear+Years; ++year)
		{
			cout<<"Year "<<year<<": $";
			cin>>income[year];
		}
		cout.precision(2);
		cout.setf(ios_base::showpoint);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<"Recapitulating, here are the figures:\n";
		for (year=FirstYear; year<=FirstYear+Years; ++year)
		{
			cout<<year<<": $"<<income[year]<<'\n';
			total += income[year];
		}
	}
	catch (LimitArE::SonOfBad& bi)
	{
		cout<<"\nLimitArE exception: "<<bi.badInd<<" is a bad index value\n"
			<<"Index should be in the range "<<bi.l_lim<<" to "<<bi.u_lim<<".\n";
		cout<<"\n . . . from the E-object:\n"; bi.report();
	}
	catch (LimitArE::BadIndex& bi)
	{
		cout<<"\nArrayDbE exception: "<<bi.badInd<<" is a bad index value\n";
		cout<<"\n . . . from the E-object:\n"; bi.report();
	}
	cout<<"\nTOTAL INCOME for "<<(year-FirstYear)<<" years is $"<<total<<".\n";
	cout<<"Bye!\n";
	return 0;
}
