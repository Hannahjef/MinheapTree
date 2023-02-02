//--------------------------------------------------------------------
// HUFFMANALGORITHM.H
// The class responsible for iplementing the Huffman Algorithm and generate code for each character
// Author: Hannah Jeffi 
//--------------------------------------------------------------------
// HuffManAlgorithm class: 
//	Creates a HuffManAlgorithm class with the following methods:
// Constructor,destructor, Parameterised Constructor, getCodes , output codes.
//--------------------------------------------------------------------
#pragma once
#include "HuffmanTree.h"
#include "PriorityQueue.h"
#include <iostream>
const int NUM_LETTERS = 26; 

using namespace std;

class HuffmanAlgorithm 
{
public:
	//-------------------------- Constructor HuffmanAlgorithm ------------------------------------
	// Default constructor for class HuffmanTree
	// Preconditions:   None
	// Postconditions:  Initialize the private variables
	//  
	HuffmanAlgorithm();

	//-------------------------- Parameterized Constructor HuffmanAlgorithm ------------------------------------
	//  constructor for class HuffmanAlgorithm for implementing HuffmanAlgorithm and generating code
	// Preconditions:   None
	// Postconditions:  merged Tree should be placed in [1] in queue, codeBook should contain the codes
	// 
	HuffmanAlgorithm(const int(&counts)[NUM_LETTERS]);



	//-------------------------- GetWord ------------------------------------
		//  Encode the given string.
		// Preconditions:   None
		// Postconditions:  the in string contains the encoded
		// Assumptions: Ignoring any character other than (a - z)
	string getWord(string in)const;

	//-------------------------- Destructor HuffmanAlgorithm ------------------------------------
	// Default constructor for class HuffmanAlgorithm
	// Preconditions:   None
	// Postconditions:  deletes the dynamically allocated memory
	// 
	//~HuffmanAlgorithm();



	//-----------------------------  <<  ----------------------------------------
	// Overloaded output operator for class HuffManALgorithm . Prints the character and their corresponding code in each line
	// Preconditions:   None
	// Postconditions: returns the output stream object which prints the character to code mapping
	friend ostream& operator<<(ostream& os, const HuffmanAlgorithm& comp);

private:
	PriorityQueue <HuffmanTree>  queue_;
	string codeBook[NUM_LETTERS];
	
};

