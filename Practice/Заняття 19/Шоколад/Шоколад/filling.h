 #pragma once
#include <string>

class Filling
{
protected:
	std::string kindFilling;
public:
	Filling();
	Filling(const std::string& kind);
	Filling(const Filling& F);
	virtual ~Filling();

	virtual void printFilling() const;
	void readFilling();
};