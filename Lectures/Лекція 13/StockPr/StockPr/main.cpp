#include <iostream>
using namespace std;
#include "stock.h"
const int n = 5;
void showStocks(Stock [], int);
void manageStocks(Stock [], int);
int main()
{
	Stock A[n] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolitic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);
	cout.setf(ios_base::showpoint);

	showStocks(A,n);
	manageStocks(A,n);
	cout <<"\n\nSTOCK LIST AFTER MANAGING:\n";
	showStocks(A,n);

	Stock::set_default("no name",0,0.0);
	Stock top;
	for (int i=0; i<n; ++i) top = top.topval(A[i]);
	cout << "\nMost valuable holding:\n";
	top.show(); cout<<'\n';

	cout<<'\n'<<Stock::getCounter()<<" instances of class Stock were created\n\n";
	system("pause");
	return 0;
}
void showStocks(Stock A[], int size)
{
	cout << "\nSTOCK HOLDINGS:\n\n";
	for (int i=0; i<size; ++i)
	{
		cout<<'#'<<i<<'\n'; A[i].show();
	}
}
void manageStocks(Stock A[], int size)
{
	char c;
	int how, how1; double price, price1;
	for (int i=0; i<n; ++i)
	{
		cout << "\nstock #" << i << " - Buy, Sell, botH or Pass? : ";
		cin >> c;
		switch (c)
		{
		case 'b': case 'B':
			cout << "Input how & price to Buy: ";
			cin >> how >> price;
			A[i].buy(how,price); break;
		case 's': case 'S':
			cout << "Input how many Sell & price to Sell: ";
			cin >> how >> price;
			A[i].sell(how,price); break;
		case 'h': case 'H':
			cout << "Input how & price to Buy: ";
			cin >> how >> price;
			cout << "Input how many Sell & price to Sell: ";
			cin >> how1 >> price1;
			A[i].buy(how,price).sell(how1,price1); break;
		default:
			cout << "No actions\n\n";
			while (cin.get()!='\n');
		}
	}
}
/*
    - - -    create 'University'		- статичний член default_stock у файлі "stock.cpp"
    - - -    create 'NanoSmart'			- #0 елементи масиву через явно вказані конструктори
    - - -    create 'Boffo Objects'		- #1
    - - -    create 'Monolitic Obelisks'- #2
    - - -    create 'Fleep Enterprises'	- #3
    - - -    default create 'University'- #4 конструктор не вказано, використано конструктор за замовчуванням

STOCK HOLDINGS:							- далі працює процедура showStocks

#0
 ***  Company: NanoSmart   shares: 12
share price: $20.00   total worth: $240.00
#1
 ***  Company: Boffo Objects   shares: 200
share price: $2.00   total worth: $400.00
#2
 ***  Company: Monolitic Obelisks   shares: 130
share price: $3.25   total worth: $422.50
#3
 ***  Company: Fleep Enterprises   shares: 60
share price: $6.50   total worth: $390.00
#4
 ***  Company: University   shares: 1
share price: $100.00   total worth: $100.00
										- тепер настала черга manageStocks
stock #0 - Buy, Sell or botH ? : B
Input how & price to Buy: 20 20.25

stock #1 - Buy, Sell or botH ? : S
Input how many Sell & price to Sell: 60 2.5

stock #2 - Buy, Sell or botH ? : H
Input how & price to Buy: 70 3.25
Input how many Sell & price to Sell: 50 3.5

stock #3 - Buy, Sell or botH ? : S
Input how many Sell & price to Sell: 100 8.5
You can't sell more than you have! Transactions is aborted.

stock #4 - Buy, Sell or botH ? : Q
No actions


STOCK LIST AFTER MANAGING:

STOCK HOLDINGS:							- знову працює процедура showStocks

#0
 ***  Company: NanoSmart   shares: 32
share price: $20.25   total worth: $648.00
#1
 ***  Company: Boffo Objects   shares: 140
share price: $2.50   total worth: $350.00
#2
 ***  Company: Monolitic Obelisks   shares: 150
share price: $3.50   total worth: $525.00
#3
 ***  Company: Fleep Enterprises   shares: 60
share price: $6.50   total worth: $390.00
#4
 ***  Company: University   shares: 1
share price: $100.00   total worth: $100.00

    - - -    create 'no name'			- викликали set_default. Видно, що вона
    - - -    Bye, no name!				- створює тимчасовий об'єкт
    - - -    default create 'no name'	- створили top за новим default-зразком

Most valuable holding:
 ***  Company: NanoSmart   shares: 32
share price: $20.25   total worth: $648.00


8 instances of class Stock were created - кожен конструктор мав змогу "відмітитися"

    - - -    Bye, NanoSmart!			- окрема змінна top
    - - -    Bye, University!			- #4 елеименти масиву
    - - -    Bye, Fleep Enterprises!	- #3
    - - -    Bye, Monolitic Obelisks!	- #2
    - - -    Bye, Boffo Objects!		- #1
    - - -    Bye, NanoSmart!			- #0
    - - -    Bye, no name!				- статичний член класу
*/