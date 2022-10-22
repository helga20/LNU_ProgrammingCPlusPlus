#ifndef _GESTS_H_
#define _GESTS_H_

// Гостями закладів харчування бувають Медведі, хлопці, хижаки :)
// Їх описують відповідні класи, ніяк не пов'язані наслідуванням

#include <iostream>
#include <string>
using std::ostream;
using std::string;

#include "food_place.h"

class Bear  // Медвідь має якийсь вік
{
private:
	int age;
public:
	Bear(int y=5):age(y) {}
	friend ostream& operator<<(ostream& os, const Bear& B)
	{
		return os << "Bear " << B.age << " years old";
	}
};
class Boy  // Хлопець має ім'я
{
private:
	string name;
public:
	Boy(string n="Alex"):name(n) {}
	friend ostream& operator<<(ostream& os, const Boy& B)
	{
		return os << "Boy " << B.name;
	}
};
class Predator  // хижаків відрізняють за біологічним видом
{
private:
	string species;
public:
	Predator(string s="Volf"):species(s) {}
	friend ostream& operator<<(ostream& os, const Predator& P)
	{
		return os << P.species;
	}
};

// Спільне у цих РІЗНИХ класів те, що їхні екземпляри споживають визначені
//   напої та закуски, займають тільки свої місця у закладах харчування
// Місце, Напій, Закуска - ХАРАКТЕРИСТИКИ згаданих вище класів
// Їх описують (псевдо)ієрархією шаблонів

// "кореневий", "абстрактний" шаблон, який ніхто не буде використовувати
// він лише задає зразок, а працюватимуть спеціалізації
// Домовляються, що кожна спеціалізація визначатиме потрібний набір типів

template <class Guest> class GuestTraits;
/* place_type, beverage_type, snack_type */

template<> class GuestTraits<Bear>
{ // характеристики медведя, як гостя:
  // місце - килим, напій - згущене молоко, закуска - мед
public:
	typedef Carpet place_type;
	typedef CondensedMilk beverage_type;
	typedef Honey snack_type;
};
template<> class GuestTraits<Boy>
{ // характеристики хлопчика, як гостя:
  // місце - за столом, напій - молоко, закуска - печиво
public:
	typedef Table place_type;
	typedef Milk beverage_type;
	typedef Cookies snack_type;
};
template<> class GuestTraits<Predator>
{ // характеристики хижака, як гостя:
  // місце - клітка, напій - вода, закуска - м'ясо
public:
	typedef Cage place_type;
	typedef Water beverage_type;
	typedef Meat snack_type;
};

#endif