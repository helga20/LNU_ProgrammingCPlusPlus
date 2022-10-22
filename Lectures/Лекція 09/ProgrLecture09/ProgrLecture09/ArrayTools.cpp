#include "ListTools.h"
#include "ArrayTools.h"
#include <iostream>

void sortByList(int * A, size_t n)
{
	// ��� ������������ ����� �, �������� �� ���� �������� � ������������� ������
	ListTools::List_t List = nullptr;
	for (size_t i = 0; i < n; ++i) ListTools::insert(A[i], List);
	// � ��� ��������� � ������ ����� � �����
	ListTools::List_t curr = List;
	for (size_t i = 0; i < n; ++i, curr = curr->link) A[i] = curr->value;
	removeList(List);
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