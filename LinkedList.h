#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

template<class T>
class LinkedList
{
private:
	struct node 
	{
		T value;
		node* next;
		node* prev;
	};

	node* Head;
	node* Tail;
	node* Current;

	void GetNode(size_t index);

	size_t size;
	size_t position;
	
public:
	T &operator[](size_t);

	void Add(T);
	void Remove(size_t);

	size_t  Size() {return size;};
	bool Empty(){return (Head == nullptr) ? true : false;};

	LinkedList();
   ~LinkedList();
};

#include "LinkedList.inl"
#endif
