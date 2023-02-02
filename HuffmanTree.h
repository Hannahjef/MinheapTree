#pragma once
#include<iostream>
#include<string>


using namespace std;

class HuffmanTree
{
private:
	struct Node
	{
		char data_;
		int frequency_;
		Node* left_;
		Node* right_;

	public:
		//-------------------------- Constructor Node ------------------------------------
	// Parameterised constructor for class Node
	// Preconditions:   None
	// Postconditions:  the data is assigned to the parameter passed and frequency is initialised to parameter, 
	// left and right node pointers are initialised to nullptr
	//         
		Node(char anEntry, int frequency) : data_{ anEntry }, frequency_{ frequency }, left_{ nullptr }, right_{ nullptr } {};

		//-------------------------- Constructor Node ------------------------------------
	// Parameterised constructor for class Node
	// Preconditions:   None
	// Postconditions:  the data is assigned to the default value passed and frequency is initialised to , 
	// left and right node pointers are initialised to nullptr
	//         
		Node(int frequency) : data_{ 0 }, frequency_{ frequency }, left_{ nullptr }, right_{ nullptr } {};
	};


public:
	//-------------------------- Constructor HuffmanTree ------------------------------------
	// Default constructor for class HuffmanTree
	// Preconditions:   None
	// Postconditions:  root is initialized to nullptr
	//          
	HuffmanTree() : root_{ nullptr } {};

	//-------------------------- Constructor HuffmanTree ------------------------------------
	// Default constructor for class HuffmanTree
	// Preconditions:   None
	// Postconditions:  root is initialized to nullptr
	//          
	HuffmanTree(char alphabet, int occurances);


	//---------------------------- Copy -----------------------------------------
	// Copy constructor for class HuffmanTree
	// Preconditions:   rhs Tree should not be empty
	// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
	HuffmanTree(const HuffmanTree& rhs);


	//---------------------------- Merge Constructor -----------------------------------------
	// Merge constructor for class HuffmanTree combines the two given inputs into a new tree and copying the memory
	//  to new tree leaving the old trees empty
	// Preconditions:   None
	// Postconditions:  The old Tree should be deleted. The new tree should hold the lhs and rhs root in left and right respectively
	HuffmanTree(HuffmanTree*& lhs, HuffmanTree*& rhs);

	//-------------------------- Destructor ------------------------------------
   // Default constructor for class HuffmanTree
   // Preconditions:   None
   // Postconditions:  all the dynaic memory of node is heap is de allocated and root_ points to nullptr without memory leak 
   //   
	~HuffmanTree();

	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator - If Tree is present in right object the tree is deallocated and a deep copy is made
	// Preconditions:   rhs Tree should not be empty
	// Postconditions:  Both the tree have same tree structure and data but different memory
	HuffmanTree& operator=(const HuffmanTree& rhs);

	//-----------------------------  <  -----------------------------------------
	// Overloaded comparator operator - It compares the frequency of the left and the right sub tree , If frequeny 
	// is same then the smallest ascii is considered as smallest
	// Preconditions:   None
	// Postconditions:  return true if tree is smaller
	bool operator<(const HuffmanTree& rhs);

	//-----------------------------  Getcode  -----------------------------------------
	// This method traverse the tree and get code from the char in the tree. 
	// The input is integer from 0-25 which repsresents a-z
	// Preconditions:   The tree must not be empty
	// Postconditions: The code is copied in the array
	void getCode(string*  codeArray)const;

private:
	//---------------------------- CopyTree -----------------------------------------
	// Deep Copy method for class HuffmanTree
	// Preconditions:  Node is not null
	// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
	void copyTree(Node*& lhsNode, const Node* node);



	//-----------------------------  Getcode Helper  -----------------------------------------
	// This method traverse the tree and get code from the char in the tree. 
	// The input is integer from 0-25 which repsresents a-z
	// Preconditions:   None
	// Postconditions:  Tree unchanged and return the code in string
	void getCodeHelper(string* codeArray, const Node* node, string& code)const;


	//-----------------------------  findLowest Tree  -----------------------------------------
		// This method traverse the tree and finds the lowest chat and return the node code from the char in the tree. 
		// The input is integer from 0-25 which repsresents a-z
		// Preconditions:   None
		// Postconditions:  Tree unchanged and return the code in string
	Node* findLowest(Node* node, Node* smallNode);

	//---------------------------- Clear -----------------------------------------
	// Clear Method for the Binary search Tree. Makes the Tree  Empty by deallocating the heap storage
	// Preconditions:   if the root_ != nullptr
	// Postconditions:  Clears the Tree by deallocating the memory and making the tree root_ = nullptr
	void clear(Node*& node);


	Node* root_ = nullptr;   // The root of the HuffmanTree

};

