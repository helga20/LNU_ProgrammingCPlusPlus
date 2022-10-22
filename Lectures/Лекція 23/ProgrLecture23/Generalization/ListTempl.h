#pragma once
#include <iostream>

// Лінійний однозв'язний список
template <typename ValueType>
class List
{
private:
	// Ланка списку містить елемент даних і вказівник на наступну ланку
	struct Node
	{
		ValueType data;
		Node* next;
		Node(ValueType x, Node* ptr = nullptr) :data(x), next(ptr){}
	};
	// Голова списку (вказівник на першу ланку)
	Node * Head;
public:
	// Клас ітератора. Ітератор використовують для обходу ланками списку
	class Iter
	{
	private:
		Node* L;
	public:
		Iter() :L(nullptr){}
		Iter(List& lst) :L(lst.Head) {}
		Iter(Node* node) :L(node) {}
		ValueType& operator*()
		{
			return L->data;
		}
		Iter& operator++()
		{
			L = L->next;
			return *this;
		}
		bool operator!=(const Iter& it)
		{
			return this->L != it.L;
		}
	};
	List(ValueType a[], int n)
	{
		this->Head = new Node(a[n - 1]);
		for (int i = n - 2; i >= 0; --i)
		{
			this->Head = new Node(a[i], this->Head);
		}
	}
	~List()
	{
		while (Head != nullptr)
		{
			Node* victim = Head;
			Head = Head->next;
			delete victim;
		}
	}
	// допоміжні методи для отримання ітераторів:
	// ... на початок списку
	Iter begin() const
	{
		return Iter(Head);
	}
	// ... на ланку "наступну після останньої"
	Iter end() const
	{
		return Iter();
	}
};

template <typename Iter>
void PrintSuccession(Iter start, Iter end)
{
	while (start != end)
	{
		cout << '\t' << *start;
		++start;
	}
	cout << '\n';
}

template <typename ValueType, typename Iter>
Iter FindValInSuccession(ValueType x, Iter start, Iter end)
{
	while (start != end && *start != x) ++start;
	return start;
}

template <typename Predic, typename Iter>
Iter FindAnyInSuccession(Predic cond, Iter start, Iter end)
{
	while (start != end && !cond(*start)) ++start;
	return start;
}