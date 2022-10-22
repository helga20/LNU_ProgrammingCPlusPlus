#pragma once
#include <iostream>
#include <iterator>

template <typename T>
class DblList
{
public:
	template <typename T>
	struct Node
	{
		T data;
		Node *prev, *next;
		Node(T x, Node* p = nullptr, Node* n = nullptr) :data(x), prev(p), next(n) {}
	};
private:
	Node<T> * top;
	Node<T> * bottom;
	size_t stored;

	mutable Node<T> * curr;
	mutable size_t index;

	void checkIndex(size_t i) const
	{
		if (i >= stored) throw std::range_error("Bad index");
	}
	void moveCurr(size_t i) const
	{
		while (i > index)
		{
			curr = curr->next;
			++index;
		}
		while (i < index)
		{
			curr = curr->prev;
			--index;
		}
	}

public:
	typedef T ValueType;
	class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		Node<T>* ptr;
	public:
		Iterator(Node<T>* p) :ptr(p) {}
		T& operator*() { return ptr->data; }
		bool operator==(const Iterator& it) const { return ptr == it.ptr; }
		bool operator!=(const Iterator& it) const { return ptr != it.ptr; }
		Iterator& operator++() { ptr = ptr->next; return *this; }
		Iterator operator++(int) { Node<T>* old = ptr; ptr = ptr->next; return Iterator(old); }
		Iterator& operator--() { ptr = ptr->prev; return *this; }
		Iterator operator--(int) { Node<T>* old = ptr; ptr = ptr->prev; return Iterator(old); }
	};
	DblList() :top(nullptr), bottom(nullptr), stored(0), curr(nullptr), index(0) {}
	explicit DblList(size_t n, T x = T()) :stored(n), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node<T>(x);
			for (size_t i = 1; i < n; ++i)
			{
				bottom->next = new Node<T>(x, bottom);
				bottom = bottom->next;
			}
		}
	}
	DblList(T* a, size_t n) :stored(n), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node<T>(a[0]);
			for (size_t i = 1; i < n; ++i)
			{
				bottom->next = new Node<T>(a[i], bottom);
				bottom = bottom->next;
			}
		}
	}
	DblList(const DblList& L) :stored(L.stored), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node<T>(L.top->data);
			Node<T>* ptr = L.top->next;
			for (size_t i = 1; i < stored; ++i)
			{
				bottom->next = new Node<T>(ptr->data, bottom);
				bottom = bottom->next;
				ptr = ptr->next;
			}
			moveCurr(L.index);
		}
	}
	~DblList()
	{
		while (top != nullptr)
		{
			Node<T>* victim = top;
			top = top->next;
			delete victim;
		}
	}
	DblList& operator=(const DblList& L)
	{
		if (this != &L)
		{
			this->clear();
			if (L.stored != 0)
			{
				top = bottom = curr = new Node<T>(L.top->data);
				Node<T>* ptr = L.top->next;
				while (ptr != nullptr)
				{
					bottom->next = new Node<T>(ptr->data, bottom);
					bottom = bottom->next;
					ptr = ptr->next;
				}
				stored = L.stored;
				moveCurr(L.index);
			}
		}
		return *this;
	}
	DblList& clear()
	{
		while (top != nullptr)
		{
			Node<T>* victim = top;
			top = top->next;
			delete victim;
		}
		bottom = curr = nullptr;
		index = stored = 0;
		return *this;
	}
	void resize(size_t n)
	{
		while (stored > n) getLast();
	}
	size_t size() const
	{
		return stored;
	}
	T& operator[](size_t i)
	{
		checkIndex(i);
		moveCurr(i);
		return curr->data;
	}
	const T& operator[](size_t i) const
	{
		checkIndex(i);
		moveCurr(i);
		return curr->data;
	}
	DblList& putLast(const T& x)
	{
		if (top == nullptr)
		{
			top = bottom = curr = new Node<T>(x);
		}
		else
		{
			bottom->next = new Node<T>(x, bottom);
			bottom = bottom->next;
		}
		++stored;
		return *this;
	}
	DblList& putFirst(const T& x)
	{
		if (top == nullptr)
		{
			top = bottom = curr = new Node<T>(x);
		}
		else
		{
			top = new Node<T>(x, nullptr, top);
			++index;
		}
		++stored;
		return *this;
	}
	DblList& put(const T& x, size_t i)
	{
		checkIndex(i);
		if (i == 0) putFirst(x);
		else
		{
			moveCurr(i);
			Node<T>* newNode = new Node<T>(x, curr->prev, curr);
			curr->prev->next = newNode;
			curr->prev = newNode;
			curr = newNode;
			++stored;
		}
		return *this;
	}
	T getLast()
	{
		if (stored == 0) throw std::range_error("Empty list");
		T x = bottom->data;
		if (top == bottom)
		{
			delete bottom;
			top = bottom = curr = nullptr;
		}
		else
		{
			if (curr == bottom)
			{
				curr = bottom->prev;
				--index;
				delete bottom;
				bottom = curr;
				bottom->next = nullptr;
			}
			else
			{
				bottom = bottom->prev;
				delete bottom->next;
				bottom->next = nullptr;
			}
		}
		--stored;
		return x;
	}
	T getFirst()
	{
		if (stored == 0) throw std::range_error("Empty list");
		T x = top->data;
		if (top == bottom)
		{
			delete top;
			top = bottom = curr = nullptr;
		}
		else
		{
			if (curr == top)
			{
				curr = top->next;
				delete top;
				top = curr;
				top->prev = nullptr;
			}
			else
			{
				top = top->next;
				delete top->prev;
				top->prev = nullptr;
				--index;
			}
		}
		--stored;
		return x;
	}
	T get(size_t i)
	{
		checkIndex(i);
		if (i == 0) return getFirst();
		else if (i == stored - 1) return getLast();
		else
		{
			moveCurr(i);
			Node<T> * victim = curr;
			T x = curr->data;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr = curr->next;
			delete victim;
			--stored;
			return x;
		}
	}
	T& front()
	{
		if (stored == 0) throw std::range_error("Empty List");
		else return top->data;
	}
	T& back()
	{
		if (stored == 0) throw std::range_error("Empty List");
		else return bottom->data;
	}

	void showOn(std::ostream& os) const
	{
		if (stored == 0)
		{
			os << "<Empty List>\n";
		}
		else
		{
			Node<T> * ptr = top;
			while (ptr != nullptr)
			{
				os << '\t' << ptr->data;
				ptr = ptr->next;
			}
			os << '\n';
		}
	}
	Iterator begin() const { return Iterator(top); }
	Iterator end() const { return Iterator(nullptr); }
	// данина сумісності з STL
	typedef T value_type;
	void push_back(const T& x) { putLast(x); }
	void push_front(const T& x) { putFirst(x); }
};

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node *prev, *next;
		Node(T x, Node* p = nullptr, Node* n = nullptr) :data(x), prev(p), next(n) {}
	};
