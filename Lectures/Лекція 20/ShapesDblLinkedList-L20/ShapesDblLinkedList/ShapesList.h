/*
 Клас-контейнер, що зберігає послідовність об'ємних фігур (змінної довжини).
  Пам'ять - двозв'язний список вказівників на об'єкти (для забезпечення поліморфізму)
    з заголовною ланкою.
  Клас повинен динамічно виділяти/звільняти пам'ять, визначати весь набір
  конструкторів, деструктор, оператор присвоєння.
 Функціональність контейнера: додавання елементів у кінець, вставляння всередину,
  вилучення за номером, вилучення всіх, перебір елементів:
  - друк кожного,
  - зберігання кожного,
  - виконання довільної дії з кожним,
  - пошук першого, що задовольняє певний критерій.

 Контейнер - власник своїх елементів, керує їхнім життєвим циклом: знищує перед
  своїм знищенням, копіює під час свого копіювання чи присвоєння.
 Труднощі:
  як за поліморфним вказівником довідатися тип об'єкта, що копіюється чи зберігається
     до файла - покласти цю відповідальність на базовий клас збереженого об'єкта
  як забезпечити правильність роботи контейнера (створення фігур лише правильних
     типів, доступ за правильним індексом) - виконувати необхідні перевірки, про
     проблеми сигналізувати об'єктами-винятками
*/
#ifndef _Shapes_DblList_
#define _Shapes_DblList_

#include "..\Shapes\VolumeShapes.h"

// тип функції, яку можна застосувати до кожного елемента контейнера
typedef void Action(VolShape*);

// тип критерію для перевірки(пошуку) елементів контейнера
typedef bool Predicate(VolShape*);

class ShDblList
{
private:
	// Ланка списку
	struct Node
	{
		VolShape* shape;
		Node* prev;
		Node* next;
		Node(VolShape* s = nullptr, Node* p = nullptr, Node* n = nullptr) :shape(s), prev(p), next(n) {}
		~Node() { delete shape; }
	};
	int len;		// кількість елементів списку (ланок)
	Node* mem;		// вказівник на саму пам'ять - на початок списку
	Node* bottom;	// остання ланка списку 
	// поля даних для пришвидшення індексування
	mutable Node* curr;		// помічник індексування
	mutable int index;		// номер останньої індексованої ланки
	bool chekIndex(int i) const { if (i < 0 || i >= len) throw BadIndex(i); }
	void moveCurr(int i) const;
public:
	class BadIndex: public std::range_error		// позначатиме помилку - неіснуючий індекс
	{
	public:
		int index;
		BadIndex(int i): range_error("Index out of range of the container"), index(i) {}
	};
// найменший контейнер - це порожній список, що містить лише заголовну ланку
	ShDblList(): len(0), mem(new Node()), index(-1)
	{
		curr = bottom = mem;
	}

// конструктор з розміром контейнера оголошено заради сумісності
// explicit захистить від випадкового перетворення цілого числа у контейнер
	explicit ShDblList(int n) : ShDblList() {}

// обов'язково для класу, що використовує динамічну пам'ять
	ShDblList(const ShDblList &);
	~ShDblList();
	ShDblList& operator=(const ShDblList &);
// доступ до елементів
	ShDblList& put(VolShape*);
	ShDblList& insert(VolShape*, int); // throw(BadIndex&)
	ShDblList& remove(int);            // throw(BadIndex&)
	ShDblList& clear();
	VolShape*& operator[](int);      // throw(BadIndex&)
	const VolShape* operator[](int) const;  //як це реалізовано? адже всяке індексування змінює окремі поля контейнера!
	int high() const { return len - 1; }
	void loadFrom(std::ifstream&);   // throw(VolShape::BadClassname&)
// перебір елементів
	void printOn(ostream&) const;
	void storeOn(ofstream&) const;
	void doEach(Action) const;
	int detectFirst(Predicate) const;
};

#endif