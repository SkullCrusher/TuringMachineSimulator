/*
	Module: Transition_Function
	File: Transition_Function.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: The transition function is responsible providing easy access to 
		the class Transition from other classes. It is responsible for loading the 
		transitions, selecting the correct one for the next transition if available, 
		validating the transitions, and printing out the transitions.
*/

#ifndef Transition_Function_H
#define Transition_Function_H

#include "Direction.h"
#include "Transition.h"
#include "crash.h"
#include "States.h"
#include "Uppercase.h"
#include "Transition.h"
#include "Tape_Alphabet.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Transition_Function{

private:
	std::vector<Transition> transitions;

public:
	
	/* Name: view
	* Purpose: Prints out all of the transitions. 
		This is used by class Show_Command though the class Turing_Machine.
	*/
	void view() const;

	/* Name: validate
	* Purpose: To find if the all of the transtions are valid.
	* Operation: This method it checks that each transition is based on the class States,
		Tape_Alphabet, and moves R or L.
	*/
	void validate(const Tape_Alphabet &tape_alphabet, States states, bool &valid);

	/* Name: find_transition
	* Purpose: To find the next transition for the Turing Machine.
	* Operation: This method searches all of the class transition until it: 
		finds a matching source and read character; or it searched all of the 
		Transitions and was unable to find one. If the class transition_Function 
		is able to find a Transition that matches it will return the Transition. 
		If the class Transition_Function is unable to find a transition that 
		matches it returns an error.
	*/
	void find_transition(string source_state, char read_character, string& destination_state, char &write_character, Direction &move_direction);

	/* Name: load
	* Purpose: Loads transitions from a definition file.
	* Operation: This method is passed a File and it reads it until, it 
		finds the next section's tag, a error in parsing the data happens, 
		or it reaches the end of the file.
	*/
	void load(ifstream& definiton, bool& valid);
	
};

#endif
