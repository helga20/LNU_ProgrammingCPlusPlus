#pragma once

//класи користувача для позначення винятків
class DivByZero {};
class ZeroArg {};

// обчислення середнього арифметичного
double arithmetic(double, double);

// обчислення середнього геометричного
// генерує виняток у випадку від'ємних аргументів
double geometric(double, double) throw(const char*);

// функції для обчислення середнього гармонійного, різні способи опрацювання помилок
// - завершує програму
double harmonic_1(double, double);
// - повертає ознаку успіху
  bool harmonic_2(double, double, double*);
// - запускає виняток
double harmonic_3(double, double) throw(const char*);
// - запускає добре типізовані винятки
double harmonic_4(double, double) throw(DivByZero, ZeroArg);
// - запускає виняток стандартного класу
double harmonic_5(double, double);