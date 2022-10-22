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

	// ������� �����
	queue<int>Queue, newQueue;
	// �������� ����� push()
	for (i = 0; i < size; i++)
	{
		Queue.push(i);
		newQueue.push(i + 1);
	}

	// ����� �����
	int QueueSize = Queue.size();
	cout << "����� �����: " << QueueSize << endl;
	QueueSize = newQueue.size();
	cout << "����� ���� �����: " << QueueSize << endl;

	// ������� �����
	if (Queue == newQueue) cout << "����� == ���� �����\n";
	if (Queue > newQueue) cout << "����� > ���� �����\n";
	if (Queue >= newQueue) cout << "����� >= ���� �����\n";
	if (Queue < newQueue) cout << "����� < ���� �����\n";
	if (Queue <= newQueue) cout << "����� <= ���� �����\n";

	// ������� �� �����
	cout << "�����: \n";
	print(Queue);
	cout << "���� �����: \n";
	print(newQueue);
	return 0;
}
void print(queue<int>& Queue)
{
	if (Queue.empty())
	{
		cout << "\n����� �������\n";	return;
	}
	while (!Queue.empty())
	{
		cout << " " << Queue.front();
		Queue.pop();
	}
	cout << "\n";
}