#pragma once
#include <string>
#include <iostream>
using namespace std;

class ElectroEngine
{
private:
	int m_duration;

public:
	ElectroEngine(int duration = 0) :m_duration(duration) {}
	ElectroEngine(const ElectroEngine& E) : m_duration(E.m_duration) {}

	void printInfo() const
	{
		cout << "Electro Engine. Battery: " << m_duration << " hours.\n";
	}

	void readFrom(std::istream& in)
	{
		in >> m_duration;
	}

	void writeTo(std::ostream& out) const
	{
		out << m_duration;
	}
};

std::istream& operator>>(std::istream& in, ElectroEngine& E)
{
	E.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const ElectroEngine& E)
{
	E.writeTo(out);
	return out;
}

class PetrolEngine
{
private:
	string m_petrol;

public:
	PetrolEngine():m_petrol("95"){}
	PetrolEngine(const string& petrol) : m_petrol(petrol) {}
	PetrolEngine(const PetrolEngine& P) : m_petrol(P.m_petrol) {}

	void printInfo() const
	{
		cout << "Petrol Engine: " << m_petrol << ".\n";
	}

	void readFrom(std::istream& in)
	{
		in >> m_petrol;
	}

	void writeTo(std::ostream& out) const
	{
		out << m_petrol;
	}
};

std::istream& operator>>(std::istream& in, PetrolEngine& P)
{
	P.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const PetrolEngine& P)
{
	P.writeTo(out);
	return out;
}