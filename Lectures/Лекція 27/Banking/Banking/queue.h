#include <iostream>
using std::ostream;
class Customer
{
private:
	static int counter[3];
	long arrive;
	int processtime;
public:
	Customer() :arrive(0), processtime(0) {}
	static void showCounters();
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
ostream& operator<<(ostream& os, const Customer& customer);

typedef Customer Item;
class Queue
{
	struct Node // �������� ���������� ����
	{
		Item item; 
		Node * next;
		Node(Item val, Node* ptr = nullptr) :item(val), next(ptr) {}
	};
	enum {Q_SIZE = 10};
private:
	Node* front;		// �������� �� ������� �����
	Node* rear;			// �������� �� ����� �����
	int items;			// ������� ������� �����
	const int qsize;	// ����������� ������� �����
	Queue(const Queue& q) : qsize(0) { } // ������������ �����������
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const;	// ��������
	bool isFull() const;	//
	int queueCount() const;	//
	bool enqueue(const Item& item);	// ���������
	bool dequeue(Item& item);		// ���������
	void show() const;
};