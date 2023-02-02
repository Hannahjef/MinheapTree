//--------------------------------------------------------------------
// HUFFMANTREE.CPP
// Declaration and definition of the template HuffmanTree class
// Author: Hannah Jeffi 
//--------------------------------------------------------------------
// HuffManTree class: 
//	Creates a HuffMan tree class with the following methods:
// Constructor,copy constructor, assignment operator , Node 
//--------------------------------------------------------------------


#include "HuffmanTree.h"
#include<iostream>
#include<string>
using namespace std;

//-------------------------- Constructor HuffmanTree ------------------------------------
	// Default constructor for class HuffmanTree
	// Preconditions:   None
	// Postconditions:  root is initialized to nullptr
	//          
HuffmanTree::HuffmanTree(char alphabet, int occurances)
{
	root_ = new Node(alphabet, occurances);
}


//---------------------------- Copy -----------------------------------------
// Copy constructor for class HuffmanTree
// Preconditions:   rhs Tree should not be empty
// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
HuffmanTree::HuffmanTree(const HuffmanTree& rhs)
{
	root_ = nullptr;
	if (rhs.root_ != nullptr)
	{
		copyTree(root_, rhs.root_);
	}

}

//---------------------------- CopyTree -----------------------------------------
// Deep Copy method for class HuffmanTree
// Preconditions:   Node is not nullptr
// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
void HuffmanTree::copyTree(Node*& lhsNode, const Node* rhsNode)
{
	if (rhsNode != nullptr)
	{
		lhsNode = new Node(rhsNode->data_);
		lhsNode->frequency_ = rhsNode->frequency_;
		copyTree(lhsNode->left_, rhsNode->left_);
		copyTree(lhsNode->right_, rhsNode->right_);
	}

}


//-----------------------------  <  -----------------------------------------
	// Overloaded comparator operator - It compares the frequency of the left and the right sub tree , If frequeny 
	// is same then the smallest ascii is considered as smallest
	// Preconditions:   none
	// Postconditions:  return true if tree is smaller
bool HuffmanTree:: operator<(const HuffmanTree& rhs)
{
	if (root_->frequency_ < rhs.root_->frequency_)
	{
		return true;
	}
	else
		if (root_->frequency_ > rhs.root_->frequency_)
		{
			return false;
		}
		else if ((root_->frequency_ == rhs.root_->frequency_))
		{
			Node* leftNode = findLowest(root_, nullptr);
			Node* rightNode = findLowest(rhs.root_, nullptr);
			return (leftNode->data_ < rightNode->data_);
		}

	return false;
}



//-----------------------------  findLowest Tree  -----------------------------------------
		// This method traverse the tree and finds the lowest chat and return the node code from the char in the tree. 
		// The input is integer from 0-25 which repsresents a-z
		// Preconditions:   None
		// Postconditions:  Tree unchanged and return the code in string
HuffmanTree::Node* HuffmanTree::findLowest(Node* node, Node* smallNode)
{

	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		if (smallNode == nullptr || node->data_ < smallNode->data_)
		{
			smallNode = node;
		}

	}
	else
	{
		return findLowest(node->left_, smallNode);
		return findLowest(node->right_, smallNode);
	}
	return smallNode;
}


//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator - If Tree is present in right object the tree is deallocated and a deep copy is made
	// Preconditions:   Both the objects are not equal
	// Postconditions:  Both the arrays have same tree structure and data but different memory
HuffmanTree& HuffmanTree::operator=(const HuffmanTree& rhs)
{
	if (this != &rhs)
	{
		clear(root_);
		copyTree(root_, rhs.root_);
	}
	return *this;
}

//---------------------------- Merge Constructor -----------------------------------------
// Merge constructor for class HuffmanTree combines the two given inputs into a new tree and copying the memory
//  to new tree leaving the old trees empty
// Preconditions:   Both The lhs and rhs object not be null pointers
// Postconditions:  The old Tree should not have any data allocated
HuffmanTree::HuffmanTree(HuffmanTree*& lhs, HuffmanTree*& rhs)
{

	if (lhs->root_ != nullptr && rhs->root_ != nullptr)
	{
		this->root_ = new Node(lhs->root_->frequency_ + rhs->root_->frequency_);
		this->root_->left_ = lhs->root_;
		this->root_->right_ = rhs->root_;
		lhs->root_ = nullptr;
		rhs->root_ = nullptr;
	}
	else if (lhs->root_ == nullptr && rhs->root_ == nullptr)
	{
		return;
	}
	else if (lhs->root_ == nullptr)  // if lhs is empty
	{
		this->root_ = new Node(rhs->root_->frequency_);
		this->root_->left_ = rhs->root_;
		rhs->root_ = nullptr;
		rhs = nullptr;
	}
	else // rhs is empty
	{
		this->root_ = new Node(lhs->root_->frequency_);
		this->root_->left_ = lhs->root_;
		lhs->root_ = nullptr;
		rhs = nullptr;
	}



}

