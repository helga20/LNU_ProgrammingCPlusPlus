#pragma once

typedef int ValueType;

int findValInMas(ValueType x, ValueType a[], int n);

struct Node
{
	ValueType data;
	Node* next;
	Node(ValueType x, Node* ptr = nullptr) :data(x), next(ptr){}
};
Node* fintValInList(ValueType x, Node* head);

ValueType* findValMas(ValueType x, ValueType* a, ValueType* last);
Node* fintValList(ValueType x, Node* head, Node* stop);

class Iter
{
private:
	Node* L;
public:
	Iter(Node* p = nullptr) :L(p){}
	Iter& operator++()
	{
		L = L->next;
		return *this;
	}
	ValueType operator*()
	{
		return L->data;
	}
	bool operator!=(const Iter& it) const
	{
		return this->L != it.L;
	}
};
Iter findVal(ValueType x, Iter head, Iter stop);

template <typename TValueType, typename TIter>
TIter findValInSucc(TValueType x, TIter head, TIter stop)
{
	for (TIter curr = head; curr != stop; ++curr)
		if (*curr == x) return curr;
	return nullptr;
}

template <typename Predicate, typename TIter>
TIter findAnyInSucc(Predicate cond, TIter head, TIter stop)
{
	for (TIter curr = head; curr != stop; ++curr)
		if (cond(*curr)) return curr;
	return nullptr;
}
