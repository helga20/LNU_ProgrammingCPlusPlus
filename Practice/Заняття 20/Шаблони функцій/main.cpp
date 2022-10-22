#include <iostream>
#include <string>
#include "car.h"
#include "book.h"
#include "simplefunctions.h"
#include "arrayfunctions.h"
using namespace std;

int main()
{
	const int N = 5;
	int arr1[N] = { 3, 2, 1, 5, 4};
	double arr2[7] = { 4.4, 3.3, 5.5, 1.1, 6.6, 2.2, 7.7 };
	printArray_1<int>(arr1, N);
	printArray_2<int, N>(arr1);
	printArray_3<int>(arr1);
	int sumArr1 = sumArray<int>(arr1);
	cout << "Sum of integers: " << sumArr1 << "\n";
	cout << "Min integer: " << minNumberInArray<int>(arr1) << "\n";

	cout << "\n";
	printArray_1<double>(arr2, 5);
	printArray_2<double, 5>(arr2);
	printArray_3<double>(arr2);
	double sumArr2 = sumArray<double>(arr2);
	cout << "Sum of doubles: " << sumArr2 << "\n";
	cout << "Min double: " << minNumberInArray<double>(arr2) << "\n";

	//cout << "\n";
	//int K; cin >> K;
	//int* arr3 = new int[K];
	//for (int i = 0; i < K; ++i)
	//	cin >> arr3[i];
	//printDynamicArray<int>(arr3, K);
	cout << "\n";

	Car C1("Seat", 160000);
	Car C2("Fiat", 30000);
	Car C3("Audi", 250010);
	Car carsArray[3] = { C1, C2, C3 };
	printBucket<Car>(carsArray);
	printBucketDynamic<Car>(carsArray, 3);
	double carSum = sumBucket<Car>(carsArray, 3);
	cout << "Bucket price: " << carSum << "\n";
	int minCarIndex = minElement<Car>(carsArray, 3);
	cout << "Cheapest Car is\n";
	carsArray[minCarIndex].print();
	cout << "\n\n";

	Book B1("Kostenko", "Poems", 210);
	Book B2("Tolkien", "Lord of the Rings", 380);
	Book* booksArray = new Book[2];
	booksArray[0] = B1;
	booksArray[1] = B2;
	printBucketDynamic<Book>(booksArray, 2);
	double bookSum = sumBucket<Book>(booksArray, 2);
	cout << "Bucket price: " << bookSum << "\n";
	int minBookIndex = minElement<Book>(booksArray, 2);
	cout << "Cheapest Book is\n";
	booksArray[minBookIndex].print();
	cout << "\n\n";








	/*
	int a = 10;
	printIntValue(a);
	double b = 5.15;
	printDoubleValue(b);

	printValue<int>(a);
	printValue<double>(b);
	printValue<string>("Oksana");

	cout << "\n10 and 5 " << averageVal<int>(a, 5) << "\n";
	cout << "5.5 and 1.1 " << averageVal<double>(b, 1.1) << "\n";

	int aCoef = applyCoef<int>(a, 7);
	cout << "\nBefore: " << a << " After: " << aCoef << "\n";
	double bCoef = applyCoef<double>(b, 10);
	cout << "Before: " << b << " After: " << bCoef << "\n\n";

	printSaleResult<int, double>(a, 2.5);
	printSaleResult<double, double>(b, 10.2);
	printSaleResult<double, int>(b, 2);
	cout << "\n\n";

	Car C1("Seat", 160000);
	Book B1("Kostenko", "Poems", 210);
	printInfo<Car>(C1);
	printInfo<Book>(B1);
	cout << "\n";
	printPriceInfo<Car>(C1, "euro");
	printPriceInfo<Book>(B1, "uah");
	cout << "\n";
	*/

	delete[] booksArray;
	return 0;
}