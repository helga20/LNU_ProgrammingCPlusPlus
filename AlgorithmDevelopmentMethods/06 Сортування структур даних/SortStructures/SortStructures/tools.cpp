#include "dataProcedures.h"
#include "newTypes.h"

void readMatrix(int a[n][m])
{
	cout << "Введіть елементи матриці " << n << 'x' << m << '\n';
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) cin >> a[i][j];
}

void printMatrix(int a[n][m])
{
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j) cout << '\t' << a[i][j];
		cout << '\n';
	}
}

// ВПОРЯДКУВАННЯ МАСИВУ а ПРОСТИМИ ВСТАВКАМИ
void simpleInsertSort(int * a, unsigned n)
{
	// спочатку впорядкованим є лише перший елемент послідовності
	// переберемо всі інші і кожен з них вставимо на відповідне місце
	for (unsigned j = 1; j < n; ++j)
	{
		// шукаємо місце для j-го елемента
		int b = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > b)
		{					// посуваєм впорядковані елементи
			a[i + 1] = a[i];
			--i;
		}
		// вставляєм j-ий елемент у впорядковану частину
		a[i + 1] = b;
	}
	return;
}

// Обмін значань двох масивів (рядків матриці)
void exchange(int * a, int * b, unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
	{
		int toSwap = a[i];
		a[i] = b[i];
		b[i] = toSwap;
	}
}

// Оператори введення-виведення даних
std::istream& operator>>(std::istream& is, dataEntry& E)
{
	is >> E.key >> E.value;
	return is;
}
std::ostream& operator<<(std::ostream& os, const dataEntry& E)
{
	os << E.key << '\t' << E.value;
	return os;
}

// Друк однозв'язного списку
void printChain(chainNode* head, std::ostream& os)
{
	while (head != nullptr)
	{
		os << '\t' << head->elem << '\n';
		head = head->link;
	}
}

// Вставка ланки у впорядкований список
void insertNode(chainNode* head, const dataEntry& E)
{
	chainNode * q = head;
	// Пошук місця
	while (q->link != nullptr && q->link->elem.key < E.key)
		q = q->link;
	// Вставляння
	q->link = new chainNode(E, q->link);
}

// Вилучення з пам'яті однозв'язного списку
void deleteChain(chainNode*& head)
{
	chainNode * victim;
	while (head != nullptr)
	{
		victim = head;
		head = head->link;
		delete victim;
	}
}

// Виведення елементів дерева в потік (inorder обхід)
void printTree(treeNode* root, std::ostream& os)
{
	if (root->left != nullptr) printTree(root->left, os);
	os << '\t' << root->elem << '\n';
	if (root->right != nullptr) printTree(root->right, os);
}

// Вставляння значення у дерево пошуку
void insertTreeNode(treeNode*& root, const dataEntry& E)
{
	if (root == nullptr)
		root = new treeNode(E);
	else if (E.key < root->elem.key)
		insertTreeNode(root->left, E);
	else
		insertTreeNode(root->right, E);
}

// Вилучення з пам'яті дерева пошуку
void deleteTree(treeNode*& root)
{
	if (root->right != nullptr) deleteTree(root->right);
	if (root->left != nullptr) deleteTree(root->left);
	delete root;
}