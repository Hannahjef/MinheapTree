//--------------------------------------------------------------------
// HUFFMANALGORITHM.CPP
// The class responsible for iplementing the Huffman Algorithm and generate code for each character
// Author: Hannah Jeffi 
//--------------------------------------------------------------------
// HuffManAlgorithm class: 
//	Creates a HuffManAlgorithm class with the following methods:
// Constructor,destructor, Parameterised Constructor, getCodes , output codes.
//--------------------------------------------------------------------

#include "HuffmanAlgorithm.h"
#include "HuffmanTree.h"
#include <iostream>
using namespace std;


//-------------------------- Constructor HuffmanAlgorithm ------------------------------------
	// Default constructor for class HuffmanAlgorithm
	// Preconditions:   None
	// Postconditions:  Initialize the private variables
	// 
HuffmanAlgorithm::HuffmanAlgorithm()
{
	for (int count = 0; count < NUM_LETTERS; count++)
	{
		codeBook[count] = "";
	}

}

//-------------------------- Parameterized Constructor HuffmanAlgorithm ------------------------------------
	//  constructor for class HuffmanAlgorithm for implementing HuffmanAlgorithm and generating code
	// Preconditions:   None
	// Postconditions:  merged Tree should be placed in [1] in queue, codeBook should contain the codes
	// 

HuffmanAlgorithm::HuffmanAlgorithm(const int(&counts)[NUM_LETTERS])
{
	for (int count = 0; count < NUM_LETTERS; count++)
	{
		codeBook[count] = "";
	}
	//Creating single node tree for each character
	for (int ascii = 0; ascii < NUM_LETTERS; ascii++)
	{
		//Creating a Tree and inserting a node for each occurances in the array
		HuffmanTree* ht = new  HuffmanTree(ascii + 97, counts[ascii]);
		queue_.insert(ht);
		ht = nullptr;
	}
	// performing Huffman Algorithm and merging tree
	while (queue_.size() > 1)
	{
		HuffmanTree* tree1 = queue_.deleteMin();
		HuffmanTree* tree2 = queue_.deleteMin();
		HuffmanTree* tree3 = new HuffmanTree(tree1, tree2);
		delete (tree1);
		delete (tree2);
		tree1 = nullptr;
		tree2 = nullptr;
		//dequeue the least two frequency, add them and put it back
		queue_.insert(tree3);

	}
	//Get code and store in codeBook.
	queue_.findMin()->getCode(&codeBook[0]);
}


//-------------------------- GetWord ------------------------------------
	//  Encode the given string.
	// Preconditions:   None
	// Postconditions:  the in string contains the encoded
	// Assumptions: Ignoring any character other than (a - z)
string HuffmanAlgorithm::getWord(string in)const
{
	string encodedInput = "";
	for (char c : in)
	{
		if (c >= 97 && c <= 122)
		{
			encodedInput.append(codeBook[c - 97]);
		}
	}
	return encodedInput;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class HuffManALgorithm . Prints the character and their corresponding code in each line
// Preconditions:   None
// Postconditions: returns the output stream object which prints the character to code mapping
ostream& operator<<(ostream& os, const HuffmanAlgorithm& comp)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		cout << (char)(i + 97) << " " << comp.codeBook[i] << endl;
	}
	return os;
}



//--------------------------------------------------------------------
// HUFFMANALGORITHM.CPP
// The class responsible for iplementing the Huffman Algorithm and generate code for each character
// Author: Hannah Jeffi 
//--------------------------------------------------------------------
// HuffManAlgorithm class: 
//	Creates a HuffManAlgorithm class with the following methods:
// Constructor,destructor, Parameterised Constructor, getCodes , output codes.
//--------------------------------------------------------------------

#include "HuffmanAlgorithm.h"
#include "HuffmanTree.h"
#include <iostream>
using namespace std;


//-------------------------- Constructor HuffmanAlgorithm ------------------------------------
	// Default constructor for class HuffmanAlgorithm
	// Preconditions:   None
	// Postconditions:  Initialize the private variables
	// 
HuffmanAlgorithm::HuffmanAlgorithm()
{
	for (int count = 0; count < NUM_LETTERS; count++)
	{
		codeBook[count] = "";
	}

}

//-------------------------- Parameterized Constructor HuffmanAlgorithm ------------------------------------
	//  constructor for class HuffmanAlgorithm for implementing HuffmanAlgorithm and generating code
	// Preconditions:   None
	// Postconditions:  merged Tree should be placed in [1] in queue, codeBook should contain the codes
	// 

HuffmanAlgorithm::HuffmanAlgorithm(const int(&counts)[NUM_LETTERS])
{
	for (int count = 0; count < NUM_LETTERS; count++)
	{
		codeBook[count] = "";
	}
	//Creating single node tree for each character
	for (int ascii = 0; ascii < NUM_LETTERS; ascii++)
	{
		//Creating a Tree and inserting a node for each occurances in the array
		HuffmanTree* ht = new  HuffmanTree(ascii + 97, counts[ascii]);
		queue_.insert(ht);
		ht = nullptr;
	}
	// performing Huffman Algorithm and merging tree
	while (queue_.size() > 1)
	{
		HuffmanTree* tree1 = queue_.deleteMin();
		HuffmanTree* tree2 = queue_.deleteMin();
		HuffmanTree* tree3 = new HuffmanTree(tree1, tree2);
		delete (tree1);
		delete (tree2);
		tree1 = nullptr;
		tree2 = nullptr;
		//dequeue the least two frequency, add them and put it back
		queue_.insert(tree3);

	}
	//Get code and store in codeBook.
	queue_.findMin()->getCode(&codeBook[0]);
}


//-------------------------- GetWord ------------------------------------
	//  Encode the given string.
	// Preconditions:   None
	// Postconditions:  the in string contains the encoded
	// Assumptions: Ignoring any character other than (a - z)
string HuffmanAlgorithm::getWord(string in)const
{
	string encodedInput = "";
	for (char c : in)
	{
		if (c >= 97 && c <= 122)
		{
			encodedInput.append(codeBook[c - 97]);
		}
	}
	return encodedInput;
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class HuffManALgorithm . Prints the character and their corresponding code in each line
// Preconditions:   None
// Postconditions: returns the output stream object which prints the character to code mapping
ostream& operator<<(ostream& os, const HuffmanAlgorithm& comp)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		cout << (char)(i + 97) << " " << comp.codeBook[i] << endl;
	}
	return os;
}



