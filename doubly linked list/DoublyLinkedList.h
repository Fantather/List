#pragma once
#include <iostream>
#include <optional>

template <typename T>
class DoublyLinkedList
{
private:
	struct DoublyLinkedNode;			// Announcement node of the list
	DoublyLinkedNode* head_;			// Pointer to the first node of the list
	DoublyLinkedNode* tail_;			// Pointer to the last node of the list
	size_t size_;						// Number of nodes in the list

public:

	// Constructors
	DoublyLinkedList();					// Empty list
	DoublyLinkedList(const T& value);	// Initialize with one node
	~DoublyLinkedList();				// Destructor

	// Add
	void AddToHead(const T& value);		// Add a new node to the head of list
	void AddToTail(const T& value);		// Add a new node to the end of list

	// Delete
	void DeleteFromHead();				// Removes the node from the start of the list
	void DeleteFromTail();				// Removes the node from the end of the list
	void DeleteAll();					// Remove all nodes

	// Print
	void Show();						// Print all nodes

	// Search
	std::optional<size_t> Search(const T& target_value);		// Looking for a node by meaning

	// Replace
	int Replace(const T& target_value, const T& new_value);		// Replaces all matching values ​​in the list with a new value

	// Reverse
	void Reverse();						// Unfolds the list in the opposite direction
};



//-------------------------------------------------------------------
/*========================== Definitions ==========================*/
//-------------------------------------------------------------------


// Constructors and Destructor
template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const T& value) : head_(new DoublyLinkedNode(value)), tail_(head_), size_(1) {}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	DeleteAll();
}


/*==== Add ====*/

// Add a new node to the head of list
template<typename T>
inline void DoublyLinkedList<T>::AddToHead(const T& value)
{
	DoublyLinkedNode* new_head = new DoublyLinkedNode(value, head_, nullptr);

	// If list empty
	if (!head_)
	{
		head_ = tail_ = new_head;
	}

	else
	{
		head_->back_ = new_head;
		head_ = new_head;
	}

	++size;
}

// Add a new node to the end of list
template<typename T>
inline void DoublyLinkedList<T>::AddToTail(const T& value)
{
	DoublyLinkedNode* new_tail = new DoublyLinkedNode(value, nullptr, tail_);

	// If list empty
	if (!tail_)
	{
		head_ = tail_ = new_tail;
	}
	
	else
	{
		tail_->next_ = new_tail;
		tail_ = new_tail;
	}

	++size;
}


/*==== Delete ====*/

// Removes the node from the start of the list
template<typename T>
inline void DoublyLinkedList<T>::DeleteFromHead()
{
	if (!head_)
		return;

	DoublyLinkedNode* old_head = head_;
	DoublyLinkedNode* new_head = head_->next_;

	// If the list contains only one element
	if (!new_head)
	{
		head_ = tail_ = nullptr;
	}

	else
	{
		new_head->back_ = nullptr;
		head_ = new_head;
	}

	delete old_head;
	--size;
}

// Removes the node from the end of the list
template<typename T>
inline void DoublyLinkedList<T>::DeleteFromTail()
{
	if (!tail_)
		return;

	DoublyLinkedNode* old_tail = tail_;
	DoublyLinkedNode* new_tail = tail_->back_;

	// If the list contains only one element
	if (!new_tail)
	{
		head_ = tail_ = nullptr;
	}
	
	else
	{
		new_tail->next_ = nullptr;
		tail_ = new_tail;
	}

	delete old_tail;
	--size_;
}

// Remove all nodes
template<typename T>
inline void DoublyLinkedList<T>::DeleteAll()
{
	while(head_)
	{
		DeleteFromHead();
	}
}


/*==== Print ====*/

// Print all nodes
template<typename T>
inline void DoublyLinkedList<T>::Show()
{
	DoublyLinkedNode current = head_;
	for (size_t i = 0; i < size_; i++)
	{
		std::cout << current.value_ << " ";
		current = current.next_;
	}
}


/*==== Search ====*/

// Looking for a node by meaning
// Returns nullopt if nothing is found
template<typename T>
inline std::optional<size_t> DoublyLinkedList<T>::Search(const T& target_value)
{
	DoublyLinkedNode* temp = head_;

	for (size_t i = 0; i < size_; i++)
	{
		if (temp->value_ == target_value)
			return i;

		temp = temp->next_;
	}

	return std::nullopt;	// If nothing is found, null returns
}


/*==== Replace ====*/

// Replaces all matching values ​​in the list with a new value
// Returns the number of altered elements or -1
template<typename T>
inline int DoublyLinkedList<T>::Replace(const T& target_value, const T& new_value)
{
	int counter = 0;
	
	DoublyLinkedNode* temp = head_;

	for (size_t i = 0; i < size_; i++)
	{
		if (temp->value_ == target_value)
		{
			temp->value_ = new_value;
			++counter;
		}

		temp = temp->next_;
	}

	return counter > 0 ? counter : -1;
}


/*==== Reverse ====*/

// Unfolds the list in the opposite direction
template<typename T>
inline void DoublyLinkedList<T>::Reverse()
{
	DoublyLinkedNode* current = head_;

	while (current)
	{
		std::swap(current->next_, current->back_);
		current = current->back_;
	}
	
	std::swap(head_, tail_);
}
