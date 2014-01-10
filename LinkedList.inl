#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
	Current = Head;
	Tail = Head;

	size = 0;
	position = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	node* Temp;
	Current = Head;

	while (Current != nullptr)
	{
		Temp = Current->next;
		delete Current;

		Current = Temp;
	}
	Head = nullptr;
	Tail = nullptr;
	Temp = nullptr;
}

template<class T>
T &LinkedList<T>::operator[](size_t index)
{
	GetNode(index);
	return Current->value;
}

template<class T>
void LinkedList<T>::Add(T input)
{
	if(Head == nullptr)
	{
		Head = new node;
		Head->next = nullptr;
		Head->prev = nullptr;
		Head->value = input;

		Current = Head;
		Tail = Head;
	}
	else
	{
		Current = Tail; //Set Current to Tail Node

		Current->next = new node;
		Current = Current->next;

		Current->next = nullptr;
		Current->prev = Tail; //Set old Tail to previous

		Current->value = input;
		//
		Tail = Current; //Set newest node to tail
	}

	position = size;
	size++;
}

template<class T>
void LinkedList<T>::GetNode(size_t index)
{
	if(index > size)
	{
		throw "Out of Range";
	}
	else if (index == position + 1)
	{
		Current = Current->next;
	}
	else if (index >= position)
	{
		while(position < index && position <= size)
		{
			Current = Current->next;
			position++;
		}
	}
	else
	{
		while(position > index && position >= 0)
		{
			Current = Current->prev;
			position--;
		}
	}
}


template<class T>
void LinkedList<T>::Remove(size_t index)
{
	node* Temp;

	if(index == 0)
	{	
		Temp = Head;
		Head = Temp->next;
		Head->prev  = nullptr;
	}
	else if (index == size - 1)
	{
		Temp = Tail;
		Tail = Temp->prev;
		Tail->next = nullptr;
	}
	else
	{
		GetNode(index);
		
		Temp   = Current;
		node* Temp_1 = Current->prev;
		node* Temp_2 = Current->next;

		Temp_1->next = Temp_2;
		Temp_2->prev = Temp_1;

		Temp_1 = nullptr;
		Temp_2 = nullptr;
	}

	Temp = nullptr;
	size--;
}
