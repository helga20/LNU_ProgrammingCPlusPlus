#pragma once
#include <iostream>
#include <string>
#include <map>

class PriceException
{
private:
	std::string m_coffeeProducer;

public:
	PriceException(const std::string& producer) : m_coffeeProducer(producer) {}
	void printInfo() const
	{
		std::cout << "Price for producer " << m_coffeeProducer << " not defined.\n";
	}

};

class CoffeePack
{
protected:
	std::string m_producer;
	int m_weight;

public:
	CoffeePack();
	CoffeePack(const std::string& producer, int weight);
	CoffeePack(const CoffeePack& C);
	virtual ~CoffeePack();

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
	virtual double getPrice() const;

	virtual bool operator<(const CoffeePack& C) const;
	CoffeePack& operator+(int weight);

	void increaseWeigh(int weight);

	static std::map<std::string, int> s_prices;
	//static void setProducerPrices(const std::map<std::string, int>& pricesMap)
	//{
	//	for (std::map<std::string, int>::const_iterator it = pricesMap.cbegin(); it != pricesMap.cend(); ++it)
	//	{
	//		s_prices[it->first] = it->second;
	//	}
	//}

};

std::istream& operator>>(std::istream& in, CoffeePack& C);
std::ostream& operator<<(std::ostream& out, const CoffeePack& C);