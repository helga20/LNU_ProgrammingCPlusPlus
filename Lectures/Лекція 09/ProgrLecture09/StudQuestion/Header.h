#pragma once
#include <iostream>
#include <functional>

// ��� data ������� ������ ���� ���'������ �����: (����, �����, �����)
// ������� (�������� �������������, �����, �������� ��������)
// ��� ��������� ��� ������������ ������� �� ���� ���������
struct data
{
	int num;
	char letter;
	double point;
	data(int x, char y, double z) :num(x), letter(y), point(z) {}
};

// ��� node �������������� ��� �������� ����� ������
struct node
{
	data val;
	node* link;
	node(int a = 0, char b = '\n', double c = 0.0, node* d = nullptr) :val(data(a, b, c)), link(d) {}
};

std::ostream& operator<<(std::ostream& os, const data&);

using predicate = bool(*)(node*);

// ������� ������ �������� ������ �� ������� ������
node* find(node* L, predicate f);
node* find_f(node* L, std::function<bool(node*)>);

// ���� ���������� ������ � ������
void show(node*);