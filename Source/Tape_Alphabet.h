/*
	Module: Tape_Alphabet
	File: Tape_Alphabet.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The list of characters that can be written to the type cells in Tape.
*/

#ifndef Tape_Alphabet_H
#define Tape_Alphabet_H

#include "Tape_Alphabet.h"
#include "Uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Tape_Alphabet {

private:
		// The attribute Alphabet is used to store the characters that can be placed on the tape cells.
	vector<char> Alphabet;

public:
	/* Name: load
	* Purpose: This method is used to load new Tape_Alhpabet characters from a file.
	* Operation: This stops when a keyword is found or the end of the file is reached. 
		All errors will be displayed to the user. If there are any errors the function 
		will set valid to fail thereby rejecting the Turing Machine Definition file. 
	*/
	void load(ifstream& definiton, bool& valid);

	/* Name: view
	* Purpose: To display the tape alphabet.
	* Operation: Prints out the values in the tape alphabet.
	*/
	void view() const;

	/* Name: is_element
	* Purpose: This method is used to check if the character is within the alphabet. 
	* Operation: Compares the argument to alphabet and returns if a match was found.
	*/
	bool is_element(char value) const;

};
#endif
