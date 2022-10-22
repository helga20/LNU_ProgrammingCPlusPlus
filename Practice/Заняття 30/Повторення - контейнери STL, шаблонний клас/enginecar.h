#pragma once
#include "car.h"
#include <iostream>
using namespace std;

template <typename TEngine>
class EngineCar : public Car
{
private:
	TEngine m_engine;

public:
	EngineCar();
	EngineCar(const std::string& model, double price, const TEngine& engine);
	EngineCar(const EngineCar& E);
	virtual ~EngineCar();

	virtual void print() const override;
	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};

template <typename TEngine>
EngineCar<TEngine>::EngineCar()
	: Car(), m_engine()
{}

template <typename TEngine>
EngineCar<TEngine>::EngineCar(const std::string& model, double price, const TEngine& engine)
	: Car(model, price), m_engine(engine)
{}

template <typename TEngine>
EngineCar<TEngine>::EngineCar(const EngineCar& E)
	: Car(E), m_engine(E.m_engine)
{}

template <typename TEngine>
EngineCar<TEngine>::~EngineCar()
{}

template <typename TEngine>
void EngineCar<TEngine>::print() const
{
	Car::print();
	m_engine.printInfo();
}

template <typename TEngine>
void EngineCar<TEngine>::readFrom(std::istream& in)
{
	Car::readFrom(in);
	m_engine.readFrom(in);
}

template <typename TEngine>
void EngineCar<TEngine>::writeTo(std::ostream& out) const
{
	Car::writeTo(out);
	m_engine.writeTo(out);
}