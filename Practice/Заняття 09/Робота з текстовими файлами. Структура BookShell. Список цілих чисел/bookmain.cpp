//#include <iostream>
//#include <fstream> // library for reading/writing from/to text file
//#include <string>
//#include "book.h"
//using namespace std;
//
//int main()
//{
//	ifstream iFile("test.txt"); // input file stream
//	int a, b;
//	iFile >> a >> b;
//	cout << "Integers: " << a << "  " << b << "\n";
//	string test;
//	iFile >> test;
//	cout << "String: " << test << "\n";
//	double x;
//	iFile >> x;
//	cout << "Double: " << x << "\n";
//
//	// reading array
//	int n; iFile >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		iFile >> arr[i];
//	}
//	cout << "Array: ";
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << "  ";
//	}
//	cout << "\n";
//	iFile.close(); // close file
//
//	ofstream oFile("oksana.txt"); // output file stream
//	for (int i = 0; i < n; ++i)
//	{
//		oFile << arr[i] << ' ';
//	}
//	oFile << "\n";
//	oFile << x << "\n";
//	oFile << test << "\n";
//	oFile << a << "\n" << b;
//	cout << "Check file oksana.txt\n";
//	oFile.close(); // close file
//	delete[] arr;
//
//	// Read/Write Books
//	iFile.open("bookinfo.txt");
//	Book B1, B2, B3;
//	iFile >> B1 >> B2 >> B3;
//	iFile.close();
//	cout << "\n\tBooks\n";
//	cout << B1 << "\n" << B2 << "\n" << B3 << "\n\n";
//
//	// allbooks.txt
//	oFile.open("allbooks.txt");
//	oFile << B1 << "\n" << B2 << "\n" << B3 << "\n";
//	oFile.close();
//	cout << "\n\tCheck allbooks.txt\n";
//
//
//
//
//
//	system("pause");
//	return 0;
//}