#ifndef _Array_Procs_
#define _Array_Procs_

// Визначення типу потрібне для того, щоб зробити легкою зміну типу даних
using num_type = double;

const size_t N = 10;
using Array = num_type[N];

// Функції для роботи з масивами типу array (зі статичними масивами)
void ReadArray(Array a);
num_type ScalarProduct(Array a, Array b);

// Створення динамічного масиву заданого розміру
num_type* CreateArray(size_t n, num_type x = 0);
// Поелементне введення масиву з консолі
void ReadArray(num_type* a, size_t n);
// Виведення масиву на консоль
void WriteArray(const num_type* a, size_t n);
// Обчислення скалярного добутку векторів
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n);
// Обчислення норми вектора
num_type Norm(const num_type* a, size_t n);

// Різні способи відшукання найбільшого елемента масиву
double maxVal(const double* a, size_t n);
double maxVal(const double* start, const double* end);
double* max(double* start, double* end);

#endif