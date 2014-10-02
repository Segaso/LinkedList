//  Author: Leonard A. Kelley III
//	Class: CSI 240 - 04
//	Description:
//		The purpose of this list class is to create a doubly-linked list with some iterator support
//		STL doesn't work, but for range based loops do, so thats a benefit I guess. 
//		linked lists are horrid for performance (two pointers per one data point).
//		std::vector will almost always outperform stl::list/this list, so use that.
//
//	Certification of Authenticity:
//	I certify that this assignment is entirely my own work.

#ifndef LIST_H
#define LIST_H

template <class T> class list {
	class iterator;
	class node;
public:
	//Iterator Support
	iterator begin() { return iterator(Head); }
	iterator end() { return iterator(Tail->Next); }

	//Munipulators
	void push_back(const T&);
	void push_front(const T&);

	void pop_back();
	void pop_front();

	void insert(size_t, const T&);
	void remove(size_t);
	void erase();

	//Accessors
	size_t size() const { return Size; }
	bool empty() const { return Head == nullptr; }

	//Constructors/Destructor

	list() : Head(nullptr), Current(Head), Tail(Head), Size(0) 
	{}
	~list() { erase(); }

private:	
	//Private Variables
	node *Head, *Tail, *Current;
	size_t Size;
};

template <class T> class list<T>::node {
public:
	node(const T& val, node* N, node* P) : Value(val), Next(N), Prev(P) {}
	node() : node(0,nullptr, nullptr) {}
	
	T Value;
	node *Next, *Prev;
};

template <class T> class list<T>::iterator {
public:
	//Constructor
	iterator(node* N) : Current(N) {}
	
	//Overloaded Operators
	iterator& operator++() {
		Current = Current->Next;
		return *this;
	}

	node* operator+(int index) {
		for (int i = 0; i < index; i++) {
			Current = Current->Next;
		}
		return Current;
	}

	bool operator!=(iterator& other) const { return Current != other.Current;}

	T& operator * () {return Current->Value; }

private:
	node* Current;
};

#include "list.inl"
#endif