#include "Procedures.h"
#include "Tools.h"

// правила переміщення коня задано глобальними змінними
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dsize = sizeof dx / sizeof *dx;

bool success;           // ознака того, чи знайдено розв'язок

void tryNextMove(int** board, int n, int step, int posX, int posY)
{
	int length = n * n; // кількість ходів незмінна
	int k = 0;          // лічильник можливих продовжень
	do
	{
		int u = posX + dx[k];       // можливий хід коня
		int v = posY + dy[k]; ++k;
		if (0 <= u && u < n && 0 <= v && v < n && board[u][v] == 0)
		{
			board[u][v] = step; //робимо хід
			if (step < length)
			{
				tryNextMove(board, n, step + 1, u, v); // шукаємо продовження
				if (!success) board[u][v] = 0;    // повернення на крок назад
			}
			else success = true;
		}
	} while (!success && k < dsize);
}

void tourByRecursion()
{
	int n;                                // розмір шахівниці
	cout << "Введіть розмір шахівниці: "; cin >> n;
	int** board = buildBoard(n);          // побудова порожньої шахівниці
	int posX, posY;                       // початкові координати коня
	cout << "Введіть координати x y першого поля (1<=x,y<=" << n << "): ";
	cin >> posY >> posX;
	board[--posX][--posY] = 1;            // поставили коня
	success = false;                      // розв'язку ще не знайшли
	tryNextMove(board, n, 2, posX, posY); // пробуємо знайти тур коня
	// виведення результатів і звільнення пам'яті
	if (success)
	{
		cout << "\n       Знайдено тур коня\n---------------------------------\n\n";
		writeBoard(board, n);
	}
	else cout << "\n       Розв'язку не знайшли\n";
	eraseBoard(board);
}

// Один хід у турі коня містить координати клітинки і кількість
// випробуваних кандидатів на продовження
struct State
{
	int x, y, k;
	State(int X = 0, int Y = 0, int K = 0) :x(X), y(Y), k(K) {}
};

bool knightTour(int** board, int n, int posX, int posY)
{
	int length = n * n - 1;               // кількість ходів
	State* moves = new State[length + 1]; // внутрішній стек
	int step = 0;                         // ходів ще не робили
	board[--posX][--posY] = 1;
	State curr(posX, posY, 0);            // початкове розташування коня
	moves[step] = curr;                   // і стан дошки
	do
	{
		bool success = false;  // успішність чергового ходу
		int u, v;              // координати чергового ходу
		while (curr.k < 8 && !success)
		{                      // шукаємо можливе продовження
			u = curr.x + dx[curr.k];
			v = curr.y + dy[curr.k];
			success = 0 <= u && u < n && 0 <= v && v < n && board[u][v] == 0;
			++curr.k;
		}
		if (success) 
		{            // знайшли продовження
			moves[++step] = curr;      // запам'ятовуємо хід
			board[u][v] = step + 1;
			curr = State(u, v, 0);     // новий стан дошки
		}
		else         // повертаємося на хід назад
		{
			board[curr.x][curr.y] = 0; // звільнили клітинку
			curr = moves[step--];      // повернули стан
		}
	} while (step < length && step >= 0);
	delete[] moves;
	return step == length;
}

void solveTour()
{
	int n;                                // розмір шахівниці
	cout << "Введіть розмір шахівниці: "; cin >> n;
	int** board = buildBoard(n);          // побудова порожньої шахівниці
	int posX, posY;                       // початкові координати коня
	cout << "Введіть координати x y першого поля (1<=x,y<=" << n << "): ";
	cin >> posY >> posX;
	bool success = knightTour(board, n, posX, posY); // шукаємо тур коня
	// виведення результатів і звільнення пам'яті
	if (success)
	{
		cout << "\n       Знайдено тур коня\n---------------------------------\n\n";
		writeBoard(board, n);
	}
	else cout << "\n       Розв'язку не знайшли\n";
	eraseBoard(board);
}
