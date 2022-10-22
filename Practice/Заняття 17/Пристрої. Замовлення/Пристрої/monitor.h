#pragma once
#include "device.h"
#include <string>

class Monitor : public Device
{
protected:
	double size;
public:
	Monitor();
	Monitor(const std::string& mdl, int prc , double sz);
	Monitor(const Monitor& M);
	virtual ~Monitor();

	virtual char getType() const override;
	virtual void deviceInfo() const override;
	virtual void printDeviceInfo() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;

	//const std::string& getModel() const;
	//int getPrice() const;
	//int getSize() const;

};

