#pragma once
#include <iostream>
#include <functional>

// Тип data моделює деякий набір пов'язаних даних: (ціле, літера, дійсне)
// буцімто (числовий ідентифікатор, назва, числовий показник)
// тип вигаданий для демонстрації доступу до полів структури
struct data
{
	int num;
	char letter;
	double point;
	data(int x, char y, double z) :num(x), letter(y), point(z) {}
};

// Тип node використовують для побудови ланок списку
struct node
{
	data val;
	node* link;
	node(int a = 0, char b = '\n', double c = 0.0, node* d = nullptr) :val(data(a, b, c)), link(d) {}
};

std::ostream& operator<<(std::ostream& os, const data&);

using predicate = bool(*)(node*);

// функції пошуку елемента списку за заданою умовою
node* find(node* L, predicate f);
node* find_f(node* L, std::function<bool(node*)>);

// друк результатів пошуку в списку
void show(node*);