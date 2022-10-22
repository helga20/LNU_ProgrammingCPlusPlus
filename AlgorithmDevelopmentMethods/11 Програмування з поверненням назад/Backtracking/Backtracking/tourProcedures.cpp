#include "Procedures.h"
#include "Tools.h"

// ������� ���������� ���� ������ ����������� �������
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dsize = sizeof dx / sizeof *dx;

bool success;           // ������ ����, �� �������� ����'����

void tryNextMove(int** board, int n, int step, int posX, int posY)
{
	int length = n * n; // ������� ���� �������
	int k = 0;          // �������� �������� ����������
	do
	{
		int u = posX + dx[k];       // �������� ��� ����
		int v = posY + dy[k]; ++k;
		if (0 <= u && u < n && 0 <= v && v < n && board[u][v] == 0)
		{
			board[u][v] = step; //������ ���
			if (step < length)
			{
				tryNextMove(board, n, step + 1, u, v); // ������ �����������
				if (!success) board[u][v] = 0;    // ���������� �� ���� �����
			}
			else success = true;
		}
	} while (!success && k < dsize);
}

void tourByRecursion()
{
	int n;                                // ����� ���������
	cout << "������ ����� ���������: "; cin >> n;
	int** board = buildBoard(n);          // �������� �������� ���������
	int posX, posY;                       // �������� ���������� ����
	cout << "������ ���������� x y ������� ���� (1<=x,y<=" << n << "): ";
	cin >> posY >> posX;
	board[--posX][--posY] = 1;            // ��������� ����
	success = false;                      // ����'���� �� �� �������
	tryNextMove(board, n, 2, posX, posY); // ������� ������ ��� ����
	// ��������� ���������� � ��������� ���'��
	if (success)
	{
		cout << "\n       �������� ��� ����\n---------------------------------\n\n";
		writeBoard(board, n);
	}
	else cout << "\n       ����'���� �� �������\n";
	eraseBoard(board);
}

// ���� ��� � ��� ���� ������ ���������� ������� � �������
// ������������ ��������� �� �����������
struct State
{
	int x, y, k;
	State(int X = 0, int Y = 0, int K = 0) :x(X), y(Y), k(K) {}
};

bool knightTour(int** board, int n, int posX, int posY)
{
	int length = n * n - 1;               // ������� ����
	State* moves = new State[length + 1]; // �������� ����
	int step = 0;                         // ���� �� �� ������
	board[--posX][--posY] = 1;
	State curr(posX, posY, 0);            // ��������� ������������ ����
	moves[step] = curr;                   // � ���� �����
	do
	{
		bool success = false;  // �������� ��������� ����
		int u, v;              // ���������� ��������� ����
		while (curr.k < 8 && !success)
		{                      // ������ ������� �����������
			u = curr.x + dx[curr.k];
			v = curr.y + dy[curr.k];
			success = 0 <= u && u < n && 0 <= v && v < n && board[u][v] == 0;
			++curr.k;
		}
		if (success) 
		{            // ������� �����������
			moves[++step] = curr;      // �����'������� ���
			board[u][v] = step + 1;
			curr = State(u, v, 0);     // ����� ���� �����
		}
		else         // ����������� �� ��� �����
		{
			board[curr.x][curr.y] = 0; // �������� �������
			curr = moves[step--];      // ��������� ����
		}
	} while (step < length && step >= 0);
	delete[] moves;
	return step == length;
}

void solveTour()
{
	int n;                                // ����� ���������
	cout << "������ ����� ���������: "; cin >> n;
	int** board = buildBoard(n);          // �������� �������� ���������
	int posX, posY;                       // �������� ���������� ����
	cout << "������ ���������� x y ������� ���� (1<=x,y<=" << n << "): ";
	cin >> posY >> posX;
	bool success = knightTour(board, n, posX, posY); // ������ ��� ����
	// ��������� ���������� � ��������� ���'��
	if (success)
	{
		cout << "\n       �������� ��� ����\n---------------------------------\n\n";
		writeBoard(board, n);
	}
	else cout << "\n       ����'���� �� �������\n";
	eraseBoard(board);
}
