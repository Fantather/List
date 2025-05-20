#pragma once
#include "SinglyLinkedList.h"

template<typename T>
struct SinglyLinkedList<T>::SinglyLinkedNode
{
public:
	SinglyLinkedNode* next_;	// Pointer on next node
	T data_;					// Stored value

	SinglyLinkedNode(const T& data, SinglyLinkedNode* next_ptr = nullptr) : data_(data), next_(next_ptr) {}
};