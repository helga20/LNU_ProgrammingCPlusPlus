#include <iostream>
#include "chocolate.h"
#include "chocolate_bar.h"
#include "snickers.h"
#include "filling.h"
#include "bar_filling.h"

using namespace std;

int main()
{
	Chocolate C1("Dark", 85);
	Chocolate C2;
	C2.readChocolate();

	cout << "\nAll chocolate:\n";
	C1.printChocolate(); cout << "\n";
	C2.printChocolate(); cout << "\n";
	cout << "\n-----------------------------------\n";

	ChocolateBar B1;
	ChocolateBar B2(65, C1);
	ChocolateBar Nuts(45.5, "Milk", 73);
	ChocolateBar B3(B2);
	ChocolateBar B4;
	B4.readChocolateBar();

	cout << "\nAll chocolate bar:\n";
	B1.printChocolateBar();
	B2.printChocolateBar();
	Nuts.printChocolateBar();
	B3.printChocolateBar();
	B4.printChocolateBar();
	cout << "\n...................................\n";

	Snickers S1;
	Snickers S2(100, C1);
	Snickers SnickersNut(60, "White", 40);
	Snickers S3(S2);
	Snickers S4;
	S4.readSnickers();

	cout << "\nAll snickers:\n";
	S1.printSnickers();
	S2.printSnickers();
	SnickersNut.printSnickers();
	S3.printSnickers();
	S4.printSnickers();
	cout << "\n___________________________________\n";

	Filling F1("Nuts");
	Filling F2("Raisins");
	Filling F3(F2);
	Filling F4;
	F4.readFilling();

	cout << "\nAll filling:\n";
	F1.printFilling(); cout << "\n";
	F2.printFilling(); cout << "\n";
	F3.printFilling(); cout << "\n"; 
	F4.printFilling(); cout << "\n";
	cout << "\n-----------------------------------\n";

	BarWithFilling BF1;
	BarWithFilling BF2("Snitoch", C1, F1);
	BarWithFilling BF3("Millenium", "Dark", 79, "with nuts");
	BarWithFilling BF4(BF2);
	BarWithFilling BF5;
	BF5.readBarWithFilling();

	cout << "\nAll chocolate bar with fillings:\n";
	BF1.printBarWithFilling();
	BF2.printBarWithFilling();
	BF3.printBarWithFilling();

	cout << "Just chocolate: \n"; 
	BF4.printChocolate(); 
	BF5.printChocolate(); 
	cout << "\n";

	cout << "Just filling: \n"; 
	BF4.printFilling(); 
	BF5.printFilling(); 
	cout << "\n";
	cout << "\n...................................\n";

	Chocolate* choc1 = &BF3;
	Chocolate* choc2 = new Chocolate("Dark", 84);
	Filling* fil1 = &BF1;
	Filling* fil2 = new Filling("poppy");
	choc1->printChocolate(); cout << "\n";
	choc2->printChocolate(); cout << "\n";
	fil1->printFilling(); cout << "\n";
	fil2->printFilling(); cout << "\n";

	return 0;
}