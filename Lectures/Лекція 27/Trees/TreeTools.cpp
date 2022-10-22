#include "TreeTools.h"
#include <iostream>
#include <queue>
#include <stack>

void searchIncl(Tree_t& T, int x)
{
	// �������� �������� x � ������ ������ T
	if (T != nullptr)
	{
		if (x < T->val) searchIncl(T->left, x);
		else searchIncl(T->right, x);
	}
	else
	{
		T = new treeNode(x, nullptr, nullptr);
	}
}
Tree_t buildTree()
{
	// ��������� ����������� �����, ����� �������� � ������
	std::cout << "Enter a sequence of different numbers to build the tree:\n";
	// �������� ������ ������
	Tree_t T = nullptr;
	int x = 0;
	// ����������-������������
	while (std::cin >> x) searchIncl(T, x);
	// ���������� ����� ������ ��������
	std::cin.clear();
	while (std::cin.get() != '\n') continue;
	return T;
}
// ����� ������ �� �����������
void writeTree(const Tree_t T)
{
	// ���� ����� ������ � �����, ������� ������ inorder
	if (T != nullptr)
	{
		writeTree(T->left);
		std::cout << '\t' << T->val;
		writeTree(T->right);
	}
}
void writeTree(const Tree_t T, unsigned shift)
{
	// ���� �������� ������ �� ������ � ����� � ���������, �� ��������� ��������� ������
	if (T != nullptr) {
		writeTree(T->left, shift + 1);
		for (unsigned i = 0; i < shift; ++i) std::cout << '\t';
		std::cout << T->val << '\n';
		writeTree(T->right, shift + 1);
	}
}

// ���� - ����������� ����� �� ������
// ����������� ����� ��� �����'���������� ��� ����� ������� ����
void printByLevel(const Tree_t Tree)
{
	std::queue<Tree_t> nodes;
	nodes.push(Tree);
	while (!nodes.empty())
	{
		Tree_t t = nodes.front(); nodes.pop();
		std::cout << '\t' << t->val;
		if (t->left != nullptr) nodes.push(t->left);
		if (t->right != nullptr) nodes.push(t->right);
	}
}
void printByLevelInLines(const Tree_t Tree)
{
	std::queue<Tree_t> nodes;
	nodes.push(Tree); int count = 1;
	while (count > 0)
	{
		int subcount = 0;
		for (int i = 0; i < count; ++i)
		{
			Tree_t t = nodes.front(); nodes.pop();
			std::cout << '\t' << t->val;
			if (t->left != nullptr)
			{
				nodes.push(t->left);
				++subcount;
			}
			if (t->right != nullptr)
			{
				nodes.push(t->right);
				++subcount;
			}
		}
		std::cout << '\n';
		count = subcount;
	}
}

// ���� - ������������� �����
// ����������� ���� ��� �����'���������� ���������� �������
void printPrefix(const Tree_t Tree)
{
	std::stack<Tree_t> subtrees;
	subtrees.push(Tree);
	while (!subtrees.empty())
	{
		Tree_t t = subtrees.top(); subtrees.pop();
		while (t != nullptr)
		{
			std::cout << '\t' << t->val;
			if (t->right != nullptr) subtrees.push(t->right);
			t = t->left;
		}
	}
}
void printInfix(Tree_t Tree)
{
	std::stack<Tree_t> nodes;
	while (!nodes.empty() || Tree != nullptr)
	{
		if (Tree != nullptr)
		{
			nodes.push(Tree);
			Tree = Tree->left;
		}
		else
		{
			Tree = nodes.top(); nodes.pop();
			std::cout << '\t' << Tree->val;
			Tree = Tree->right;
		}
	}
}

void removeTree(Tree_t& Tree)
{
	if (Tree != nullptr)
	{
		removeTree(Tree->left);
		removeTree(Tree->right);
		delete Tree;
		Tree = nullptr;
	}
}

Tree_t toDel;
// �������� �������
void delLast(Tree_t& r)
{
	if (r->right != nullptr) delLast(r->right);
	else
	{
		toDel->val = r->val;
		toDel = r;
		r = r->left;
	}
}
// ������� ������� ��� ���������
bool withdrawRec(Tree_t& tree, int x)
{
	if (tree == nullptr) return false; // ������ ����� ����
	else if (x < tree->val)
	{
		return withdrawRec(tree->left, x);
	}
	else if (x > tree->val)
	{
		return withdrawRec(tree->right, x);
	}
	else
	{
		toDel = tree;
		if (toDel->right == nullptr)
		{
			tree = toDel->left;
		}
		else if (toDel->left == nullptr)
		{
			tree = toDel->right;
		}
		else
		{
			delLast(tree->left);
		}
		delete toDel;
		return true;
	}
}