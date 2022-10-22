#include "printer.h"
using namespace std;

Printer::Printer()
	:Device(), pages(0)
{}

Printer::Printer(const std::string& mdl, int prc, int pgs)
	: Device(mdl, prc), pages(pgs)
{}

Printer::Printer(const Printer& P)
	: Device(P), pages(P.pages)
{}

Printer::~Printer()
{}

void Printer::deviceInfo() const
{
	cout << "Printer print speed: " << pages << "\n";
}

void Printer::printDeviceInfo() const
{
	cout << "Printer Info\n";
	Device::printDeviceInfo();
	cout << "Print speed:" << pages << "\n";
}

void Printer::readFrom(std::istream& in)
{
	Device::readFrom(in);
	in >> pages;
}
void Printer::writeTo(std::ostream& out) const
{
	Device::writeTo(out);
	out << " " << pages;
}

char  Printer::getType() const
{
	return 'P';
}