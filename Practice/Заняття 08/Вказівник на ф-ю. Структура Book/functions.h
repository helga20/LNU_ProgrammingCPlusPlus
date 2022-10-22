#pragma once

void sayHi();
void sayBye();

int multTwo(int x);
int addFive(int y);

double sum(double a, double b);
double mult(double a, double b);

void doActionIntegers(int a, int (*f)(int));

void readArray(int* arr, const int n);
void printArray(const int* arr, const int n);

void modifyArray(int* arr, const int n, int (*f)(int));