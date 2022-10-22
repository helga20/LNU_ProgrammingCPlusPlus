#pragma once

struct treeNode;
typedef treeNode* Tree_t;

struct treeNode
{
	int val;
	Tree_t left;
	Tree_t right;
	treeNode() : val(0), left(nullptr), right(nullptr) {}
	treeNode(int x, Tree_t l, Tree_t r) : val(x), left(l), right(r) {}
};

// �������� ���� �������� � ������ ������
void searchIncl(Tree_t&, int);
// ��������� ����������� ����� � ������ ������
Tree_t buildTree();
// ����� ������ � ������������ ���������
void writeTree(const Tree_t, unsigned);
// ����� ������ �� �����������
void writeTree(const Tree_t);

// ���� - ����������� ����� �� ������
void printByLevel(const Tree_t);
void printByLevelInLines(const Tree_t Tree);
// ���� - ������������� �����
void printPrefix(const Tree_t);
void printInfix(Tree_t Tree);

// ������ ��� ������
void removeTree(Tree_t& Tree);
// ������ ���� ������� ������ ������
bool withdrawRec(Tree_t& tree, int x);