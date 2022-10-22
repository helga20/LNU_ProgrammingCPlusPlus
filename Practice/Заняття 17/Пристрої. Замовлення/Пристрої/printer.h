#pragma once
#include "device.h"
#include <string>

class Printer : public Device
{
protected:
	int pages;
public:
	Printer();
	Printer(const std::string& mdl, int prc, int pgs);
	Printer(const Printer& P);
	virtual ~Printer();

	virtual char getType() const override;
	virtual void deviceInfo() const override;
	virtual void printDeviceInfo() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};
