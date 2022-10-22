#include "sortProcedures.h"
#include <ctime>
#include <iomanip>

int* createRandomVector(unsigned n)
{
	int * a = new int[n];
	std::srand(std::time(NULL));
	unsigned m = n * 2;
	for (unsigned i = 0; i < n; ++i)
		a[i] = std::rand() % m;
	return a;
}

int* createCopyVector(int * a, unsigned n)
{
	int * c = new int[n];
	for (unsigned i = 0; i < n; ++i) c[i] = a[i];
	return c;
}

void printVector(int* a, unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
		cout << std::setw(5) << a[i];
	cout << std::endl;
}

void manage(void (*Sort)(int * a, unsigned n), int * a, unsigned n)
{
	int * vector = createCopyVector(a, n);
	cout << "\nПеред впорядкуванням:\n"; printVector(vector, n);
	Sort(vector, n);
	cout << "\nПісля впорядкування:\n"; printVector(vector, n); 
	delete[] vector;
}