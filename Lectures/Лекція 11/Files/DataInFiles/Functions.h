#pragma once
#include <iostream>

// Визначення типу потрібне для того, щоб зробити легкою зміну типу даних
using num_type = double;

// Поелементне введення масиву з потоку
void ReadArrayFromStream(num_type* a, size_t n, std::istream& is);
// Обчислення скалярного добутку векторів
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n);
// Виведення масиву на консоль
void WriteArray(num_type* a, size_t n);

using func = double(*)(double);
typedef void(*proc)(void);

// Побудова таблиці значень функції
void TabulateToStream(std::ostream& os, func f, double a, double b, double h);