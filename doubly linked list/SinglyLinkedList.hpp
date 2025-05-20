#pragma once
#include "SinglyLinkedList.h"
#include "SinglyLinkedNode.h"

/*==== Helper methods ====*/
// Checks the index for inserting
// Throws std::out_of_range if index is negative or ≥ size_
template<typename T>
inline size_t SinglyLinkedList<T>::valid_index_(ptrdiff_t index, IndexMode mode)
{
	if (index < 0)
	{
		throw std::out_of_range("SinglyLinkedList::Push_by_index - index less than 0");
	}

	size_t new_index = static_cast<size_t>(index);

	if ((mode == IndexMode::Insert && new_index > size_) ||
		(mode == IndexMode::Remove && new_index >= size_)) {
		throw std::out_of_range("SinglyLinkedList::valid_index_ - index out of range");
	}

	return new_index;
}


/*==== Constructors and Destructor ====*/

// Default
// Default pointers nullptr, list size 0
template<typename T>
inline SinglyLinkedList<T>::SinglyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

// With parameters
template<typename T>
inline SinglyLinkedList<T>::SinglyLinkedList(const T& data) : head_(new SinglyLinkedNode(data)), tail_(head_), size_(1) {}

// Destructor
template<typename T>
inline SinglyLinkedList<T>::~SinglyLinkedList()
{
	DeleteAll();
}


/*==== Methods ====*/

// Add Node to start of the list
template<typename T>
inline void SinglyLinkedList<T>::push_front(const T& value)
{
	head_ = new SinglyLinkedNode(value, head_);
	++size_;

	if (!tail_)
	{
		tail_ = head_;
	}
}

// Add value to end of the list
template<typename T>
inline void SinglyLinkedList<T>::push_tail(const T& value)
{
	SinglyLinkedNode* new_node = new SinglyLinkedNode(value);
	
	// If list was empty
	if (!head_)
	{
		head_ = tail_ = new_node;
	}

	else
	{
		tail_->next_ = new_node;
		tail_ = new_node;
	}

	++size_;
}

// Add value to list by index
// Throws std::out_of_range if index is out of range.
template<typename T>
inline void SinglyLinkedList<T>::push_by_index(const T& value, const ptrdiff_t index)
{
	size_t new_index = valid_index_(index, IndexMode::Insert);

	if (new_index == 0)
	{
		push_front(value);
		return;
	}

	if (new_index == size_)
	{
		push_tail(value);
		return;
	}

	SinglyLinkedNode* temp = head_;

	for (size_t i = 0; i < new_index - 1; i++)
	{
		temp = temp->next_;
	}

	SinglyLinkedNode* new_node = new SinglyLinkedNode(value, temp->next_);
	temp->next_ = new_node;
	++size_;
}

// Delete from start of the list
template<typename T>
inline void SinglyLinkedList<T>::pop_front()
{
	// Empty list
	if (!head_)
		return;

	SinglyLinkedNode* temp = head_;
	head_ = head_->next_;				// Assigned to nullptr if there are no values
	delete temp;

	// If list empty
	if (!head_)
	{
		tail_ = nullptr;
	}

	--size_;
}

// Delete from end of the list
template<typename T>
inline void SinglyLinkedList<T>::pop_tail()
{
	// Empty list
	if (!tail_)
		return;

	// List with one element
	if (head_ == tail_)
	{
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
		return;
	}

	// Finding the penultimate node
	SinglyLinkedNode* temp = head_;
	while (temp->next_ != tail_)
	{
		temp = temp->next_;
	}

	// Delete last element
	delete tail_;
	tail_ = temp;
	tail_->next_ = nullptr;
	--size_;
}

// Removes the element at the given index.
// - If index is 0, removes the first element.
// - If index is size_ - 1, removes the last element.
// - Otherwise, removes the middle element.
// Throws std::out_of_range if index is out of range.
template<typename T>
inline void SinglyLinkedList<T>::pop_by_index(const ptrdiff_t index)
{
	size_t new_index = valid_index_(index, IndexMode::Remove);

	if (new_index == 0)
	{
		pop_front();
		return;
	}

	if (new_index == size_ - 1)
	{
		pop_tail();
		return;
	}

	SinglyLinkedNode* current = head_;

	for (size_t i = 0; i < new_index - 1; i++)
	{
		current = current->next_;
	}

	SinglyLinkedNode* temp = current->next_;
	current->next_ = temp->next_;
	delete temp;
	--size_;
}

// Delete all elements of the list
template<typename T>
inline void SinglyLinkedList<T>::DeleteAll()
{
	while (head_)
	{
		pop_front();
	}
}


/*==== Search method ====*/

// Searches for the first occurrence of the given value.
// Returns the index if found; otherwise returns const NULL_ (not found).
template<typename T>
inline size_t SinglyLinkedList<T>::Search(const T& value)
{
	SinglyLinkedNode* temp = head_;
	for (size_t i = 0; i < size_; ++i)
	{
		if (temp->data_ == value)
		{
			return i;
		}

		temp = temp->next_;
	}

	return NULL_;	// Not found
}


/*==== Replace method ====*/

// Replaces all matching values in the list with a new value
// Returns the number of replacements performed
template<typename T>
inline int SinglyLinkedList<T>::Replacement(const T& replaced_value, const T& new_value)
{
	SinglyLinkedNode* temp = head_;
	int counter = 0;

	for (size_t i = 0; i < size_; i++)
	{
		if (replaced_value == temp->data_)
		{
			temp->data_ = new_value;
			++counter;
		}

		temp = temp->next_;
	}

	return counter > 0 ? counter : -1;
}


/*==== Print ====*/

// Print list
template<typename T>
inline void SinglyLinkedList<T>::show()
{
	if (!head_)
		return;

	SinglyLinkedNode* temp = head_;
	while (temp)
	{
		std::cout << temp->data_ << ' ';
		temp = temp->next_;
	}
}


/*==== Reverse ====*/

// Turning out the list elements
// Redirects links inside the nodes in the other direction, and then assigns the last knot in Head, making it the first
template<typename T>
inline void SinglyLinkedList<T>::Reverse()
{
	SinglyLinkedNode* current = head_;
	SinglyLinkedNode* previous = nullptr;
	SinglyLinkedNode* next = nullptr;

	while (head_)
	{
		next = current->next_;
		current->next_ = previous;
		previous = current;
		current = next;
	}

	head_ = previous;
}





/*==== Other methods ====*/

// Return true if head_ != nullptr
template<typename T>
inline bool SinglyLinkedList<T>::empty() const
{
	return head_ == nullptr;
}
