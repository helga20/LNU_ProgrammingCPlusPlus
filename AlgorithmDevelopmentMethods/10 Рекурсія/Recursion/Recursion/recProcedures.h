#ifndef _REC_PROCEDURES_GUARD_
#define _REC_PROCEDURES_GUARD_

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

long long harmFibo(unsigned);
long long Fibonacci(unsigned n);

enum position {Left, Middle, Right};
void moveTower(short h, position from, position _to, position through);

struct extInt
{
	int val;
	char ind;
};
ostream& operator<<(ostream& os, const extInt& x);
bool operator>(const extInt& a, const extInt& b);

void stableQuickSort(extInt *array, int n);
void quickSort(int *array, int low, int high);

struct treeNode; // поперднє оголошення структури потрібне для оголошення вказівника
typedef treeNode* Tree_t; // вказівнику даємо ім'я задля зручності
typedef int dataType_t;   // тип інформаційної частини вершини може бути довільним

struct treeNode
{
	dataType_t val;  // інформацйна частина
	Tree_t left;     // зв'язок з піддеревами
	Tree_t right;
	treeNode() : val(0), left(nullptr), right(nullptr) {}
	treeNode(dataType_t x, Tree_t l, Tree_t r) : val(x), left(l), right(r) {}
};

dataType_t sum(Tree_t t);
dataType_t sumEco(Tree_t t);
dataType_t sumNotEmpty(Tree_t t);
dataType_t Sum(Tree_t t);
void printTree(const Tree_t, unsigned);

void calcFibo();
void solveTowers();
void useQuickSort();
void traverseTree();


#endif