#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList
{
private:
	struct node 
	{
		T value;
		node* next;
		node* prev;
		size_t index;
	};

	node* Head;
	node* Tail;
	node* Current;

	void GetNode(size_t index);

	size_t size;
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
