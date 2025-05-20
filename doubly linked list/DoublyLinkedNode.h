#pragma once
#include "DoublyLinkedList.h"

template<typename T>
struct DoublyLinkedList<T>::DoublyLinkedNode
{
public:
	DoublyLinkedNode* next_;	// Pointer to the next node
	DoublyLinkedNode* back_;	// Pointer to the previous node
	T value_;					// Stored value

	// Constructor with parameters
	DoublyLinkedNode(const T& value, DoublyLinkedNode* next = nullptr, DoublyLinkedNode* back = nullptr) : value_(value), next_(next), back_(back) {}
};