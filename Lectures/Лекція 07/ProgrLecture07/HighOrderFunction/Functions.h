#pragma once

//typedef double (*func)(double);
using func = double(*)(double);
typedef void(*proc)(void);

// Побудова таблиці значень функції
void Tabulate(func f, double a, double b, double h);

// Рекурсивна реалізація методу поділу відрізка навпіл
double bisection(func f, double a, double b, double eps = 1e-8);

// Процедури, що виконують окремі "розділи" великої програми
void CalculateRoots();
void Integrate();
void DeelWithArray();