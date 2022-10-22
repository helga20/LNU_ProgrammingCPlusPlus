//Приклад про те, що шаблон класу може мати дружні функції
#include <iostream>
template<typename T>
class TRational
{
	T n;
public:
	explicit TRational(int n_) : n(n_) {}

	template<typename U>
	friend bool operator == (const TRational<U>& lObj, const TRational<U>& rObj);
};

template<typename U>
bool operator == (const TRational<U>& lObj, const TRational<U>& rObj)
{
	return lObj.n == rObj.n;
}

int main()
{
	TRational<int> a(1);
	TRational<int> b(1);
	TRational<int> c(2);

	std::cout << (a == b) << ", " << (a == c);

	return 0;
}