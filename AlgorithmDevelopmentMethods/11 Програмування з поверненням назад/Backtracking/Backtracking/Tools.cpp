#include "Tools.h"
#include <iostream>
#include <string>

using std::cout;

// ������� �������� ������� nxn � ��������� �� ������
int** buildBoard(int n)
{
	int nqr = n*n;
	int** board = new int*[n];
	*board = new int[nqr];
	for (int i = 0, *curr = *board; i < nqr; ++i, ++curr) *curr = 0;
	for (int i = 1; i < n; ++i) board[i] = board[i - 1] + n;
	return board;
}
// ������� �������� ���'��� �� �������
void eraseBoard(int**& board)
{
	delete[] * board;
	delete[] board;
	board = nullptr;
}
// �������� �� ���� �������-���������; ����� - � ���������� �������,
// ������� ������� ��������� ��������� - � ����� �������� �����
void writeBoard(int** board, int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		cout.width(4); cout << i + 1 << " |";
		for (int j = 0; j < n; ++j)
		{
			cout.width(4); cout << board[j][i];
		}
		cout << '\n';
	}
	cout << "      " << std::string(n * 4 + 1, '-') << "\n      ";
	for (int j = 0; j < n; ++j)
	{
		cout.width(4); cout << char('a' + j);
	}
	cout << '\n';
}

