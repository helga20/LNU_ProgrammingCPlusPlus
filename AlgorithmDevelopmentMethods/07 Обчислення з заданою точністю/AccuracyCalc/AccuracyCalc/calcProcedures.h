#ifndef _CALC_PROCEDURES_GUARD_
#define _CALC_PROCEDURES_GUARD_

#define _USE_MATH_DEFINES

#include <iostream>
using std::cout;
using std::cin;

void sinSeriesSum();
void sumOfSeriesB();
void dichotomy();
void numIntegration();
void lambdaIntegration();

typedef double(*func)(double);

double dychotom(func f, double a, double b, double eps = 1e-8);
double dychotomRec(func f, double a, double b, double eps = 1e-8);

double leftRect(double a, double b, func f, double eps = 1e-6);

#endif