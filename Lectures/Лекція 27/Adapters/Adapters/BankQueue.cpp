#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <queue>
using namespace std;

class Customer
{
	int idNom;
	int serviceTime;
public:
	static int custNo;
	Customer() : serviceTime(0), idNom(0) {}
	Customer(int tm) : serviceTime(tm) { idNom = ++custNo; }
	int getTime() { return serviceTime; }
	void setTime(int newTime){ serviceTime = newTime; }
	friend ostream& operator<<(ostream& os, const Customer& c)
	{
		return os << 'C' << c.idNom << '[' << c.serviceTime << ']';
	}
};

class Teller
{
	queue<Customer>& customers;
	Customer current;
	enum { SLICE = 5 };
	int ttime;
	bool busy;
public:
	Teller(queue<Customer>& cq) : customers(cq), ttime(0), busy(false) {}
	Teller& operator=(const Teller& rv)
	{
		customers = rv.customers;
		current = rv.current;
		ttime = rv.ttime;
		busy = rv.busy;

		return *this;
	}
	bool isBusy() { return busy; }
	void run(bool recursion = false)
	{
		if (!recursion) ttime = SLICE;
		int servTime = current.getTime();
		if (servTime > ttime)
		{
			servTime -= ttime;
			current.setTime(servTime);
			busy = true;
			return;
		}
		if (servTime < ttime)
		{
			ttime -= servTime;
			if (!customers.empty())
			{
				current = customers.front();
				customers.pop();
				busy = true;
				run(true);
			}
			return;
		}
		current = Customer();
		busy = false;
		return;
	}
	void outCurrent(ostream& os)
	{
		os << "serving(" << current << ')';
	}
};

class CustomerQ : public queue<Customer>
{
public:
	friend ostream& operator<<(ostream& os, const CustomerQ& cd)
	{
		os << " size=" << cd.c.size() << "  ";
		copy(cd.c.begin(), cd.c.end(), ostream_iterator<Customer>(os," "));
		return os;
	}
};

int Customer::custNo = 0;

int main()
{
	CustomerQ customers;
	list<Teller> tellers;
	typedef list<Teller>::iterator TellIt;
	tellers.push_back(Teller(customers));
	srand(time(0));
	clock_t ticks = clock();
	ofstream out("result.txt");
	while (clock() < ticks + 0.1 * CLOCKS_PER_SEC)
	{
		for (int i = 0; i < rand() % 5; ++i) customers.push(Customer(rand() % 15 + 1));
		out << tellers.size() << " Tellers serve the Queue: " << customers << endl;
		for (TellIt i = tellers.begin(); i != tellers.end(); ++i)
		{
			(*i).run();
			out << "     "; (*i).outCurrent(out);
			out << " and tail: " << customers << endl;
		}
		out << /*'{' << tellers.size() << '}' << customers <<*/ endl;
		if (customers.size()/tellers.size() > 2) tellers.push_back(Teller(customers));
		if (tellers.size()>1 && customers.size()/tellers.size()<2)
			for (TellIt i=tellers.begin(); i!=tellers.end(); ++i)
				if (!(*i).isBusy()) {tellers.erase(i); break;}
	}
	return 0;
}