#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
	Current = Head;
	Tail = Head;

	size = 0;
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
		Head->index = 0;

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
		Current->index = size;
		
		//
		Tail = Current; //Set newest node to tail
	}

	size++;
}

template<class T>
void LinkedList<T>::GetNode(size_t index)
{
	if(index > size)
	{
		throw "Out of Range";
	}
	else if (index == Current->index + 1)
	{
		Current = Current->next;
	}
	else if (index >= Current->index)
	{
		for(size_t i = Current->index; i < index && i <= size; i++)
		{
			Current = Current->next;
		}
	}
	else
	{
		for(size_t i = Current->index; i > index && i >= 0; i--)
		{
			Current = Current->prev;
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
		if(Head->index != 1)
		Head->index--;
	}
	else if (index == size - 1)
	{
		Temp = Tail;
		Tail = Temp->prev;

		if(Tail->index != 1)
		Tail->index--;
	}
	else
	{
		GetNode(index);
			  Temp   = Current;
		node* Temp_1 = Current->prev;
		node* Temp_2 = Current->next;

		Temp_1->next = Temp_2;
		Temp_2->prev = Temp_1;

		if(Temp_1->index != 0)
		{
			Temp_1->index--;
		}
		while(Temp_2 != 0)
		{
			Temp_2->index--;
			Temp_2 = Temp_2->next;
		}

		Temp_1 = nullptr;
		Temp_2 = nullptr;
	}

	Temp = nullptr;
	size--;
}