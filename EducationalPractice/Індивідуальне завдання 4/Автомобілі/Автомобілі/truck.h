#pragma once
#include"car.h"

class Truck : public Car
{
private:
	int maxLift;
public:
	Truck();
	Truck(const std::string& brnd, double prc, int lift);
	Truck(const Truck& T);
	virtual~Truck();

	virtual Car* clone() const override;

	virtual char getType() const override;
	virtual void printCarInfo() const override;

	virtual double getPrice() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};