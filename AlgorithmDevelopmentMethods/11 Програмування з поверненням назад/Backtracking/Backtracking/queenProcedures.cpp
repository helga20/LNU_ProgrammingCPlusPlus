#include "Tools.h"
#include "Procedures.h"

struct cell
{
	char x; int y;
	cell(char a = 'a', int b = 1) :x(a), y(b) {}
};
std::ostream& operator<<(std::ostream& os, const cell& c)
{
	os << c.x << c.y; return os;
}

// ��������, �� ������� k-�� �������� ���������
bool safe(cell* queens, int k)
{
	for (int i = k - 1; i >= 0; --i)      // ���'�����, �� �������� ���, ����
		if (queens[i].y == queens[k].y || // ��������� ���������� ��
			queens[i].x - queens[i].y == queens[k].x - queens[k].y || // �������
			queens[i].x + queens[i].y == queens[k].x + queens[k].y) return false;
	return true;
}

// ���� �������� ������������ n �����
bool tryPutQueen(cell* queens, int n, int k)
{
	// k-�� ������ ������ ��� � ���� ���������
	queens[k].x = 'a' + k;
	queens[k].y = 0;      // ����������� ������������ (� n �����)
	bool success = false;
	do
	{	++queens[k].y;    // ������� �����������
		if (safe(queens, k))
		{   // ������������ k-� ������ - ��������
			if (k + 1 == n) success = true; // ������� ����'����
			else                            // ������ �����������
				success = tryPutQueen(queens, n, k + 1);
		}
	} while (!success && queens[k].y < n);
	return success;
}

void putQueens()
{
	int n;                                // ����� ���������
	cout << "������ ����� ���������: "; cin >> n;
	cell * queens = new cell[n];          // ������� ���'����
	bool success = tryPutQueen(queens, n, 0);
	// ��������� ���������� � ��������� ���'��
	if (success)
	{
		int**board = buildBoard(n);       // ������� �������� ��������� ���������
		cout << "\n       �������� ������������\n---------------------------------\n\n      ";
		for (int i = 0; i < n; ++i)
		{
			cout << "  " << queens[i];    // ������� �������� ������������
			// � "������������" ������ �� ���������:
			// ������� ������� ������ 0, ������� � ������ - 13
			board[queens[i].x - 'a'][queens[i].y - 1] = 13;
		}
		cout << "\n\n";
		writeBoard(board, n);             // ���� ���������
		eraseBoard(board);
	}
	else cout << "\n       ����'���� �� �������\n";
	delete[] queens;
}