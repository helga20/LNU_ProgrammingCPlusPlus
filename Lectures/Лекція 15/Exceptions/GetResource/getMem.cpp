#include <iostream>
using namespace std;

/* Клас моделює роботу "розумного вказівника".
   Він інкапсулює справжній вказівник, належним чином перевизначає оператор розіменування.
   Головне завдання - коректно звільнити динамічну пам'ять, що й робить деструктор.
   Поле name - зайве. Його додали виключно для зручності спостереження за об'єктами
*/
class DoublePtr
{
	double * p;
	char name;
public:
	DoublePtr(char n) :name(n) { p = new double; cout << "Get mem for " << name << '\n'; }
	~DoublePtr() { delete p; cout << "Free mem from " << name << '\n'; }
	double& operator*() { return *p; }
};

// Функція демонструє використання розумних вказівників:
// уведіть x>=0 - отримаєте нормальне завершення,
// уведіть x < 0 - отриаєте виняток.
// В обох випадках локальний об'єкт коректно звільняє динамічну пам'ять
void doMem()
{
	DoublePtr a('A'); // Local smart pointer
	double x;
	cout << "Input a number: "; cin >> x;
	if (x < 0) throw "Negative";
	*a = x*2.3;
	cout << x << ' ' << *a << '\n';
}

int main()
{
	DoublePtr b('B'); // Global smart pointer
	// Випробовуємо виконання doMem()
	try
	{
		doMem();
	}
	catch(...)
	{
		cout<< "catched!\n";
	}
	system("pause");

	// Приклад з msdn перехоплення і розпізнання винятку часу виконання
	const char * c = "test"; // неправильний параметр локалізації
	//const char * c = "ukr";
	// runtime_error  
	try
	{
		locale loc(c);
		cout << c << endl;
	}
	catch (exception &e)
	{
		cerr << "Caught " << e.what() << endl;
		cerr << "Type " << typeid(e).name() << endl;
	};
	system("pause");
	return 0;
}