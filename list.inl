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

#include "list.h"

template <class T> void list<T>::push_back(const T& val) {
	if (Head == nullptr) {
		Head = new node(val, nullptr, nullptr);
		Tail = Head;
	} 
	else {
		Tail->Next = new node(val, nullptr, Tail);
		Tail = Tail->Next;
	}
	Size++;
}

template <class T> void list<T>::push_front(const T& val) {
	if (Head == nullptr) {
		Head = new node(val, nullptr, nullptr);
		Tail = Head;
	}
	else {
		Head->Prev = new node(val, Head, nullptr);
		Head = Head->Prev;
	}
	Size++;
}

template <class T> void list<T>::pop_back() {
	if (Head == nullptr) {
		throw std::length_error("List<T> is not Initilized.");
	}
	else {
		Current = Tail->Prev;
		delete Tail;

		Tail = Current;
		Tail->Next = nullptr;
	}
	Size--;
}

template <class T> void list<T>::pop_front() {
	if (Head == nullptr) {
		throw std::length_error("List is not Initilized.");
	}
	else {
		Current = Head->Next;
		delete Head;

		Head = Current;
		Head->Prev = nullptr;
	}
	Size--;
}

template <class T> void list<T>::remove(size_t index) {
	if (index > size() || index < 0) {
		throw std::out_of_range("index out of range");
	} 
	else if (index == 0) { 
		pop_front();
	}
	else if (index == size()) {
		pop_back();
	}
	else {
		Current = begin() + index;
		Current->Prev->Next = Current->Next;
		Current->Next->Prev = Current->Prev;
		delete Current;
	}
	Size--;
}

template <class T> void list<T>::insert(size_t index, const T& val) {
	if (index > size() || index < 0) {
		throw std::out_of_range("index out of range");
	}
	else if (index == 0) {
		push_front(val);
	}
	else if (index == size()) {
		push_back(val);
	}
	else {
		Current = begin() + index;
		Current->Prev->Next = new node(val, Current, Current->Prev);
		Current->Prev = Current->Prev->Next;
	}
	Size++;
}

template <class T> void list<T>::erase() {
	if (!empty()) {
		Current = Head;
		while (Current != nullptr) {
			delete 	Current->Prev;
			Current->Prev = nullptr;

			Current = Current->Next;
		}
		Head = Tail = Current = nullptr;
		Size = 0;
	}
}