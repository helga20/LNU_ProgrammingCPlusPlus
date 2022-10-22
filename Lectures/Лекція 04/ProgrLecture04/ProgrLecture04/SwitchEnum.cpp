#include <iostream>
using namespace std;

int main()
{
	enum Direction {Up, Right, Down, Left};
	Direction dir = Up;
	// Перелік можна перетворювати на ціле
	cout << "Direction as integer: " << dir << endl;
	// Його зручно використати в операторі варіанту
	switch (dir)
	{
	case Up: cout << "The UP direction"; break;
	case Right: cout << "The RIGHT direction"; break;
	case Down: cout << "The DOWN direction"; break;
	case Left: cout << "The LEFT direction"; break;
	default: cout << "Unknown direction";
	}
	cout << endl;
	// ЗАВДАННЯ: змінити напрям за годинниковою стрілкою задану кількість разів
	int n;
	cout << "\nInput an integer: ";
	cin >> n;
	cout << " Let's change direction " << n << " times\n";
	// Для розв'язання змінимо напрям на наступний n раз
	Direction newDir = dir;
	for (int i = 0; i < n; ++i)
	{
		switch (newDir)
		{
		case Up: newDir = Right; break;
		case Right: newDir = Down; break;
		case Down: newDir = Left; break;
		case Left: newDir = Up; break;
		}
	}
	cout << "\nAfter changes:\n";
	switch (newDir)
	{
	case Up: cout << "The UP direction"; break;
	case Right: cout << "The RIGHT direction"; break;
	case Down: cout << "The DOWN direction"; break;
	case Left: cout << "The LEFT direction"; break;
	default: cout << "Unknown direction";
	}
	cout << endl;
	// Альтернативний спосіб розв'язування - обчислити порядковий номер нового напрямку
	// і примусово перетворити ціле на значення з переліку
	newDir = Direction((n + dir) % 4);
	cout << "\nAfter calculations:\n";
	switch (newDir)
	{
	case Up: cout << "The UP direction"; break;
	case Right: cout << "The RIGHT direction"; break;
	case Down: cout << "The DOWN direction"; break;
	case Left: cout << "The LEFT direction"; break;
	default: cout << "Unknown direction";
	}
	cout << endl;
	system("pause");
	// Значення констант можна задавати явно
	enum { Null, Zero = 0, Uno, One = 1 };
	cout << Null << ' ' << Zero << ' ' << Uno << ' ' << One << endl;
	system("pause");
	return 0;
}