#pragma once

// впор€дкуванн€ масиву ц≥лих чисел за зростанн€м з використанн€м зв'€зних структур
void sortByList(int * A, size_t n);
void sortByTree(int * A, size_t n);

// об'Їднанн€ двох впор€дкованих масив≥в у новий
int * merge(int*A, size_t n, int*B, size_t m);

// виведенн€ масиву на консоль
void writeArray(int* A, size_t n);