#ifndef _SORTS_PROCEDURES_GUARD_
#define _SORTS_PROCEDURES_GUARD_

#include <iostream>
using std::cout;
using std::cin;

void simpleInsertSort(int * a, unsigned n);
void findMaxSort(int * a, unsigned n);
void bubbleSort(int * a, unsigned n);
void replaceSort(int * a, unsigned n);

int* createRandomVector(unsigned n);
int* createCopyVector(int * a, unsigned n);
void printVector(int* a, unsigned n);
void manage(void (*Sort)(int * a, unsigned n), int * a, unsigned n);

#endif