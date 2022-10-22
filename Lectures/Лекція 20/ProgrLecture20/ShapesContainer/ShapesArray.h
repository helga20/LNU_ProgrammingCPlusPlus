/*
 Клас-контейнер, що зберігає послідовність об'ємних фігур (змінної довжини).
  Пам'ять - динамічний масив вказівників на об'єкти (для забезпечення поліморфізму).
  Клас повинен перерозподіляти пам'ять (за потреби), визначати весь набір
  конструкторів, деструктор, оператор присвоєння.
 Функціональність контейнера: додавання елементів у кінець, вставляння всередину,
  вилучення за номером, вилучення всіх, перебір елементів: - друк кожного,
  - зберігання кожного, - виконання довільної дії з кожним, - пошук першого,
  що задовольняє певний критерій.

 Контейнер - власник своїх елементів, керує їхнім життєвим циклом: знищує перед
  своїм знищенням, копіює під час свого копіювання чи присвоєння.
 Труднощі:
  як за поліморфним вказівником довідатися тип об'єкта, що копіюється чи зберігається
     до файла - покласти цю відповідальність на базовий клас збереженого об'єкта
  як забезпечити правильність роботи контейнера (створення фігур лише правильних
     типів, доступ за правильним індексом) - виконувати необхідні перевірки, про
     проблеми сигналізувати об'єктами-винятками
*/
#ifndef _Shapes_Array_
#define _Shapes_Array_

#include "..\Shapes\VolumeShapes.h"

// тип функції, яку можна застосувати до кожного елемента контейнера
typedef void Action(VolShape*);

// тип критерію для перевірки(пошуку) елементів контейнера
typedef bool Predicate(VolShape*);

class ShArray
{
private:
	int used, size;		// розміри виділеної та зайнятої пам'яті
	VolShape** mem;		// вказівник на саму пам'ять
	void checkMem();	// за потреби перерозподіляє пам'ять
	void chekIndex(int i) const { if (i < 0 || i >= used) throw BadIndex(i); }
public:
	class BadIndex: public std::range_error		// позначатиме помилку - неіснуючий індекс
	{
	public:
		int index;
		BadIndex(int i): range_error("Index out of range of the container"), index(i) {}
	};
// найменший контейнер може містити дві фігури
	ShArray(): used(0), size(2), mem(new VolShape*[2]) {}

// можна наперед замовити довільний розмір виділеної пам'яті, щоб запобігти перерозподілам
// explicit захистить від випадкового перетворення цілого числа у контейнер
	explicit ShArray(int n): used(0), size(n), mem(new VolShape*[n]) {}

// обов'язково для класу, що використовує динамічну пам'ять
	ShArray(const ShArray &);
	~ShArray();
	ShArray& operator=(const ShArray &);
// доступ до елементів
	ShArray& put(VolShape*);
	ShArray& insert(VolShape*, int); // throw(BadIndex&)
	ShArray& remove(int);            // throw(BadIndex&)
	ShArray& clear();
	VolShape*& operator[](int);      // throw(BadIndex&)
	const VolShape* operator[](int) const;
	int high() const { return used - 1; }
	void loadFrom(std::ifstream&);   // throw(VolShape::BadClassname&)
// перебір елементів
	void printOn(ostream&) const;
	void storeOn(ofstream&) const;

	void doEach(Action) const;
	int detectFirst(Predicate) const;
};

#endif