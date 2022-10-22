#include "device.h"
using namespace std;

Device::Device()
	:model("no model"), price(0)
{}

Device::Device(const string& mdl, int prc)
	: model(mdl), price(prc)
{}

Device::Device(const Device& D)
	: model(D.model), price(D.price)
{}

Device:: ~Device()
{}

void Device::printDeviceInfo() const
{
	cout << "Model:" << model << ". Price: " << price << "\n";
}

void Device::readFrom(istream& in)
{
	in >> model >> price;
}
void Device::writeTo(ostream& out) const
{
	out << model<<" " << price<< " ";
}

istream& operator>>(istream& in, Device& D)
{
	D.readFrom(in);
	return in;
}
ostream& operator<<(ostream& out, const Device& D)
{
	D.writeTo(out);
	return out;
}

const std::string& Device::getModel() const
{
	return model;
}

int Device::getPrice() const
{
	return price;
}


