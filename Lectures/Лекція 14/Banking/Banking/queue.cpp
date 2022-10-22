#include "queue.h"
#include <cstdlib>
#include <iostream>
using std::cout;

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}
Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isEmpty() const
{
	return items == 0;
}
bool Queue::isFull() const
{
	return items == qsize;
}
int Queue::queueCount() const
{
	return items;
}
bool Queue::enqueue(const Item &item)
{
	if (isFull())
		return false;
	Node* add = new Node(item);
	if (add == 0)
		return false;
	items++;
	if (front != nullptr)
		rear->next = add;
	else
		front = add;
	rear = add;
	return true;
}
bool Queue::dequeue(Item &item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}
void Queue::show() const
{
	if (items > 0)
	{
		Node* current = front;
		for (int i = 0; i < items; i++)
		{
			cout << "Customer #" << i << ": " << current->item << '\n';
			current = current->next;
		}
	}
	else cout<<"The Queue is empty\n";
}
int Customer::counter[3] = {0};
void Customer::showCounters()
{
	cout<<"Customer reports about instances:\n";
	for (int i = 0; i < 3; i++)
		cout << i + 1 << " process time: " << counter[i] << '\n';
}
void Customer::set(long when)
{
	processtime = rand() % 3 + 1;
	arrive = when;
	counter[processtime-1]++;
}
ostream& operator<<(ostream& os, const Customer& customer)
{
	os << " arrive: "<<customer.when()
		<<" processtime: "<<customer.ptime();
	return os;
}