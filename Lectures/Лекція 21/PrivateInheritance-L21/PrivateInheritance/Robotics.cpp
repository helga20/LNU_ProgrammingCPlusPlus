#include "pch.h"
#include "Robotics.h"

int Robot::SerialNumber = 10001000;
Robot::Robot() :model("Base XL"), powerType("Solar")
{
	this->serialNo = ++SerialNumber;
}

Robot::Robot(const char * mod, const char * pow) :model(mod), powerType(pow)
{
	this->serialNo = ++SerialNumber;
}

void Robot::printOn(std::ostream & os) const
{
	os << "ROBOT <model: '" << model << "' No: " << serialNo << " on " << powerType << " energy>";
}

std::ostream & operator<<(std::ostream & os, const Robot & robot)
{
	robot.printOn(os);
	return os;
}

std::ostream & operator<<(std::ostream & os, const Robocop & robocop)
{
	robocop.printOn(os);
	return os;
}
