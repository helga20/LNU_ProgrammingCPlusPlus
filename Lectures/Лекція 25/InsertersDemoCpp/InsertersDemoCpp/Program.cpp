/* Програма демонструє використання різноманітних ітераторів:
   контейнерних, потокових, вставки */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <Windows.h>
// директива замість багатьох оголошень заради економії місця
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	// Використаємо вбудований масив і послідовний контейнер
	// Заради простоти наповнимо їх цілими числами
	int a[] = { 1,2,3,4,5,6,7,8 };
	const int n = sizeof a / sizeof *a;
	int b[n] = { 0 };

	// традиційне виведення масивів на консоль
	cout << "\n * Масив а *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << a[i];
	cout << "\n * Масив b - початкове значення *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << b[i];
	cout << '\n';
	system("pause");

	// очевидний приклад використання алгоритму копіювання
	copy(a, a + n, b);
	cout << "\n * Масив b - значення після копіювання *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << b[i];
	cout << '\n';
	system("pause");

	// потоковий ітератор для виведення на консоль
	// потрібно задати три параметри:
	//  - шаблона - тип даних, які треба виводити
	//  - конструктора - потік і рядок-розділювач
	ostream_iterator<int> out(cout, "\t");
	// виведення на консоль за допомогою копіювання
	cout << "\n * Масив а - виведення копіюванням *\n";
	copy(a, a + n, out);
	cout << "\n * Масив b - виведення копіюванням *\n";
	copy(b, b + n, out);
	cout << '\n';
	system("pause");

	// неочевидне виведення на консоль
	cout << "\n --- Демонстрація можливостей потокового ітератора\n";
	for (int i = 7; i < 99; i += 10) *out++ = i;
	cout << '\n';
	system("pause");

	// виведення контейнера на консоль за допомогою копіювання
	// ітератори надасть сам контейнер
	vector<int> A = { 10,20,30,40,50,60,70,80 };
	cout << "\n * Вектор А - виведення копіюванням *\n";
	copy(A.begin(), A.end(), out);
	cout << '\n';
	system("pause");

	// копіювання контейнерів, розмір відомий
	vector<int> B(A.size());
	copy(A.begin(), A.end(), B.begin());
	cout << "\n * Вектор B - після копіювання *\n";
	copy(B.begin(), B.end(), out);
	cout << '\n';
	system("pause");

	// Джерело і приймач можуть бути різних типів
	copy(a, a + n, B.begin());
	cout << "\n * Вектор B - після копіювання з масиву *\n";
	copy(B.begin(), B.end(), out);
	cout << '\n';
	system("pause");

	// Копіювання може змінити розмір приймача, якщо використати спеціальний ітератор
	vector<int> C = { 55 };
	cout << "\n * Вектор C - початкове значення *\n";
	copy(C.begin(), C.end(), out);
	copy(A.begin(), /*A.end(),*/ back_inserter(C));
	cout << "\n * Вектор C - після копіювання *\n";
	copy(C.begin(), C.end(), out);
	cout << '\n';
	system("pause");

	// ітератори можна використовувати в конструкторах
	vector<int> D(C.begin(), C.end());
	cout << "\n * Вектор D - після конструювання *\n";
	copy(D.begin(), D.end(), out);
	cout << '\n';
	system("pause");

	// файлові ітератори можна використовувати для виведення вмісту контейнера,
	// для завантаження контейнера з файла, для створення контейнера з файла
	ofstream fout("Integers.txt");
	copy(D.begin(), D.end(), ostream_iterator<int>(fout, "\t")); // виведення
	fout.close();
	cout << "\n * Вектор D записано до файла *\n";
	system("copy Integers.txt con");
	cout << '\n';
	system("pause");

	// Завантаження з файла
	ifstream fin("Integers.txt");
	A.clear(); // оголошений раніше контейнер очистимо від старого вмісту
	// Для початкового ітератора потрібно задати файловий потік
	// Кінцевий ітератор повертає конструктор за замовчуванням
	copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(A));
	cout << "\n * Вектор А - після завантаження з файла *\n";
	copy(A.begin(), A.end(), out);
	cout << '\n';
	fin.close();
	system("pause");

	// Створення з файла. Для коректної роботи конструктора обов'язково
	// оголосити стартовий ітератор як іменовану змінну
	fin.open("Integers.txt");
	istream_iterator<int> start_iter(fin), end_iter;
	vector<int> E(start_iter, end_iter);
	//vector<int> E(start_iter, istream_iterator<int>()); // можна і так
	cout << "\n * Вектор E - після створення з файла *\n";
	copy(E.begin(), E.end(), out);
	cout << '\n';
	fin.close();
	system("pause");

	return 0;
}