#include <iostream>
#include "readers.h"
#include "books.h"
#include "bookorder.h"
#include "devices.h"
using namespace std;

int main()
{
	Kid Tom(12);
	Developer Steve("Middle");
	Tourist Jack("USA");
	Student Olga(2);

	cout << "   Readers\n";
	cout << Tom << "\n" << Steve << "\n" << Jack << "\n" << Olga << "\n\n";

	FantasyBook HP;
	CppBook CBook;
	LvivGuide LBook;
	cout << "   Books\n";
	cout << HP << "\n" << CBook << "\n" << LBook << "\n\n";

	PaperBook PBook;
	PdfBook Pdf;
	EBook Kindle;
	cout << "   Devices\n";
	cout << PBook << "\n" << Pdf << "\n" << Kindle << "\n\n";

	BookOrder<Kid> TomOrder(Tom);
	BookOrder<Developer> SteveOrder(Steve);
	BookOrder<Tourist> JackOrder(Jack);
	BookOrder<Student> OlgaOrder(Olga);
	cout << "   Book Orders\n";
	TomOrder.printOrderInfo(); cout << "\n";
	SteveOrder.printOrderInfo(); cout << "\n";
	JackOrder.printOrderInfo(); cout << "\n";
	OlgaOrder.printOrderInfo(); cout << "\n\n";

	
	return 0;
}