/*
Шаблон класу можна використати як базовий для створення підкласів.
Новий клас-шаблон розширює можливості батьківського.
*/
#include "stackPtn.h"
template <typename Type>
class ExtStack : public Stack<Type>
{
public:
	//повертає значення з вершини без зміни стека
	Type peek() const { return mem[top - 1]; }
};

// Конкретизований шаблон також може бути базовим класом

class StackDbl : public ExtStack<double>
{
public:
	// дає змогу побачити внутрішність стека
	void print() const;
};