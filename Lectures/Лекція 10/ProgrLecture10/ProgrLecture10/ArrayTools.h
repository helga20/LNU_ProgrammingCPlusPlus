#pragma once

// ������������� ������ ����� ����� �� ���������� � ������������� ��'����� ��������
void sortByList(int * A, size_t n);
void sortByTree(int * A, size_t n);

// ��'������� ���� ������������� ������ � �����
int * merge(int*A, size_t n, int*B, size_t m);

// ��������� ������ �� �������
void writeArray(int* A, size_t n);