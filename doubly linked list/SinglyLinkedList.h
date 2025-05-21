#pragma once
#include <iostream>


template<typename T>
class SinglyLinkedList
{
private:
	struct SinglyLinkedNode;		// Node struct for a list

	SinglyLinkedNode* head_;		// Pointer to the first element
	SinglyLinkedNode* tail_;		// Pointer to the last element
	size_t size_;					// List size

	// Specifies the type of index operation:
	// - Insert: used when adding elements (index can be equal to size_)
	// - Remove: used when removing elements (index must be less than size_)
	enum class IndexMode{Insert, Remove};

	// Helper methods
	size_t valid_index_(ptrdiff_t index, IndexMode mode);	// Validate your index

public:

	static const size_t NULL_ = static_cast<size_t>(-1);	// Meaning for incorrect index

	// Constructors and destructor
	SinglyLinkedList();						// Default
	SinglyLinkedList(const T& data);		// With parameters
	~SinglyLinkedList();					// Destructor

	// Getter
	size_t size() const { return size_; }

	// Add elements
	void push_front(const T& value);								// Add value to start of the list
	void push_tail(const T& value);									// Add value to end of the list
	void push_by_index(const T& value, const ptrdiff_t index);		// Add value to list by index

	// Delete elements
	void pop_front();									// Delete from start of the list
	void pop_tail();									// Delete from end of the list
	void pop_by_index(const ptrdiff_t index);			// Delete element by index
	void DeleteAll();									// Delete all elements of the list

	// Search
	size_t Search(const T& value);						// Search by meaning

	// Replace
	int Replacement(const T& replaced_value, const T& new_value);	// Replaces all matching values in the list with a new value

	// Print
	void show();					// Print list

	// Reverse
	void Reverse();					// Unfolds elements of the list in the opposite direction

	// Other methods
	bool empty() const;				// Return true if head_ == nullptr
	
};


#include "SinglyLinkedList.hpp"