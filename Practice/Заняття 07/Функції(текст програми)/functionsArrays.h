#pragma once

// Only for static arrays of 10 elements
void readStaticArray10(int (&arr)[10]);
void printStaticArray10(int (&arr)[10]);

// For both static and dynamic arrays of n elements
void readArray(int* arr, int n);
void printArray(const int* arr, int n);
int sumArray(const int* arr, int n);
int minElement(const int* arr, int n);

// Завдання 11
double calculateP(double(&a)[7], double y);
void task11(double(&a)[7]);
double task12(double(&a)[7], double s, double t);