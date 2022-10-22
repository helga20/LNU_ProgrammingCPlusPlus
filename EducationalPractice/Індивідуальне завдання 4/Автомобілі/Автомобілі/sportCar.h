#pragma once
#include"car.h"

class sportCar : public Car
{
private:
	int maxSpeed;
public:
	sportCar();
	sportCar(const std::string& brnd, double prc, int speed);
	sportCar(const sportCar& S);
	virtual~sportCar();

	virtual Car* clone() const override;

	virtual char getType() const override;
	virtual void printCarInfo() const override;

	virtual double getPrice() const override;

	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};