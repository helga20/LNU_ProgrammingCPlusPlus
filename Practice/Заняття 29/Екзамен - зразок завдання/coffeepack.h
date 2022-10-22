#pragma once
#include <iostream>
#include <string>
#include <map>

class CoffeePriceException
{
private:
	std::string m_producer;

public:
	CoffeePriceException(const std::string& producer) : m_producer(producer) {}
	void printInfo() const
	{
		std::cout << "Producer " << m_producer << " has no price set.\n";
	}
};

class CoffeePack
{
protected:
	std::string m_producer;
	int m_weight;
	std::map<std::string, int>* m_prices;

public:
	CoffeePack(std::map<std::string, int>* prices = nullptr);
	CoffeePack(const std::string& producer, int weigth, std::map<std::string, int>& prices);
	CoffeePack(const CoffeePack& C);
	virtual ~CoffeePack();

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
	virtual double getPrice() const;
	virtual char getType() const;
	virtual void initialize();

	CoffeePack& operator=(const CoffeePack& C);
	bool operator<(const CoffeePack& P) const;

	void setPricesTable(std::map<std::string, int>& prices);
	void increaseWeight(int weight);
	const std::string& getProducer() const;
	int getWeight() const;

};

std::istream& operator>>(std::istream& in, CoffeePack& C);
std::ostream& operator<<(std::ostream& out, const CoffeePack& C);