#include "car.h"
#include <fstream>
using namespace std;

Car::Car() : m_model(""), m_price(0.0)
{}

Car::Car(const std::string& model, double price) : m_model(model), m_price(price)
{}

Car::Car(const Car& C) : m_model(C.m_model), m_price(C.m_price)
{}

Car::~Car()
{}

void Car::print() const
{
	cout << "Car: " << m_model << ". " << m_price << " euro\n";
}

double Car::getPrice() const
{
	return m_price;
}

const std::string& Car::getModel() const
{
	return m_model;
}

void Car::setDiscount(int discount)
{
	double discountValue = m_price * (double)discount / 100.0;
	m_price -= discountValue;
}

void Car::readFrom(std::istream& in)
{
	in >> m_model >> m_price;
}

void Car::writeTo(std::ostream& out) const
{
	out << m_model << ' ' << m_price;
}

bool Car::operator==(const Car& C) const
{
	return m_model == C.m_model && m_price == C.m_price;
}

bool Car::operator<(const Car& C) const
{
	return m_price < C.m_price;
}

std::istream& operator>>(std::istream& in, Car& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Car& C)
{
	C.writeTo(out);
	return out;
}

void readCarsFromFile(std::vector<Car>& cars, const std::string& fileName)
{
	ifstream iFile(fileName);
	while (!iFile.eof())
	{
		Car car; iFile >> car;
		cars.push_back(car);
	}
	iFile.close();
}