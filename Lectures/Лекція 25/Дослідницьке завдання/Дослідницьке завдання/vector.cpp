//Приклад вектора
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& array);
int main()
{
	const int SIZE = 10;
	vector<int> array; // Порожній вектор
	// Заповнюємо вектор за допомогою функції-члена push_back()

	for (int i = 0; i < SIZE; i++) array.push_back(i);
	// Виводимо вектор на екран
	printf("Вихідний вектор\n");
	print(array);
	// Видаляємо 5-й елемент вектора

	array.erase(array.begin() + 4);
	printf("Після видалення числа 4\n");
	print(array);
	// Видаляємо діапазон [6,9)
	array.erase(array.begin() + 5, array.begin() + 8);
	printf("Після видалення чисел 6, 7 й 8\n");
	print(array);
	// Виводимо на печатку зарезервований розмір вектора
	int arrayMaxSize = array.max_size();
	printf("Максимальний розмір вектора = %d\n", arrayMaxSize);

	// Виводимо на печатку розмір вектора
	int arraySize = array.size();
	printf("Розмір вектора = %d\n", arraySize);
	// Виводимо на печатку ємність вектора
	int arrayCapacity = array.size();
	printf("Ємність вектора = %d\n", arrayCapacity);
	// Вставляємо в діапазон [1,5) чотири п'ятірки й виводимо вектор на печатку
	array.insert(array.begin() + 1, 4, 5);
	printf("Після вставки чотирьох п'ятірок у діапазон [1,5) \n");
	print(array);
	// Видаляємо останній елемент
	printf("Після видалення останнього елемента\n");
	array.pop_back();
	print(array);
	// Повідомляємо новий вектор. Копіюємо в нього вміст вектора array
	vector<int> newArray(array.begin(), array.end());
	printf("Вектор newArray\n");
	print(newArray);
	// Заповнюємо вектор newArray сімками
	newArray.insert(newArray.begin(), newArray.size(), 7);
	printf("Після вставки сімок\n");
	print(newArray);
	// Дописуємо у вектор newArray уміст вектора newArray
	newArray.assign(array.begin(), array.end());
	printf("Після присвоєння вектора array\n");
	print(newArray);
	// Стираємо вектор newArray
	newArray.clear();
	printf("Спроба вивести порожній вектор\n");
	print(newArray);
	// Порівняння векторів
	array.clear();
	for (i = 0; i < SIZE; i++)
	{
		array.push_back(i);
		newArray.push_back(i + 1);
	}
	printf("Вектор array: ");
	print(array);
	printf("Вектор newArray: ");
	print(newArray);
	if (array == newArray) printf("array == newArray\n");
	if (array > newArray) printf("array > newArray\n");
	if (array >= newArray) printf("array >= newArray\n");
	if (array < newArray) printf("array < newArray\n");
	if (array <= newArray) printf("array <= newArray\n");
	return 0;
}
void print(vector<int>& array)
{
	if (array.empty())
	{
		printf("%s \n", "Вектор порожній");
		return;
	}

	vector<int>::iterator iter;
	for (iter = array.begin(); iter != array.end(); iter++)
		printf("%d ", *iter);
	printf("\n");