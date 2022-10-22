#include <iostream>
#include "order.h"
#include "monitor.h"
#include "printer.h"
using namespace std;

Order::Order()
	:number(0), oneDevice(nullptr)
{}

Order::Order(int num, Device* device)
	: number(num), oneDevice(device)
{}

Order::Order(const Order& O)
	: number(O.number), oneDevice(O.oneDevice)
{}

Order::~Order()
{}

void Order::printInfo() const
{
	if (oneDevice == nullptr)
	{
		cout << "Invalid order (no device)\n";
		return;
	}
	cout << "Order: " << number << "\n";
	oneDevice->printDeviceInfo();
}

int Order::getOrder() const
{
	return number;
}

void Order::printOrderInfo() const
{
	if (oneDevice == nullptr)
	{
		cout << "Invalid order (no device)\n";
		return;
	}
	cout << *oneDevice << "\n";
}

Device* Order::getDevice() const
{
	return oneDevice;
}

void Order::setOrder(int num)
{
	if (num == 0)
	{
		cout << "Error! No order\n";
		cout << "\n";
		return;
	}
	number = num;
}

void Order::setDevice(Device* device)
{
	if (device == nullptr)
	{
		cout << "Error! Invalid device\n";
		return;
	}
	oneDevice = device;
}

Device*& Order::getDevice()
{
	return oneDevice;
}

void Order::readFrom(std::istream& in)
{
	in >> number;
	char code;
	in >> code;
	if (code == 'M')
	{
		oneDevice = new Monitor();
		in >> *oneDevice;
	}
	else if (code == 'P')
	{
		oneDevice = new Printer();
		in >> *oneDevice;
	}
	else
	{
		in.ignore(222, '\n');
	}
}

void Order::writeTo(std::ostream& out) const
{
	if (oneDevice == nullptr)
	{
		return;
	}
	out << number << ' \n';
	out << oneDevice->getType() << ' ' << *oneDevice;
}

double Order::getPrice() const
{
	if (oneDevice == nullptr)
	{
		cout << "Error! Invalid device\n";
		return 0;
	}
	return oneDevice->getPrice();
}

int Order::getNumber() const
{
	if (number == 0)
	{
		cout << "Error! Invalid number\n";
		return 0;
	}
	return number;
}

int Order::minOrder(Order* arr1, int m)
{
	Order minOrder = arr1[0];
	for (int i = 1; i < m; ++i)
	{
		if (minOrder.getNumber() < arr1[i].getNumber())
		{
			return minOrder.getNumber();
		}
	}	
}

std::istream& operator>>(std::istream& in, Order& O)
{
	O.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const  Order& O)
{
	O.writeTo(out);
	return out;
}



