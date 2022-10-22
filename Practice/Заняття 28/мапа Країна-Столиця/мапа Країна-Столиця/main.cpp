#include <iostream>
#include "capital.h"
#include <map>
#include <fstream>
using namespace std;

int main()
{
    map <string, Capital> country_map;

    Capital C1;
    Capital C2("Madrid", 3.2);
    Capital C3("Berlin", 3.6);
    Capital C4(C2);
    Capital C5;
    C5.readCapital();

    cout << "\nAll capitals:\n";
    C1.printCapitalInfo();
    C2.printCapitalInfo();
    C3.printCapitalInfo();
    C4.printCapitalInfo();
    C5.printCapitalInfo();

    cout << "_________________________________________\n";

    ifstream iFile("map.txt");
    int n; iFile >> n;
    for (int i = 0; i < n; ++i)
    {
        string country_name; iFile >> country_name;
        Capital info; info.getName();
        iFile >> info;
        country_map.emplace(country_name, info);

    }
    iFile.close();
    cout << "\nMap from file: \n";

    for (map<string, Capital>::iterator it = country_map.begin(); it != country_map.end(); ++it)
    {
        cout << it->first << " -> ";
        cout << it->second.getName() << "\n";
    }

    double max = 0.0;
    for (map<string, Capital>::iterator it = country_map.begin(); it != country_map.end(); ++it)
    {
        double temporary = it->second.getPopulation();
        if (max < temporary)
        {
            max = temporary;
        }
    }

    for (map<string, Capital>::iterator it = country_map.begin(); it != country_map.end(); ++it)
    {
        double temporary = it->second.getPopulation();
        if (max == temporary)
        {
            cout << "\nThe largest population: " << endl;
            cout << it->first << " -> ";
            cout << it->second.getName() << "\n";
        }
    }

	cout << "\n";
	system("pause");
	return 0;
}