#include "LargeNumber.h"

// ��������� �������� �������� �����
void multByTwo(largeNumber& x)
{
	char calc;                        // ��������� �������� ���������
	char transfer = 0;                // ����������� �� �������� �������
	for (int i = 0; i <= x.last; ++i) // ����������� �� ����� �������� �����
	{
		calc = x.digits[i] * 2 + transfer;
		x.digits[i] = calc % 10;      // ������� ����� ������� ��������
		transfer = calc / 10;         // ������ - ����������
	}
	if (transfer > 0)                 // ����� ����� ��� ������
		x.digits[++x.last] = transfer;
}

// ��������� ��������� �������� �����
void print(const largeNumber& x)
{
	for (int i = x.last; i >= 0; --i) cout << (int)x.digits[i];
	cout << '\n';
}

// �������� ��������� 2 �� ������� n, 1<=n<=1000
void powerLast()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n (n<=1000): "; cin >> n;
	largeNumber x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x.last = 0;
	x.digits[0] = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		multByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 � ������ " << n << " = ";
	//�����������_������_�����(x);
	print(x);
}

/* ==================================================================================== */

// ��������� ��������� �������� ���'��
void eraseList(NumNode*& x)
{
	while (x != nullptr)
	{
		NumNode* victim = x;
		x = x->link;
		delete victim;
	}
}
// ��������� �������� �������� �����
void multByTwo(NumNode* x)
{
	unsigned short calc;
	unsigned short transfer = 0;
	x = new NumNode(0, x);       // ��������� ����� ������� ��� ����������� �����������
	NumNode* curr = x;
	while (curr->link != nullptr)
	{
		calc = curr->link->num * 2 + transfer;
		if (calc < 10000)
		{                        // �� 4 ����� ���������� � ���� �����
			transfer = 0;
			curr->link->num = calc;
		}
		else
		{                        // � ����������� � �������� �����
			transfer = 1;
			curr->link->num = calc % 10000;
		}
		curr = curr->link;
	}
	// ���� �����, ���� ����� ����� ������
	if (transfer > 0) curr->link = new NumNode(1);
	// ��������� ����� ����� �� ������
	delete x;
}
// ��������� ��������� �������� �����
void print(const NumNode* x)
{
	// ����� ���������� ������ ����� ��������
	NumNode* reverse = nullptr;
	while (x != nullptr)
	{
		reverse = new NumNode(x->num, reverse);
		x = x->link;
	}
	x = reverse;
	cout << x->num; // ���� ������ "�����" ��� ������� ����
	x = x->link;
	char empt = cout.fill('0');
	while (x != nullptr) // ����� "����" ������� �� ������ � � ������
	{
		cout.width(4);
		cout << x->num;
		x = x->link;
	}
	cout << '\n';
	cout.fill(empt); // ��������� ���������� �� �������������
	eraseList(reverse); // ��������� ������ ����� �� �������
}
// �������� ��������� 2 �� ������� n
void powerList()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n: "; cin >> n;
	NumNode* x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x = new NumNode(1);  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		multByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 � ������ " << n << " = ";
	//�����������_������_�����(x);
	print(x);
	eraseList(x);
}

/* ==================================================================================== */

LargePositiveInteger& LargePositiveInteger::operator=(unsigned n)
{
	digits.clear();
	if (n == 0)	digits.push_back(0);
	else
	{
		while (n > 0)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}
	return *this;
}
LargePositiveInteger& LargePositiveInteger::multByTwo()
{
	char calc;
	char transfer = 0;
	for (int i = 0; i < digits.size(); ++i)
	{
		calc = digits[i] * 2 + transfer;
		digits[i] = calc % 10;
		transfer = calc / 10;
	}
	if (transfer > 0) digits.push_back(transfer);
	return *this;
}
LargePositiveInteger& LargePositiveInteger::operator*=(unsigned n)
{
	if (n == 0) return *this = 0;
	unsigned calc;
	unsigned transfer = 0;
	for (int i = 0; i < digits.size(); ++i)
	{
		calc = digits[i] * n + transfer;
		digits[i] = calc % 10;
		transfer = calc / 10;
	}
	while (transfer > 0)
	{
		digits.push_back(transfer % 10);
		transfer /= 10;
	}
	return *this;
}
ostream& operator<<(ostream& os, const LargePositiveInteger& L)
{
	for (int i = L.digits.size() - 1; i >= 0; --i) os << (int)L.digits[i];
	os << '\n';
	return os;
}

void powerLastest()
{
	cout << "* ���������� �������� ������� ����� 2 *\n\n";
	int n;
	cout << "������ n: "; cin >> n;
	LargePositiveInteger x; // ������ ����� �
	// ��������� 2^n � ����� x
	//     ������_�����_x = 1;
	x = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// �������_������_�����(x);
		x *= 2; // x = 2^k
	}
	// x = 2^n
	//�����������_������_�����(x);
	cout << "2 � ������ " << n << " = " << x;
}
