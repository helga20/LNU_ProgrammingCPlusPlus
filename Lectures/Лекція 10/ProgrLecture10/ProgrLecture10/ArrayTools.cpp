#include "ListTools.h"
#include "TreeTools.h"
#include "ArrayTools.h"
#include <iostream>

void sortByList(int * A, size_t n)
{
	// щоб упорядкувати масив А, помістимо всі його елементи у впорядкований список
	ListTools::List_t List = nullptr;
	for (size_t i = 0; i < n; ++i) ListTools::insert(A[i], List);
	// а тоді повернемо зі списку назад в масив
	ListTools::List_t curr = List;
	for (size_t i = 0; i < n; ++i, curr = curr->link) A[i] = curr->value;
	removeList(List);
}
// допоміжна функція обходить дерево t і збирає значення в масив a
// pos відслідковує місце в масиві, куди заносять значення
void takeValues(Tree_t t, int * a, size_t& pos)
{
	if (t->left != nullptr) takeValues(t->left, a, pos);
	a[pos++] = t->val;
	if (t->right != nullptr) takeValues(t->right, a, pos);
}
void sortByTree(int * A, size_t n)
{
	// щоб упорядкувати масив А, помістимо всі його елементи у впорядковане дерево
	Tree_t Tree = nullptr;
	for (size_t i = 0; i < n; ++i) searchIncl(Tree, A[i]);
	// а тоді повернемо з дерева назад в масив
	size_t k = 0;
	takeValues(Tree, A, k);
	removeTree(Tree);
}
int * merge(int*A, size_t n, int*B, size_t m)
{
	size_t i = 0, j = 0, k = 0;
	int* C = new int[n + m];
	while (i < n && j < m)
	{
		if (A[i] < B[j]) C[k++] = A[i++];
		else C[k++] = B[j++];
	}
	while (i < n) C[k++] = A[i++];
	while (j < m) C[k++] = B[j++];
	return C;
}
void writeArray(int* A, size_t n)
{
	for (size_t i = 0; i < n; ++i)
		std::cout << '\t' << A[i];
	std::cout << '\n';
}