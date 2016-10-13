/*
	Module: Tape
	File: Tape.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The tape of a Turing machine consists of an ordered sequence of cells, 
		indexed starting at 0, which may grow to any size needed up to the limit of 
		storage during operation of the machine on an input string. Each cell contains a 
		character in the tape alphabet. An input string is stored in the lowest numbered 
		tape cells at the beginning of operation, and all other tape cells initially contain 
		the blank character. The current cell starts at the first cell on the tape. In performing 
		a transition of the Turing machine, the character contained in the current cell may be 
		read and written, and the current cell may be moved one cell to the left or right. The 
		tape exists only as part of a Turing machine.
*/

#ifndef Tape_H
#define Tape_H

#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Direction.h"
#include "Uppercase.h"
#include "crash.h"

#include <string>
#include <fstream>
#include <iostream>
#include <exception>
#include <algorithm>

using namespace std;


class Tape {

private:
		// The attribute cells is a dynamically growing character string containing the Turing machine tape. 
		// In preforming an update, the tape may be extended by appending a blank character.
	string cells;

		// The index of the current cell on the Turing machine tape is stored in the attribute current_cell.
	int current_cell;

		// The blank character used, to initialize and extend the Turing machine tape, is contained in the attribute blank_character.
	char blank_character;
public:
	Tape();

	/* Name: load
	* Purpose: The method load reads the blank character from the Turing machine definition file.
	* Operation: If the blank character is reserved or not printable, or the next keyword 
		does not follow it in the file, an error message is displayed and valid is set to false.
	*/
	void load(ifstream& definiton, bool& valid);

	/* Name: validate
	* Purpose: The method validate determines if the blank character of the Turing machine is in the 
		tape alphabet, but not in the input alphabet. 
	* Operation: If the blank character is in the input alphabet, or is not in the tape alphabet, 
		an error message is displayed and valid is set to of false.
	*/
	void validate(const Input_Alphabet& input_Alphabet, const Tape_Alphabet& tape_alphabet, bool &valid) const;

	/* Name: view
	* Purpose: The method view displays the blank character of the Turing machine.
	* Operation: Returns blank_character.
	*/
	void view() const;

	/* Name: initialize
	* Purpose: To prepare the tape before the start of the simulation.
	* Operation: The method initialize sets the Turing machine tape to the input string followed 
		by a blank character, replacing the previous contents of the tape. 
		The current cell is set to the first cell on the tape, indicated by the index 0.
	*/
	void initialize(string input_string);

	/* Name: update
	* Purpose: The method update first determines if the update of the Turing machine tape is possible.
	* Operation: The method returns if a left move is specified from the first cell. If a right move is 
		specified from the last cell, a blank character is appended to the tape. Assuming that the 
		update may be performed, the character to write on the tape is stored in the current cell, 
		replacing the previous character in that cell. To move the current cell one cell to the left, 
		the index is decremented, or to move the current cell one cell to the right, the index is incremented. 
	*/
	void update(char write_character, Direction move_direction);

	/* Name: left
	* Purpose: The method left returns a character string up to the maximum number of 
		cells from the Turing machine tape to the left of the current cell, excluding that cell.
	* Operation:  The length of the string will be less than the maximum if there are fewer cells 
		to the left of the current cell. If the string is truncated from the tape, 
		the reserved character '<' will be added to the beginning of the string.
	*/
	string left(int maximum_number_of_cells) const;

	/* Name: right
	* Purpose:  The method right returns a character string up to the maximum number of cells from the 
		Turing machine tape to the right of the current cell, including that cell.
	* Operation: The length of the string will be less than the maximum if there are fewer cells to the 
		right of the current cell up to the rightmost nonblank character. If the string is truncated from the 
		tape, the reserved character '>' will be added to the end of the string.
	*/
	string right(int maximum_number_of_cells) const;

	/* Name: current_character
	* Purpose: The method current_character returns the character contained in the current cell on the Turing machine tape.
	* Operation: Return index cell from the cells string.
	*/
	char current_character() const;

	/* Name: is_first_cell
	* Purpose: To find if the tape is on the first most cell.
	* Operation: The method is_first_cell returns a value of true if the current cell 
		on the Turing machine tape is the first cell, indicated by the index 0. Otherwise, 
		it returns a value of false.
	*/
	bool is_first_cell() const;

};


#endif
