#include <iostream>
#include "functionsArrays.h"
using namespace std;

int main()
{
	cout << "\nDynamic array: ";
	int n; cin >> n;
	int* b = new int[n];
	readArray(b, n);
	printArray(b, n);
	cout << "\n";
	int prod = prodArray(b, n);
	cout << "Product: " << prod << "\n";
	int max = maxElement(b, n);
	cout << "Max: " << max << "\n";

	
	system("pause");
	return 0;
}