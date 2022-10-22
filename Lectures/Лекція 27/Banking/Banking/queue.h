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
	struct Node // вкладене оголошення типу
	{
		Item item; 
		Node * next;
		Node(Item val, Node* ptr = nullptr) :item(val), next(ptr) {}
	};
	enum {Q_SIZE = 10};
private:
	Node* front;		// вказівник на початок черги
	Node* rear;			// вказівник на кінець черги
	int items;			// поточна довжина черги
	const int qsize;	// максимальна довжина черги
	Queue(const Queue& q) : qsize(0) { } // заблокований конструктор
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const;	// перевірки
	bool isFull() const;	//
	int queueCount() const;	//
	bool enqueue(const Item& item);	// занесення
	bool dequeue(Item& item);		// вилучення
	void show() const;
};