private:
	Node * top;
	Node * bottom;
	size_t stored;

	mutable Node * curr;
	mutable size_t index;

	void checkIndex(size_t i) const
	{
		if (i >= stored) throw std::range_error("Bad index");
	}
	void moveCurr(size_t i) const
	{
		while (i > index)
		{
			curr = curr->next;
			++index;
		}
		while (i < index)
		{
			curr = curr->prev;
			--index;
		}
	}

public:
	typedef T ValueType;
	class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	private:
		Node* ptr;
	public:
		Iterator(Node* p) :ptr(p) {}
		T& operator*() { return ptr->data; }
		bool operator==(const Iterator& it) const { return ptr == it.ptr; }
		bool operator!=(const Iterator& it) const { return ptr != it.ptr; }
		Iterator& operator++() { ptr = ptr->next; return *this; }
		Iterator operator++(int) { Node* old = ptr; ptr = ptr->next; return Iterator(old); }
		Iterator& operator--() { ptr = ptr->prev; return *this; }
		Iterator operator--(int) { Node* old = ptr; ptr = ptr->prev; return Iterator(old); }
	};
	LinkedList() :top(nullptr), bottom(nullptr), stored(0), curr(nullptr), index(0) {}
	explicit LinkedList(size_t n, T x = T()) :stored(n), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node(x);
			for (size_t i = 1; i < n; ++i)
			{
				bottom->next = new Node(x, bottom);
				bottom = bottom->next;
			}
		}
	}
	LinkedList(T* a, size_t n) :stored(n), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node(a[0]);
			for (size_t i = 1; i < n; ++i)
			{
				bottom->next = new Node(a[i], bottom);
				bottom = bottom->next;
			}
		}
	}
	LinkedList(const LinkedList& L) :stored(L.stored), index(0)
	{
		if (stored == 0)
		{
			top = bottom = curr = nullptr;
		}
		else
		{
			top = bottom = curr = new Node(L.top->data);
			Node* ptr = L.top->next;
			for (size_t i = 1; i < stored; ++i)
			{
				bottom->next = new Node(ptr->data, bottom);
				bottom = bottom->next;
				ptr = ptr->next;
			}
			moveCurr(L.index);
		}
	}
	~LinkedList()
	{
		while (top != nullptr)
		{
			Node* victim = top;
			top = top->next;
			delete victim;
		}
	}
	LinkedList& operator=(const LinkedList& L)
	{
		if (this != &L)
		{
			this->clear();
			if (L.stored != 0)
			{
				top = bottom = curr = new Node(L.top->data);
				Node* ptr = L.top->next;
				while (ptr != nullptr)
				{
					bottom->next = new Node(ptr->data, bottom);
					bottom = bottom->next;
					ptr = ptr->next;
				}
				stored = L.stored;
				moveCurr(L.index);
			}
		}
		return *this;
	}
	LinkedList& clear()
	{
		while (top != nullptr)
		{
			Node* victim = top;
			top = top->next;
			delete victim;
		}
		bottom = curr = nullptr;
		index = stored = 0;
		return *this;
	}
	void resize(size_t n)
	{
		while (stored > n) getLast();
	}
	size_t size() const
	{
		return stored;
	}
	T& operator[](size_t i)
	{
		checkIndex(i);
		moveCurr(i);
		return curr->data;
	}
	const T& operator[](size_t i) const
	{
		checkIndex(i);
		moveCurr(i);
		return curr->data;
	}
	LinkedList& putLast(T x)
	{
		if (top == nullptr)
		{
			top = bottom = curr = new Node(x);
		}
		else
		{
			bottom->next = new Node(x, bottom);
			bottom = bottom->next;
		}
		++stored;
		return *this;
	}
	LinkedList& putFirst(T x)
	{
		if (top == nullptr)
		{
			top = bottom = curr = new Node<T>(x);
		}
		else
		{
			top = new Node<T>(x, nullptr, top);
			++index;
		}
		++stored;
		return *this;
	}
	LinkedList& put(T x, size_t i)
	{
		checkIndex(i);
		if (i == 0) putFirst(x);
		else
		{
			moveCurr(i);
			Node<T>* newNode = new Node<T>(x, curr->prev, curr);
			curr->prev->next = newNode;
			curr->prev = newNode;
			curr = newNode;
			++stored;
		}
		return *this;
	}
	T getLast()
	{
		if (stored == 0) throw std::range_error("Empty list");
		T x = bottom->data;
		if (top == bottom)
		{
			delete bottom;
			top = bottom = curr = nullptr;
		}
		else
		{
			if (curr == bottom)
			{
				curr = bottom->prev;
				--index;
				delete bottom;
				bottom = curr;
				bottom->next = nullptr;
			}
			else
			{
				bottom = bottom->prev;
				delete bottom->next;
				bottom->next = nullptr;
			}
		}
		--stored;
		return x;
	}
	T getFirst()
	{
		if (stored == 0) throw std::range_error("Empty list");
		T x = top->data;
		if (top == bottom)
		{
			delete top;
			top = bottom = curr = nullptr;
		}
		else
		{
			if (curr == top)
			{
				curr = top->next;
				delete top;
				top = curr;
				top->prev = nullptr;
			}
			else
			{
				top = top->next;
				delete top->prev;
				top->prev = nullptr;
				--index;
			}
		}
		--stored;
		return x;
	}
	T get(size_t i)
	{
		checkIndex(i);
		if (i == 0) return getFirst();
		else if (i == stored - 1) return getLast();
		else
		{
			moveCurr(i);
			Node * victim = curr;
			T x = curr->data;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr = curr->next;
			delete victim;
			--stored;
			return x;
		}
	}
	T& front()
	{
		if (stored == 0) throw std::range_error("Empty List");
		else return top->data;
	}
	T& back()
	{
		if (stored == 0) throw std::range_error("Empty List");
		else return bottom->data;
	}

	void showOn(std::ostream& os) const
	{
		if (stored == 0)
		{
			os << "<Empty List>\n";
		}
		else
		{
			Node * ptr = top;
			while (ptr != nullptr)
			{
				os << '\t' << ptr->data;
				ptr = ptr->next;
			}
			os << '\n';
		}
	}
	Iterator begin() const { return Iterator(top); }
	Iterator end() const { return Iterator(nullptr); }

	typedef T value_type;
	void push_back(T x) { putLast(x); }
	void push_front(T x) { putFirst(x); }
};