//-----------------------------  Getcode  -----------------------------------------
	// This method traverse the tree and get code from the char in the tree. 
	// The input is integer from 0-25 which repsresents a-z
	// Preconditions:   The tree must not be empty
	// Postconditions: The code is copied in the array
void HuffmanTree::getCode(string* codeArray)const
{
	string code = "";
	getCodeHelper(codeArray, root_, code);
}

//-----------------------------  Getcode Helper  -----------------------------------------
// This method traverse the tree and get code from the char in the tree. 
// The input is integer from 0-25 which repsresents a-z
// The input is integer from 0-25 which repsresents a-z
// Preconditions:   The tree must not be empty
// Postconditions: The code is copied in the array
void HuffmanTree::getCodeHelper(string* codeArray, const Node* node, string& code)const
{

	if (node == nullptr)
	{
		return;
	}

	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		if (node->data_ != '\0')
		{
			int value = node->data_ - 97;
			*(codeArray + value) = code;
		}
	}
	else
	{
		getCodeHelper(codeArray, node->left_, code.append("0"));
		getCodeHelper(codeArray, node->right_, code.append("1"));
	}
	if (code.size() >= 1)
	{
		code.pop_back();
	}
}

//-------------------------- Destructor ------------------------------------
// Default constructor for class HuffmanTree
// Preconditions:   None
// Postconditions:  all the dynaic memory of node is heap is de allocated and root_ points to nullptr without memory leak 
//   

HuffmanTree:: ~HuffmanTree()
{

	clear(root_);
}


//---------------------------- Clear -----------------------------------------
// Clear Method for the Binary search Tree. Makes the Tree  Empty by deallocating the heap storage
// Preconditions:   if the root_ != nullptr
// Postconditions:  Clears the Tree by deallocating the memory and making the tree root_ = nullptr
void HuffmanTree::clear(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}
	clear(node->left_);
	clear(node->right_);
	delete node;
	node = nullptr;
}//--------------------------------------------------------------------
// HUFFMANTREE.CPP
// Declaration and definition of the template HuffmanTree class
// Author: Hannah Jeffi 
//--------------------------------------------------------------------
// HuffManTree class: 
//	Creates a HuffMan tree class with the following methods:
// Constructor,copy constructor, assignment operator , Node 
//--------------------------------------------------------------------


#include "HuffmanTree.h"
#include<iostream>
#include<string>
using namespace std;

//-------------------------- Constructor HuffmanTree ------------------------------------
	// Default constructor for class HuffmanTree
	// Preconditions:   None
	// Postconditions:  root is initialized to nullptr
	//          
HuffmanTree::HuffmanTree(char alphabet, int occurances)
{
	root_ = new Node(alphabet, occurances);
}


//---------------------------- Copy -----------------------------------------
// Copy constructor for class HuffmanTree
// Preconditions:   rhs Tree should not be empty
// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
HuffmanTree::HuffmanTree(const HuffmanTree& rhs)
{
	root_ = nullptr;
	if (rhs.root_ != nullptr)
	{
		copyTree(root_, rhs.root_);
	}

}

//---------------------------- CopyTree -----------------------------------------
// Deep Copy method for class HuffmanTree
// Preconditions:   Node is not nullptr
// Postconditions:  The HuffmanTree in the lhs is copied to the HuffmanTree in the rhs object
void HuffmanTree::copyTree(Node*& lhsNode, const Node* rhsNode)
{
	if (rhsNode != nullptr)
	{
		lhsNode = new Node(rhsNode->data_);
		lhsNode->frequency_ = rhsNode->frequency_;
		copyTree(lhsNode->left_, rhsNode->left_);
		copyTree(lhsNode->right_, rhsNode->right_);
	}

}


//-----------------------------  <  -----------------------------------------
	// Overloaded comparator operator - It compares the frequency of the left and the right sub tree , If frequeny 
	// is same then the smallest ascii is considered as smallest
	// Preconditions:   none
	// Postconditions:  return true if tree is smaller
