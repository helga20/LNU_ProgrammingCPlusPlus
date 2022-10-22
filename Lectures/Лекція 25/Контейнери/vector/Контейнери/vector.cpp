/*#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

void printOn(vector<int>& Vector);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 11;

	vector<int> Vector; 
	for (int i = 0; i < size; i++) Vector.push_back(i);
	cout << "Вектор: \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// видаляю 2
	Vector.erase(Vector.begin() + 2);
	cout << "Після видалення числа 2: \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// видаляю діапазон [4,9)
	Vector.erase(Vector.begin() + 3, Vector.begin() + 8);
	cout << "Після видалення діапазону [4,9): \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// виводжу максимальний розмір вектора
	int vectorMaxSize = Vector.max_size();
	cout << "Максимальний розмір вектора: " << vectorMaxSize << endl;

	// виводжу розмір вектора
	int vectorSize = Vector.size();
	cout << "Розмір вектора: " << vectorSize << endl;

	// виводжу ємність вектора
	int vectorCapacity = Vector.size();
	cout << "Ємність вектора: " << vectorCapacity << endl;
	cout << "\n";
	system("pause");

	//  вношу в діапазон [2,5) три вісімки
	Vector.insert(Vector.begin() + 2, 3, 8);
	cout << "Після вставки трьох вісімок у діапазон [2,5): \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// видаляю останній елемент
	cout << "Після видалення останнього елемента: \n";
	Vector.pop_back();
	printOn(Vector);
	cout << "\n";
	system("pause");

	// створюю новий вектор і копіюю в нього вміст поперенього вектора 
	vector<int> newVector(Vector.begin(), Vector.end());
	cout << "Новий вектор: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// заповнюю новий вектор одиничками
	newVector.insert(newVector.begin(), newVector.size(), 1);
	cout << "Після вставки одиничок: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// дописую у вектор newVector вміст вектора 
	newVector.assign(Vector.begin(), Vector.end());
	cout << "Після присвоєння вмісту вектора: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// стрираю вектор newVector
	newVector.clear();
	cout << "Спроба вивести порожній вектор: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// порівнюю вектори
	Vector.clear();
	for (int i = 0; i < size; i++)
	{
		Vector.push_back(i);
		newVector.push_back(i + 1);
	}
	cout << "Вектор: ";	  printOn(Vector);
	cout << "Новий вектор: ";	printOn(newVector);
	if (Vector == newVector) cout << "Вектор == Новий вектор\n";
	if (Vector > newVector) cout << "Вектор > Новий вектор\n";
	if (Vector >= newVector) cout << "Вектор >= Новий вектор\n";
	if (Vector < newVector) cout << "Вектор < Новий вектор\n";
	if (Vector <= newVector) cout << "Вектор <= Новий вектор\n";

	cout << "\n";
	system("pause");
	return 0;
}
void printOn(vector<int>& Vector)
{
	if (Vector.empty())
	{
		cout << "Вектор порожній\n";
		return;
	}
	vector<int>::iterator iter;
	for (iter = Vector.begin(); iter != Vector.end(); iter++)
		cout << " " << *iter;
		cout << "\n";
}*/