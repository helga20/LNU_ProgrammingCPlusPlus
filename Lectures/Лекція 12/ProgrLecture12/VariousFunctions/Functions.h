#pragma once

int maxVal(int a, int b, int c);
double maxVal(double * A, unsigned n);

void writeLine(char c = '-', unsigned k = 80);
char * left(const char * str, int n = 1);

inline double sqr(double x) { return x * x; }

void writeSum(int d ...);
void PrintVar(char *szTypes, ...);
void ShowVar(char *szTypes, ...);

unsigned printChars(char c, int k);