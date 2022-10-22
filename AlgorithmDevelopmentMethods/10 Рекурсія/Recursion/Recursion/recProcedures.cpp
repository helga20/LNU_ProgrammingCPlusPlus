#include "recProcedures.h"
#include <chrono>

long long harmFibo(unsigned n)
{
	if (n < 2) return 1LL;                         // ������������ ����'����
	else return harmFibo(n - 1) + harmFibo(n - 2); // ��������
}

long long factorial(unsigned n)
{
	if (n < 2) return 1LL;            // ������������ ����'����
	else return n * factorial(n - 1); // ��������
}

long long fibo(long long a, long long b, unsigned n)
{
	if (n < 1) return a;               // ������������ ����'����
	else return fibo(b, a + b, n - 1); // ��������
}
long long Fibonacci(unsigned n)
{
	return fibo(1, 1, n);
}

void calcFibo()
{
	cout << "* ���������� ����� Գ������� *\n\n";
	unsigned n;
	cout << "������ n: "; cin >> n;
	cout << "������� ������������ �������\n F(" << n << ") = ";
	auto begin = std::chrono::steady_clock::now();
	long long F = harmFibo(n);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << F << "   " << elapsed_ms.count() << " ms ellapsed\n";
	cout << "������� ������������ ���������\n F(" << n << ") = ";
	begin = std::chrono::steady_clock::now();
	F = Fibonacci(n);
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << F << "   " << elapsed_ms.count() << " ms ellapsed\n";
}

// ================================================================================

// ����� ������� ���� ���������� ������ �����
void moveDisk(position from, position _to)
{
	static const char* name[3] = {" Left ", "Middle", " Right"};
	cout << name[from] << " --> " << name[_to] << '\n';
}
// ���� ����������� ������ ��� ���������� ��� �
// h ����� � ������� from �� ��������� _to
void moveTower(short h, position from, position _to, position through)
{
	if (h == 1) moveDisk(from, _to);   // �������� ������
	else
	{                                  // �������� �� ���� ����� ������ h-1
		moveTower(h - 1, from, through, _to);
		moveDisk(from, _to);
		moveTower(h - 1, through, _to, from);
	}
}
void solveTowers()
{
	cout << "* ����'�������� ������ ��� �������� ��� *\n\n";
	short h;
	cout << "������ ������ ���: "; cin >> h;
	moveTower(h, Left, Right, Middle);
}

// ================================================================================

void printArr(extInt *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout.width(3); cout << a[i];
	}
	cout << '\n';
}
ostream& operator<<(ostream& os, const extInt& x)
{
	os << x.val << '-' << x.ind;
	return os;
}
bool operator>(const extInt& a, const extInt& b)
{
	return a.val > b.val;
}
// ��������� �������� ���������� ������ a ������ n
void stableQuickSort(extInt *a, int n)
{
	// ������������ ������
	int i = 0; // ����� ����������� �������, ����� ��������-������������
	int j = 1; // ������� ������������� �������
	while (j < n)
	{
		if (a[i] > a[j])
		{                // ����� �������� ���� ��� ������� �� ������������
			extInt c = a[j];
			for (int k = j - 1; k >= i; --k) a[k + 1] = a[k];
			a[i] = c;
			++i; 
		}
		// ������ �� ������������ ���������� ��������
		++j;
	}
	if (i > 1) stableQuickSort(a, i);           // ������������ �����
	if (n - i > 1) stableQuickSort(a + i + 1, n - i - 1); // �� �����
}

void quickSort(extInt *a, int low, int high)
{
	// ������������ ������
	int i = low;                   // ����� ���� ����� ������
	int j = high;                  // ������ ���� ����� ������
	extInt pivot = a[(i + j) / 2]; // �������-�����������
	while (i <= j)
	{
		while (pivot > a[i]) i++;  // � ����� �� ������� "�������������"
		while (a[j] > pivot) j--;  // j ����� �� ������� "�������������"
		if (i < j)                 // ���� ���������� �� � ���� ������,
		{                          // �� �� ����� ������� ������
			extInt c = a[i];
			a[i] = a[j];
			a[j] = c;
			++i; --j;
		}
		else if (i == j)
		{
			++i; --j;
		}
	}
	if (j > low) quickSort(a, low, j);   // ������������ �����
	if (i < high) quickSort(a, i, high); // �� �����
}

void useQuickSort()
{
	cout << "* ������������� ������ ����� \"�����\" *\n\n";
	extInt a[] = { { 5, 'a' }, { 3, 'a' }, { 9, 'a' }, { 2, 'a' }, { 1, 'a' }, { 2, 'b' }, { 6, 'a' }, { 5, 'b' }, { 8, 'a' }, { 3, 'b' },
	               { 4, 'a' }, { 7, 'a' }, { 2, 'c' }, { 8, 'b' }, { 5, 'c' }, { 5, 'd' } };
	extInt b[] = { { 5, 'a' }, { 3, 'a' }, { 9, 'a' }, { 2, 'a' }, { 1, 'a' }, { 2, 'b' }, { 6, 'a' }, { 5, 'b' }, { 8, 'a' }, { 3, 'b' },
	               { 4, 'a' }, { 7, 'a' }, { 2, 'c' }, { 8, 'b' }, { 5, 'c' }, { 5, 'd' } };
	const int n = sizeof a / sizeof a[0];
	cout << "���������� �����\n";
	printArr(a, n);
	cout << "���������� �������� ���������� ����������\n";
	stableQuickSort(a, n);
	printArr(a, n);
	quickSort(b, 0, n - 1);
	cout << "���������� �������� ����������\n";
	printArr(b, n);
}

// ================================================================================

dataType_t sum(Tree_t t)
{
	if (t == nullptr) return 0;
	else
		return t->val + sum(t->left) + sum(t->right);
}

dataType_t sumEco(Tree_t t)
{
	if (t == nullptr) return 0;
	else
	{
		dataType_t s = t->val;
		if (t->left != nullptr) s += sumEco(t->left);
		if (t->right != nullptr) s += sumEco(t->right);
		return s;
	}
}

dataType_t sumNotEmpty(Tree_t t)
{
	dataType_t s = t->val;
	if (t->left != nullptr) s += sumNotEmpty(t->left);
	if (t->right != nullptr) s += sumNotEmpty(t->right);
	return s;
}
dataType_t Sum(Tree_t t)
{
	return (t == nullptr) ? 0 : sumNotEmpty(t);
}

// ����� ������ � ������������ ���������
void printTree(const Tree_t t, unsigned shift)
{
	// ���� �������� ������ �� ������ � ����� � ���������, �� ��������� ��������� ������
	if (t != nullptr)
	{
		printTree(t->left, shift + 1);  // ���� ����� ��������
		// ���� ������ ����������:
		for (unsigned i = 0; i < shift; ++i) cout << '\t'; // �������� - �������
		std::cout << t->val << '\n';                       // ���� - ��������
		printTree(t->right, shift + 1); // ���� ������� ��������
	}
}

void traverseTree()
{
	cout << "* ���� ��������� ������ � ���������� ���� ���� �������� *\n\n";
	Tree_t t = new treeNode(1, new treeNode(2, new treeNode(4, nullptr, nullptr), new treeNode(5, nullptr, nullptr)),
		new treeNode(3, nullptr, new treeNode(6, nullptr, nullptr)));
	printTree(t, 0);
	cout << " s = " << sum(t) << '\n';
	cout << " S = " << Sum(t) << '\n';
}
