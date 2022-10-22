#include <iostream>
#include <algorithm>
#include <queue>
#include <Windows.h>
using namespace std;

void print(queue<int>& Queue);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 5;
	int i;

	// створюю черга
	queue<int>Queue, newQueue;
	// заповнюю черну push()
	for (i = 0; i < size; i++)
	{
		Queue.push(i);
		newQueue.push(i + 1);
	}

	// розмір черги
	int QueueSize = Queue.size();
	cout << "Розмір черги: " << QueueSize << endl;
	QueueSize = newQueue.size();
	cout << "Розмір нової черги: " << QueueSize << endl;

	// порівнюю черги
	if (Queue == newQueue) cout << "Черга == Нова черга\n";
	if (Queue > newQueue) cout << "Черга > Нова черга\n";
	if (Queue >= newQueue) cout << "Черга >= Нова черга\n";
	if (Queue < newQueue) cout << "Черга < Нова черга\n";
	if (Queue <= newQueue) cout << "Черга <= Нова черга\n";

	// виводжу на екран
	cout << "Черга: \n";
	print(Queue);
	cout << "Нова черга: \n";
	print(newQueue);
	return 0;
}
void print(queue<int>& Queue)
{
	if (Queue.empty())
	{
		cout << "\nЧерга порожня\n";	return;
	}
	while (!Queue.empty())
	{
		cout << " " << Queue.front();
		Queue.pop();
	}
	cout << "\n";
}