bool HuffmanTree:: operator<(const HuffmanTree& rhs)
{
	if (root_->frequency_ < rhs.root_->frequency_)
	{
		return true;
	}
	else
		if (root_->frequency_ > rhs.root_->frequency_)
		{
			return false;
		}
		else if ((root_->frequency_ == rhs.root_->frequency_))
		{
			Node* leftNode = findLowest(root_, nullptr);
			Node* rightNode = findLowest(rhs.root_, nullptr);
			return (leftNode->data_ < rightNode->data_);
		}

	return false;
}



//-----------------------------  findLowest Tree  -----------------------------------------
		// This method traverse the tree and finds the lowest chat and return the node code from the char in the tree. 
		// The input is integer from 0-25 which repsresents a-z
		// Preconditions:   None
		// Postconditions:  Tree unchanged and return the code in string
HuffmanTree::Node* HuffmanTree::findLowest(Node* node, Node* smallNode)
{

	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		if (smallNode == nullptr || node->data_ < smallNode->data_)
		{
			smallNode = node;
		}

	}
	else
	{
		return findLowest(node->left_, smallNode);
		return findLowest(node->right_, smallNode);
	}
	return smallNode;
}


//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator - If Tree is present in right object the tree is deallocated and a deep copy is made
// Preconditions:   Both the objects are not equal
// Postconditions:  Both the arrays have same tree structure and data but different memory
HuffmanTree& HuffmanTree::operator=(const HuffmanTree& rhs)
{
	if (this != &rhs)
	{
		clear(root_);
		copyTree(root_, rhs.root_);
	}
	return *this;
}

//---------------------------- Merge Constructor -----------------------------------------
// Merge constructor for class HuffmanTree combines the two given inputs into a new tree and copying the memory
//  to new tree leaving the old trees empty
// Preconditions:   Both The lhs and rhs object not be null pointers
// Postconditions:  The old Tree should not have any data allocated
HuffmanTree::HuffmanTree(HuffmanTree*& lhs, HuffmanTree*& rhs)
{

	if (lhs->root_ != nullptr && rhs->root_ != nullptr)
	{
		this->root_ = new Node(lhs->root_->frequency_ + rhs->root_->frequency_);
		this->root_->left_ = lhs->root_;
		this->root_->right_ = rhs->root_;
		lhs->root_ = nullptr;
		rhs->root_ = nullptr;
	}
	else if (lhs->root_ == nullptr && rhs->root_ == nullptr)
	{
		return;
	}
	else if (lhs->root_ == nullptr)  // if lhs is empty
	{
		this->root_ = new Node(rhs->root_->frequency_);
		this->root_->left_ = rhs->root_;
		rhs->root_ = nullptr;
		rhs = nullptr;
	}
	else // rhs is empty
	{
		this->root_ = new Node(lhs->root_->frequency_);
		this->root_->left_ = lhs->root_;
		lhs->root_ = nullptr;
		rhs = nullptr;
	}



}

//-----------------------------  Getcode  -----------------------------------------
// This method traverse the tree and get code from the char in the tree. 
// The input is integer from 0-25 which repsresents a-z
// Preconditions:   The tree must not be empty
// Postconditions: The code is copied in the array
void HuffmanTree::getCode(string* codeArray)const
{
	string code = "";
	getCodeHelper(codeArray, root_, code);
}

//-----------------------------  Getcode Helper  -----------------------------------------
// This method traverse the tree and get code from the char in the tree. 
// The input is integer from 0-25 which repsresents a-z
// The input is integer from 0-25 which repsresents a-z
// Preconditions:   The tree must not be empty
// Postconditions: The code is copied in the array
void HuffmanTree::getCodeHelper(string* codeArray, const Node* node, string& code)const
{

	if (node == nullptr)
	{
		return;
	}

	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		if (node->data_ != '\0')
		{
			int value = node->data_ - 97;
			*(codeArray + value) = code;
		}
	}
	else
	{
		getCodeHelper(codeArray, node->left_, code.append("0"));
		getCodeHelper(codeArray, node->right_, code.append("1"));
	}
	if (code.size() >= 1)
	{
		code.pop_back();
	}
}

//-------------------------- Destructor ------------------------------------
// Default constructor for class HuffmanTree
// Preconditions:   None
// Postconditions:  all the dynaic memory of node is heap is de allocated and root_ points to nullptr without memory leak 
//   

HuffmanTree:: ~HuffmanTree()
{

	clear(root_);
}


//---------------------------- Clear -----------------------------------------
// Clear Method for the Binary search Tree. Makes the Tree  Empty by deallocating the heap storage
// Preconditions:   if the root_ != nullptr
// Postconditions:  Clears the Tree by deallocating the memory and making the tree root_ = nullptr
void HuffmanTree::clear(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}
	clear(node->left_);
	clear(node->right_);
	delete node;
	node = nullptr;
}