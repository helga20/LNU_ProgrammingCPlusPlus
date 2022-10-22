#include <iostream>
#include <fstream>
#include "edition.h"
#include "functions.h"
using namespace std;

int main()
{
	/*
	// за замовч
	Edition E1;
	// з парам
	Edition E2("Ellenberg", "Math Thinking", 320.5, 400);
	// копіювання
	Edition E3(E2);

	//cout << E1;
	//cout << E2.title << "\n";
	cout << "My editions\n";
	E1.print();
	E2.print();
	E3.print();
	cout << "\n";

	cout << "Edition info\n";
	cout << "author: " << E2.getAuthor() << "\n";
	cout << "title:  " << E2.getTitle() << "\n";
	cout << "price:  " << E2.getPrice() << "\n";
	cout << "\n";

	E1.setAuthor("Tolkien");
	E1.setTitle("Hobbit");
	E1.setPrice(550.2);
	E1.setPages(200);

	E3.setPrice(470.8);

	cout << "New editions\n";
	E1.print();
	E2.print();
	E3.print();
	cout << "\n";

	Edition E4;
	string temp;
	cout << "Enter author: "; cin >> temp;
	E4.setAuthor(temp);
	cout << "Enter title: "; cin >> temp;
	E4.setTitle(temp);
	double p;
	cout << "Enter price: "; cin >> p;
	int n;
	cout << "Enter nof pages: "; cin >> n;
	E4.setPrice(p);
	E4.setPages(n);
	cout << "Your Edition\n";
	E4.print();
	cout << "\n";

	Edition E5;
	cout << "Enter edition (auth/title/price/nofPages)\n";
	cin >> E5;
	cout << "Your Edition\n";
	cout << E5 << "\n";
	cout << "\n";
	*/

	ifstream iFile("books.txt");
	int size; iFile >> size;
	Edition* arr = new Edition[size];
	for (int i = 0; i < size; ++i)
	{
		iFile >> arr[i];
	}
	iFile.close();

	cout << "Editions from file\n";
	
	//for (int i = 0; i < size; ++i)
	//{
	//	// 1
	//	arr[i].print();
	//	// 2
	//	//cout<<arr[i];
	//	// 3
	//	//arr[i].writeTo(cout);
	//}
	//cout << "\n";

	printEditions(arr, size);
	printEditionsByAuthor(arr, size, "Tolkien");
	printEditionsByAuthor(arr, size, "Yaroshko");
	printEditionsByPagePrice(arr, size, 10);
	printEditionsByPagePrice(arr, size, 100);
	cout << "Total price: " << totalPrice(arr, size) << " uah.\n\n";
	cout << "Most expensive Edition\n";
	const Edition& E = findMostExpensiveEdition(arr, size);
	cout << E.getTitle() << " - " << E.getPrice() << " uah.\n\n";
	cout << "Cheapest page price\n";
	int index = findCheapestEditionByPagePrice(arr, size);
	cout << arr[index].getTitle() << " - " << arr[index].pagePrice() << "uah. (" << arr[index].getPrice() << " uah).\n\n";

	cout << "\n-------------------------\nSorted Editions\n";
	sortByPrice(arr, size);
	printEditions(arr, size);
	cout << "\n";
	sortByAuthor(arr, size);
	printEditions(arr, size);
	cout << "\n";

	delete[] arr;
	cout << "\n";
	system("pause");
	return 0;
}