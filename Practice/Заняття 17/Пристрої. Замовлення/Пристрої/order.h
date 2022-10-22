#pragma once
#include <string>
#include "monitor.h"
#include <iostream>

class Order
{
private:
	int number;
	Device* oneDevice;
public:
	Order();
	Order(int num, Device* device);
	Order(const Order& O);
	~Order();

	void printInfo() const;
	int getOrder() const;

	void printOrderInfo() const;
	Device* getDevice() const;

	void setOrder(int num);

	void setDevice(Device* device);

	Device*& getDevice();
	double getPrice() const;
	int getNumber() const;
	int minOrder(Order* arr1, int m);

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

};

std::istream& operator>>(std::istream& in, Order& O);
std::ostream& operator<<(std::ostream& out, const  Order& O);


