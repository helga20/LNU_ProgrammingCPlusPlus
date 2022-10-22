#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include "noisy.h"
using namespace std;

long Noisy::create = 0, Noisy::assign = 0,
	Noisy::copy = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

int main()
{
	const int size = 7;
	cout << "*** The array creation\n";
	Noisy na[size];
	// заповнення множини
	cout << "*** The set creation\n";
	set<Noisy> ns(na, na + size);
	cout << endl;
	Noisy n;
	// додавання нового елемента множини
	cout << "\n*** Insertion\n";
	ns.insert(n);
	ns.insert(Noisy());
	cout << endl;
	cout << "\n*** Looking for\n";
	cout << "ns.count(" << n << ")=" << ns.count(n) << endl;
	// перевірка наявності в множині
	if (ns.find(n) != ns.end()) cout << "n(" << n << ") found in ns\n";
	// конструювання на місці
	cout << "\n*** Emplacing\n";
	ns.emplace(22);
	ns.emplace(7, 5);
	// вилучення
	cout << "\n*** Erasing\n";
	ns.erase(22);
	ns.erase(ns.find(n));
	// виведення
	cout << "\n *** The set\n";
	copy(ns.begin(), ns.end(), ostream_iterator<Noisy>(cout, "\n"));
	cout << "\n\n--------------------------------\n";

	// автоматичне заповнення відображення
	cout << "\n*** Fun with a map<int,Noisy>\n";
	map<int, Noisy> nm;
	cout << "\n-- Automatic filling --------------------\n";
	for (int i = 0; i < 10; ++i) nm[i];
	cout << "\n-- Output the map ---------------------\n";
	for (size_t j = 0; j < nm.size(); ++j) cout << "nm[" << j << "] = " << nm[j] << '\n';
	cout << "\n-- Insertion by [] ----------------------\n";
	// додавання нової пари до відображення
	nm[10] = n;
	cout << "\n-- Insertion ----------------------------\n";
	// вставляння нової пари
	nm.insert(make_pair(47, n));
	cout << "\n-- Emplacing --------------------------\n";
	nm.emplace(15, Noisy());
	nm.emplace(20, 25);
	nm.emplace(21, Noisy(3, 3));
	cout << "\n-- Replacing --------------------------\n";
	nm[47] = Noisy();
	nm[5] = nm[0];
	cout << "\n-- Looking for a key ------------------\n";
	// пошук за ключем 
	cout << "\n nm.count(10) = " << nm.count(10)
		<< "\n nm.count(11) = " << nm.count(11) << '\n';
	map<int, Noisy>::iterator it = nm.find(6);
	if (it != nm.end())
		cout << "value:" << (*it).second << " found in nm at location 6\n";
	// ітератор відображення перебирають пари ключ-значення
	cout << "\n-- Output the map ---------------------\n";
	for (it = nm.begin(); it != nm.end(); ++it)
		cout << (*it).first << ':' << (*it).second << ".\n";
	cout << "\n--------------------------------\n";
	// Як працює оператор []
	map<Noisy, Noisy> mnn;
	Noisy n1, n2;
	cout << "\n================================\n";
	mnn[n1] = n2;
	cout << "\n................................\n";
	mnn[n2] = n1;
	cout << "\n--------------------------------\n";
	cout << mnn[n1] << '\t' << mnn[n2] << endl;
	cout << "\n-------- Clean up --------------\n";
	system("pause");
	return 0;
}
