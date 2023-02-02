//--------------------------------------------------------------------
// PRIORITYQUEUE.H
// Declaration and definition of the template PriorityQueue class
// Author: Olson (borrowing from a previous edition of Carrano/Henry)
//--------------------------------------------------------------------
// PriorityQueue class: 
//	Implements a priority queue using a heap with the following methods:
//		insert, deleteMin, findMin, heapify
//  The heap is stored in a vector (see the CSS 502 lecture notes)
//  Assumptions:
//	 Can only store data for which operator< exists
//	 (hence the Comparable type variable)
//--------------------------------------------------------------------

#pragma once
#include <vector>
using namespace std;

template <typename Comparable>
class PriorityQueue {
public:
	
	//-------------------------- Constructor  ------------------------------------
	// Default constructor for class PriorityQueue
	// Preconditions:   None
	// Postconditions:  numElements is initialized to zero
	//    
	PriorityQueue()
	{
		numElements = 0;
	}
	
	//-------------------------- Destructor  ------------------------------------
	// Default constructor for class PriorityQueue
	// Preconditions:   None
	// Postconditions:  Items in the queue are deleted.
	//  
	~PriorityQueue()
	{
		//numElements = 0;
		clear();
	}


	//-------------------------- Copy Constructor  ------------------------------------
	// Default constructor for class PriorityQueue
	// Preconditions:   count should not be less than zero
	// Postconditions:  None
	// 
	PriorityQueue(Comparable* array[], int count)
	{
		items.push_back(nullptr);
		numElements = count;
		for (int i = 0; i < count; i++)
		{

			items.push_back(nullptr);

			items[i + 1] = array[i];
		}
		heapify();
	}
	//-------------------------- Copy Constructor  ------------------------------------
	// Default constructor for class PriorityQueue
	// Preconditions:   rhs is not null
	// Postconditions:  None
	// 
	PriorityQueue(const PriorityQueue& rhs)
	{
		if (rhs.numElements == 0)
		{
			return;
		}
		else
		{
			items.push_back(nullptr);
			numElements = rhs.numElements;
			for (int i = 0; i <= rhs.numElements; i++)
			{
				if (i != rhs.numElements)
				{
					items.push_back(nullptr);
				}
				items[i] = rhs.items[i];
			}
		}
	}


	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator - If Queue is present in right object the tree is deallocated and a deep copy is made
	// Preconditions:   rhs queue should not be empty
	// Postconditions:  Both the queue have same tree structure and data 
	PriorityQueue& operator=(const PriorityQueue& rhs)
	{
		if (this != &rhs)
		{
			clear();
			
			numElements = rhs.numElements;
			while ((int)items.size() <= numElements)
				items.push_back(nullptr);
			for (int i = 0; i <= rhs.numElements; i++)
			{
				items[i] = rhs.items[i];
			}
		}
		return *this;
	}
	
	

	//------------------------------------------------------------------------
	// insert - adds a single item to the priority queue
	// Preconditions: the initial heap has sufficient memory allocated
	//		and satisfies the heap order property
	// Postconditions: inserts the item into the queue, such that a new
	//		heap is created containing the union of the elements
	void insert(Comparable* c) {
		if (c == NULL) return;

		// Add item in position 0 (dummy position) to prevent percolating up from root 
		if (items.size() < 1) items.push_back(c);
		else items[0] = c;

		// Ensure we have enough space
		numElements++;
		while ((int)items.size() <= numElements)
			items.push_back(nullptr);

		// Percolate up
		int position = numElements;
		while (*c < *items[position / 2]) {
			items[position] = items[position / 2];
			position = position / 2;
		}
		items[position] = c;
	}

	//------------------------------------------------------------------------
	// findMin - returns a const pointer to the minimum value in the priority queue
	// Preconditions: items[0] exists if numElements is larger than zero
	// Postconditions: Returns nullptr if the heap is empty, otherwise returns
	//	the item at the root of the heap (presumably the minimum priority).
	const Comparable* findMin() const {
		if (numElements <= 0) return nullptr;
		else return items[1];
	}

	//------------------------------------------------------------------------
	// deleteMin - delete the minimum and return a pointer to it
	// Preconditions: items[0] exists if numElements is larger than zero
	// Postconditions: Returns nullptr if the heap is empty, otherwise returns
	//	the item at the root of the heap (presumably the minimum priority).
	//  That element is deleted from the heap and the heap order property is
	//  restored.
	Comparable* deleteMin() {
		if (numElements == 0) return nullptr;

		// Give memory back to user
		Comparable* toReturn = items[1];
		items[1] = items[numElements];
		numElements--;

		percolateDown(1);
		return toReturn;
	}

	//------------------------------------------------------------------------
	// size
	// Preconditions: none
	// Postconditions: returns the size of the queue
	int size() const {
		return numElements;
	}

	//------------------------------------------------------------------------
	// isEmpty
	// Preconditions: none
	// Postconditions: returns whether the queue is empty (zero elements)
	int isEmpty() const {
		return numElements == 0;
	}


private:

	//------------------------------------------------------------------------
	// percolateDown - used to restore the heap order property after deleteMin
	// Preconditions: Both subtrees of the root are heaps
	// Postconditions: Restores the heap order property by shifting the root
	//  down until it reaches an appropriate node
	void percolateDown(int position) {
		int child = position * 2;
		if (child > numElements) return;
		if (child != numElements && *items[child + 1] < *items[child]) child++;
		if (*items[child] < *items[position]) {
			swap(items[child], items[position]);
			percolateDown(child);
		}
	}

	//------------------------------------------------------------------------
	// heapify - modifies any set of data into a heap
	// Preconditions: items has been allocated space for numElements pointers
	// Postconditions: The items stored form a heap
	void heapify() {
		for (int i = numElements / 2; i > 0; i--)
			percolateDown(i);
	}

	/// <summary>
	/// 
	/// </summary>
	void clear()
	{
		items[0] = nullptr;
		for (int count = 1; count <= size(); count++)
		{
			if (items[count] != nullptr)
			{
				delete items[count];
			}
			items[count] = nullptr;
			numElements--;
		}
	
	}

	int numElements = 0;			// Number of elements in the queue
	vector <Comparable*> items;	// The elements in the priority queue stored in a heap

	
};
