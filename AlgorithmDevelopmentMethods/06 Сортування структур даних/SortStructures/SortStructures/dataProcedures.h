#ifndef _DATA_PROCEDURES_GUARD_
#define _DATA_PROCEDURES_GUARD_

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;

const unsigned n = 3;
const unsigned m = 4;

void sortEachRow();
void sortMatrix();
void sortMatrixSum();
void sortByChain();
void sortByTree();
void sortByMerge();

void fillFile(ofstream& f, unsigned n);
void showFile(const char * fileName);
void sortFile(const char * fileName);
void distribute(ifstream & f, ofstream & a, ofstream & b, long long & ka, long long & kb);
void mergeFile(ifstream & a, ifstream & b, ofstream & c, long long k);

void readMatrix(int a[n][m]);
void printMatrix(int a[n][m]);
void simpleInsertSort(int * a, unsigned n);
void exchange(int * a, int * b, unsigned n);

#endif