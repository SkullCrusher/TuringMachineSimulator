/*
	Module: Tape
	File: Tape.cpp
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
#include "stdafx.h"
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


Tape::Tape() :
	cells(" "),
	current_cell(0),
	blank_character(' ')
{
}

	/* Name: load
	* Purpose: The method load reads the blank character from the Turing machine definition file.
	* Operation: If the blank character is reserved or not printable, or the next keyword 
		does not follow it in the file, an error message is displayed and valid is set to false.
	*/
void Tape::load(ifstream &definiton, bool& valid) {

	string value;
	if ((definiton >> value) &&
		(value.length() == 1) && (value[0] != '\\') &&
		(value[0] != '[') && (value[0] != ']') &&
		(value[0] != '<') && (value[0] != '>') &&
		(value[0] >= '!') && (value[0] <= '~')) {

		blank_character = value[0];
	}else{
		cout << "Error: Illegal blank character.\n";
		valid = false;
	}


	// Read the next keyword.
	if ((!(definiton >> value)) || (UpperCase(value) != "FINAL_STATES:")){
		cout << "Error: Missing Keyword after blank character " << blank_character << ".\n";
		valid = false;
	}
}

	/* Name: validate
	* Purpose: The method validate determines if the blank character of the Turing machine is in the 
		tape alphabet, but not in the input alphabet. 
	* Operation: If the blank character is in the input alphabet, or is not in the tape alphabet, 
		an error message is displayed and valid is set to of false.
	*/
void Tape::validate(const Input_Alphabet& input_alphabet,
	const Tape_Alphabet& tape_alphabet,
	bool& valid) const
{

	// The blank character cannot be in the input alphabet.
	if (input_alphabet.is_element(blank_character)) {
		cout << "Error: Blank character '" << blank_character << "' is in the input alphabet.\n";
		valid = false;
	}

	// The blank character has to be in the tape alphabet.
	if (!tape_alphabet.is_element(blank_character)) {
		cout << "Error: Blank character '" << blank_character << "' is not in the tape alphabet.\n";
		valid = false;
	}

}

	/* Name: view
	* Purpose: The method view displays the blank character of the Turing machine.
	* Operation: Returns blank_character.
	*/
void Tape::view() const{
	cout << "B = " << blank_character << "\n\n";
}

	/* Name: initialize
	* Purpose: To prepare the tape before the start of the simulation.
	* Operation: The method initialize sets the Turing machine tape to the input string followed 
		by a blank character, replacing the previous contents of the tape. 
		The current cell is set to the first cell on the tape, indicated by the index 0.
	*/
void Tape::initialize(string input_string)
{
	cells = input_string + blank_character;
	current_cell = 0;
}

	/* Name: update
	* Purpose: The method update first determines if the update of the Turing machine tape is possible.
	* Operation: The method returns if a left move is specified from the first cell. If a right move is 
		specified from the last cell, a blank character is appended to the tape. Assuming that the 
		update may be performed, the character to write on the tape is stored in the current cell, 
		replacing the previous character in that cell. To move the current cell one cell to the left, 
		the index is decremented, or to move the current cell one cell to the right, the index is incremented. 
	*/
void Tape::update(char write_character, Direction Move_Direction){

	Move_Direction = UpperCase(Move_Direction);

		// Prevent moving off the start of the tape.
	if ((Move_Direction == "L") && (current_cell == 0)){
		//thow an exception instead of just returning.
		// another thow would be "Unable to find transition"
		throw crash("Left move from first cell");
	}

		// Prevent moving off the end of the tape by attaching a new blank character.
	if ((Move_Direction == "R") && (current_cell == cells.length() - 1)){
		// The exception he added.
		// You get an object of "BAD_ALLOC can be thrown by string operator +="
		// "BAD_ALLOC" is derived from base class exception in c++ standard library.
		// Class exception defines a virtual function: 'what'
		// 'what' may be inherited or overridden in derived class.
		// 'what' provides a error message for particular exception.
		
		cells += blank_character;
	}

	cells[current_cell] = write_character;

	if (Move_Direction == "L"){
		current_cell--;
	}else{
		current_cell++;
	}
}

	/* Name: left
	* Purpose: The method left returns a character string up to the maximum number of 
		cells from the Turing machine tape to the left of the current cell, excluding that cell.
	* Operation:  The length of the string will be less than the maximum if there are fewer cells 
		to the left of the current cell. If the string is truncated from the tape, 
		the reserved character '<' will be added to the beginning of the string.
	*/
string Tape::left(int maximum_number_of_cells) const{
	int first_cell = max(0, current_cell - maximum_number_of_cells);

	string value = cells.substr(first_cell, current_cell - first_cell);

	// see if it truncated part of it.
	if (value.length() < current_cell){
		value.insert(0, "<");
	}

	return value;
}

	/* Name: right
	* Purpose:  The method right returns a character string up to the maximum number of cells from the 
		Turing machine tape to the right of the current cell, including that cell.
	* Operation: The length of the string will be less than the maximum if there are fewer cells to the 
		right of the current cell up to the rightmost nonblank character. If the string is truncated from the 
		tape, the reserved character '>' will be added to the end of the string.
	*/
string Tape::right(int maximum_number_of_cells) const{

	int end_cell = cells.length() - 1;
	while ((end_cell >= current_cell) &&
		(cells[end_cell] == blank_character))
	{
		--end_cell;
	}

	int last_cell = min(end_cell, current_cell + maximum_number_of_cells - 1);

	string value = cells.substr(current_cell, last_cell - current_cell + 1);

	// see if it truncated part of it.
	if (value.length() < end_cell - current_cell + 1) {
		value.append(">");
	}

	return value;
}

	/* Name: current_character
	* Purpose: The method current_character returns the character contained in the current cell on the Turing machine tape.
	* Operation: Return index cell from the cells string.
	*/
char Tape::current_character() const{
	return cells[current_cell];
}

	/* Name: is_first_cell
	* Purpose: To find if the tape is on the first most cell.
	* Operation: The method is_first_cell returns a value of true if the current cell 
		on the Turing machine tape is the first cell, indicated by the index 0. Otherwise, 
		it returns a value of false.
	*/
bool Tape::is_first_cell() const{
	return (current_cell == 0);
}
