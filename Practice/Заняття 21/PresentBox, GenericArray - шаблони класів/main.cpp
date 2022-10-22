#include <iostream>
#include "book.h"
#include "car.h"
#include "presentbox.h"
#include "genericarray.h"
using namespace std;

int main()
{
	GenericArray<int> arrInt(25);
	GenericArray<double> arrDbl(5);
	GenericArray<char> arrChar(3);

	arrInt.addElem(4);
	arrInt.addElem(5);
	arrInt.addElem(7);
	arrInt.addElem(2);

	//int elem;
	//cout << "Enter integer: "; cin >> elem;
	//if (arrInt.containsElement(elem))
	//{
	//	cout << "Yes, such element exists. Index: " << arrInt.findIndex(elem) << ".\n";
	//}
	//else
	//{
	//	cout << "Sorry, no such element\n";
	//}

	arrDbl.addElem(5.1);
	arrDbl.addElem(3.7);
	arrDbl.addElem(1.4);

	arrChar.addElem('A');
	arrChar.addElem('B');
	arrChar.addElem('C');
	arrChar.addElem('D');

	cout << "Chars array: ";
	for (int i = 0; i < arrChar.getElementCount(); ++i)
	{
		cout << arrChar.getElement(i) << ' ';
	}
	cout << "\n";

	//arrInt.printArray();
	//arrDbl.printArray();
	//arrChar.printArray();

	cout << "\n\n";

	GenericArray<Car> CarsArray;
	CarsArray.readFromFile("cars.txt");
	CarsArray.printArray();

	//Car Audi("Audi", 250000);
	//try
	//{
	//	Car& myCar = CarsArray.findElement(Audi);
	//	myCar.setDiscount(25);
	//}
	//catch (const char* msg)
	//{
	//	cout << "ERROR: " << msg << "\n";
	//}
	//cout << "\n\nCheck all cars:\n";
	//CarsArray.printArray();

	double totalSum = CarsArray.getElement(0).getPrice();
	for (int i = 1; i < CarsArray.getElementCount(); ++i)
	{
		totalSum += CarsArray.getElement(i).getPrice();
	}
	cout << "Total price of Cars: " << totalSum << "\n";

	cout << "\n\n";













	/*
	Car Audi("Audi", 250000);
	Book Matan("Tarasiuk", "MatAn", 90.5);
	Book Lord("Tolkien", "Lord of the Rings", 255);

	PresentBox<Car> PCar("Oleh", Audi);
	PresentBox<Book> PBook("Olena", Matan);
	PresentBox<Car> PCar_copy(PCar);
	PresentBox<Book> PBook_default;

	PCar.printPresentBoxInfo();
	cout << "Total price:    " << PCar.getPresentBoxPrice();
	PCar.setPresentDiscount(15);
	cout << "\nDiscount price: "<< PCar.getPresentBoxPrice();
	cout << "\n\n";
	PBook.printPresentBoxInfo();
	cout << "Total price:    " << PBook.getPresentBoxPrice();
	PBook.setPresentDiscount(10);
	cout << "\nDiscount price: " << PBook.getPresentBoxPrice();
	cout << "\n\n";

	PBook_default.setRecipient("Andriy");
	PBook_default.setPresent(Lord);
	PBook_default.printPresentBoxInfo();
	cout << "Total price: " << PBook_default.getPresentBoxPrice();
	cout << "\n\n";

	PresentBox<Car> PCar_2;
	cin >> PCar_2;  // PCar_2.readPresentBox(cin);
	cout << PCar_2; // PCar_2.writePresentBox(cout);
	cout << "\n\n";
	*/
	
	return 0;
}