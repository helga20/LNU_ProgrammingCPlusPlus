#pragma once
#include <iostream>
using namespace std;

// Returns sum of a and b
double sum(double a, double b);
double sum1(double a, double b);

// Returns minimum of a and b
double min(double a, double b);

// Returns max of a and b
double max(double a, double b);
double max1(double a, double b);

// Периметр прямокутника
double perimOfRectangle(double a, double b);

// Площа прямоктника
double squareOfRectangle(double a, double b);

// Збільшує вхідний параметр в 5 разів
void multFive(int& a); // за посиланням

// Обмін значеннями
void swapValues(double& a, double& b);
