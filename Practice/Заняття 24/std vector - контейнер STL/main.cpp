#include <iostream>
#include <vector>
#include "functions.h"
#include "book.h"
using namespace std;

int main()
{
	vector<Book> myLib;
	myLib.reserve(10);
	readVector<Book>(myLib, "books.txt");
	cout << "My Library (of " << myLib.size() << " books)\n";
	printVectorIterator<Book>(myLib);

	auto maxIt = findMaxBook(myLib);
	cout << "\nThe most expensive Book is:\n";
	maxIt->print();

	cout << "\nChoose the discount: ";
	int discount; cin >> discount;
	maxIt->setDiscount(discount);
	cout << "\nAfter discount:\n";
	maxIt->print();
	cout << "\n";

	cout << "My Library (after disount)\n";
	printVectorIterator<Book>(myLib);

	vector<Book> tolkLib;
	tolkLib.reserve(myLib.size());
	string authorName = "Tolkien";
	for (auto it = myLib.cbegin(); it != myLib.cend(); ++it)
	{
		if (it->getAuthor() == authorName)
		{
			tolkLib.push_back(*it);
		}
	}
	cout << "\nLibrary of " << authorName << " ( " << tolkLib.size() << " books)\n";
	printVectorIterator<Book>(tolkLib);
	














	/*
	vector<int> v1;
	//cout << "v1 size: " << v1.size() << "\n";
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	//cout << "v1 size: " << v1.size() << "\n";

	cout << "v1: ";
	//printVector(v1);
	printVectorIterator(v1);

	vector<int> v2;// (5);
	//v2.reserve(10);
	v2.resize(10); // ідентично до конструктора
	//cout << "v2 size: " << v2.size() << "\n";
	v2.at(0) = 2;
	v2[1] = 4;
	v2[2] = 6;
	v2.push_back(8);
	v2.push_back(10);
	vector<int>::iterator it = v2.begin() + 3;
	*it = 22;
	//++it; ++it; // ?
	//*it == 22;
	//it -= 1; // ?
	//*it = 44;
	//cout << "v2 size: " << v2.size() << "\n";
	cout << "v2: ";
	//printVector(v2);
	printVectorIterator<int>(v2);
	cout << "v2: "; printReverse(v2);

	vector<int> v3(5, 3);
	vector<int> v4 = { 5, 3 };
	cout << "v3: "; printVector(v3);
	v3.insert(v3.begin() + 2, 5);
	v3.insert(v3.begin() + 4, 5);
	cout << "v3: "; printVector(v3);
	v3.insert(v3.begin() + 3, v2.begin() + 1, v2.begin() + 5);
	cout << "v3: "; printVector(v3);
	cout << "v4: "; printVector(v4);
	cout << "\n";

	vector<int> v5;
	//readVectorFixedSize(v5, "numbers.txt");
	readVector(v5, "numbers2.txt");
	cout << "v5: "; printVectorIterator<int>(v5);

	vector<double> v6(6, 1.5);
	cout << "v6: "; printVectorIterator<double>(v6);

	*/
	cout << "\n";
	return 0;
}