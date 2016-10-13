/*
	Module: Input_Alphabet
	File: Input_Alphabet.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: Holds the alphabet for the input strings.
*/

#ifndef Input_Alphabet_H
#define Input_Alphabet_H

#include "Input_Alphabet.h"
#include "Uppercase.h"
#include "Tape_Alphabet.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Input_Alphabet {

private:
	// his attribute is used to store the list of Input_Alphabet characters that were loaded from the 
	// 	Turing Machine definition file. The characters contained must be a subset of the ones contained 
	// 	in the Tape_Alphabet and also does not include the blank character.
	vector<char> Alphabet;

public:
	/* Name: load
	* Purpose:  This function attempts to load the Input_Alphabet from the File.
	* Operation: If there is a failure on reading or parsing the file, the function will 
		set valid to false, display the error, and return. If the function is able to 
		read and parse the file, the function will return.
	*/
	void load(ifstream& definiton, bool& valid);

	/* Name: view
	* Purpose: This function displays the contents of Alphabet.
	* Operation: Prints out the characters in Alphabet.
	*/
	void view() const;

	/* Name: is_element
	* Purpose: This function checks if the parameters character is contained within Alphabet.
	* Operation: Compares the argument with every character in alphabet to find a match.
	*/
	bool is_element(char value) const;

	/* Name: validate
	* Purpose: To determine if the loaded alphabet is valid.
	* Operation: This function compares the elements loaded from the Turing Machine definition 
		file to the ones in Tape_Alphabet.
	*/
	void validate(Tape_Alphabet tape_alphabet, bool & valid);
	
};

#endif
