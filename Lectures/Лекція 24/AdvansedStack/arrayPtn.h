// Шаблон динамічного масиву фіксованого розміру.
// Клас інкапсулює роботу з вказівниками, перевіряє
// правильність звертань за індексом

#include <stdexcept>
#include <sstream>

template <typename Type>
class Array
{
private:
	unsigned int size;
	Type* arr;
	void checkIndex(int i) const;
public:
	Array(): arr(0), size(0) {}
	explicit Array(unsigned int n, const Type& val = 0.0);
	Array(const Type* pn, unsigned int n);
	Array(const Array& a);
	virtual ~Array();
	unsigned int arSize() const { return size; }
	Type& operator[](int i);
	const Type& operator[](int i) const;
	Array& operator=(const Array& a);
};
template<typename Type>
inline void Array<Type>::checkIndex(int i) const
{
	if (i < 0 || i >= size)
	{
		std::ostringstream mess;
		mess << "Error in ArrayDb limits: " << i << " is a bad index.";
		throw std::out_of_range(mess.str());
	}
}
template <typename Type>
Array<Type>::Array(unsigned int n, const Type& val)
{
	arr = new Type[n];
	size = n;
	for (size_t i=0; i<n; i++) arr[i] = val;
}
template <typename Type>
Array<Type>::Array(const Type *pn, unsigned int n)
{
	arr = new Type[n];
	size = n;
	for (size_t i=0; i<n; i++) arr[i] = pn[i];
}
template <typename Type>
Array<Type>::Array(const Array<Type> &a)
{
	size = a.size;
	arr = new Type[size];
	for (size_t i=0; i<size; i++) arr[i] = a.arr[i];
}
template <typename Type>
Array<Type>::~Array()
{
	delete[] arr;
}
template <typename Type>
Type& Array<Type>::operator[](int i)
{
	checkIndex(i);
	return arr[i];
}
template <typename Type>
const Type& Array<Type>::operator[](int i) const
{
	checkIndex(i);
	return arr[i];
}
template <typename Type>
Array<Type>& Array<Type>::operator =(const Array<Type> &a)
{
	if (this == &a) return *this;
	delete[] arr;
	size = a.size;
	arr = new Type[size];
	for (size_t i=0; i<size; i++) arr[i] = a.arr[i];
	return *this;
}
