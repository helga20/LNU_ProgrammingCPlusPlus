#include <iostream>
#include <cstring>
using namespace std;
#include "stock.h"

Stock::Stock()
{
	strcpy(company, default_stock.company);
	shares = default_stock.shares;
	share_val = default_stock.share_val;
	total_val = default_stock.total_val;
	cout << "    - - -    default create '" << company << "'\n";
	++Counter;
}
Stock::Stock(const char *co, int n, double pr)
{
	strncpy(company, co, Len - 1);
	company[Len - 1] = '\0';
	if (n>0) shares = n; else shares = 0;
	if (pr>0) share_val = pr; else share_val = -pr;
	set_tot();
	cout << "    - - -    create '" << company << "'\n";
	++Counter;
}
Stock::~Stock()
{
	cout << "    - - -    Bye, " << company << "!\n";
}
Stock& Stock::buy(int num, double price)
{
	if (num<0) cerr<<"Number of shared purchased can't be negative. Transactions is aborted.\n";
	else {
		shares += num; share_val = price; set_tot();
	} return *this;
}
Stock& Stock::sell(int num, double price)
{
	if (num>shares) cerr<<"You can't sell more than you have! Transactions is aborted.\n";
	else {
		shares -= num; share_val = price; set_tot();
	} return *this;
}
void Stock::update(double price)
{
	share_val = price; set_tot();
}
void Stock::show() const
{
	cout << " ***  Company: " << company	<< "   shares: " << shares
		<<"\nshare price: $" << share_val << "   total worth: $" << total_val << '\n';
}
const Stock& Stock::topval(const Stock &s) const
{
	if (s.total_val>total_val) return s;
	return *this;
}
Stock Stock::default_stock("University", 1, 100.0);
int Stock::Counter = 0;
void Stock::set_default(const char * co, int n, double pr)
{
	default_stock = Stock(co,n,pr);
}