#include "monitor.h"
using namespace std;

Monitor::Monitor()
	:Device(), size(0.0)
{}

Monitor::Monitor(const std::string& mdl, int prc, double sz)
	: Device(mdl, prc), size(sz)
{}

Monitor::Monitor(const Monitor& M)
	: Device(M), size(M.size)
{}

Monitor::~Monitor()
{}

void Monitor::deviceInfo() const
{
	cout << "Motitor size: " << size << "\n";
}

void Monitor::printDeviceInfo() const
{
	cout << "Monotor Info\n";
	Device::printDeviceInfo();
	cout << "Size:" << size << "\n";
}

void Monitor::readFrom(std::istream& in)
{
	Device::readFrom(in);
	in >> size;
}
void Monitor::writeTo(std::ostream& out) const
{
	Device::writeTo(out);
	out << " " << size;
}