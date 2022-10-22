#pragma once
#include <string>
#include <iostream>

class Device
{
protected:
	std::string model;
	int price;
public:
	Device();
	Device(const std::string& mdl, int prc);
	Device(const Device& D);
	virtual ~Device();

	virtual char getType() const abstract;
	virtual void deviceInfo() const abstract;
	virtual void printDeviceInfo() const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;

	const std::string& getModel() const;
	int getPrice() const;

};

std::istream& operator>>(std::istream& in, Device& D);
std::ostream& operator<<(std::ostream& out, const Device& D);