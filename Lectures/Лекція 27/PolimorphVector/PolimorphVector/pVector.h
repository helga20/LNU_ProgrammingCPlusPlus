#pragma once
#include <vector>
using std::vector;

template <typename pT>
class pVector :public vector<pT>
{
private:
	void internalClear()
	{
		for (iterator it = begin(); it != end(); ++it) delete *it;
	}
public:
	pVector() : vector() {}
	~pVector()
	{
		internalClear();
	}
	pVector(const pVector& pV) : vector(pV)
	{
		for (iterator it = begin(); it != end(); ++it) *it = (*it)->Clone();
	}
	pVector& operator=(const pVector& pV)
	{
		if (this != &pV)
		{
			internalClear();
			vector::operator=(pV);
			for (iterator it = begin(); it != end(); ++it) *it = it->Clone();
		}
		return *this;
	}
	void clear()
	{
		internalClear();
		vector::clear();
	}
};