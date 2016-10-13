/*
	Module: Transition_Function
	File: Transition_Function.cpp
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

#include "Transition_Function.h"

#include "Direction.h"
#include "Transition.h"
#include "crash.h"
#include "States.h"
#include "Uppercase.h"
#include "Transition.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


/* Name: view
* Purpose: Prints out all of the transitions.
* Operation: This method is used to print out the value of the transition. 
	This is used by class Show_Command though the class Turing_Machine.
*/
void Transition_Function::view() const{

		// Display a empty set if it is empty.
	if (transitions.size() == 0){
		cout << "Delta = {}\n\n";
		return;
	}

	for (unsigned int i = 0; i < transitions.size(); i++){

		Transition Temp = transitions[i];
	
		cout << "Delta("
			<< Temp.Source_State()
			<< ", "
			<< Temp.Read_Character()
			<< ") = ("
			<< Temp.Destination_State()
			<< ", "
			<< Temp.Write_Character()
			<< ", "
			<< Temp.Move_Direction()
			<< ")\n";
	}

	cout << "\n";
}

	/* Name: validate
	* Purpose: To find if the all of the transtions are valid.
	* Operation: This method it checks that each transition is based on the class States,
		Tape_Alphabet, and moves R or L.
	*/
void Transition_Function::validate(const Tape_Alphabet &tape_alphabet, States states, bool & valid){

		// Prevent two transitions from having the same source_state and Read_Character
	for (unsigned int i = 0; i < transitions.size(); i++){		
		for(unsigned int z = i + 1; z < transitions.size(); z++){			
			if(transitions[i].Source_State() == transitions[z].Source_State()
			&& transitions[i].Read_Character() == transitions[z].Read_Character()){
				valid = false;
				cout << "Error: Two transitions have the same source state '" << transitions[i].Source_State() << "' and read character '" << transitions[i].Read_Character() << "'.\n";
			}			
		}		
	}

		// Validate the the tape alphabet elements.
	for (unsigned int i = 0; i < transitions.size(); i++){

			// The read character is not contained within the tape alphabet.
		if (!tape_alphabet.is_element(transitions[i].Read_Character())){			
			cout << "Error: Transition read character '" << transitions[i].Read_Character() << "' is not in tape alphabet.\n";
			valid = false;
		}

			// The write character is not contained within the tape alphabet.
		if (!tape_alphabet.is_element(transitions[i].Write_Character())){
			cout << "Error: Transition write character '" << transitions[i].Write_Character() << "' is not in tape alphabet.\n";
			valid = false;
		}
	}

		// Validate that all of the states are in the list of states.
	for (unsigned int i = 0; i < transitions.size(); i++){

			// The source state is not in the list of states.
		if (!states.is_element(transitions[i].Source_State())){
			cout << "Error: Transition source state '" << transitions[i].Source_State() << "' is not in states.\n";

			valid = false;
		}

			// The destination state is not in the list of states. 
		if (!states.is_element(transitions[i].Destination_State())){
			cout << "Error: Transition destination state '" << transitions[i].Destination_State() << "' is not in states.\n";

			valid = false;
		}
	}
	
}

/* Name: find_transition
* Purpose: To find the next transition for the Turing Machine.
* Operation: This method searches all of the class transition until it: 
	finds a matching source and read character; or it searched all of the 
	Transitions and was unable to find one. If the class transition_Function 
	is able to find a Transition that matches it will return the Transition. 
	If the class Transition_Function is unable to find a transition that 
	matches it returns an error.
*/
void Transition_Function::find_transition(string source_state, char read_character, string & destination_state, char & write_character, Direction & move_direction){

		// Search for a transition that matches the source_state and the read_character.
	for (unsigned int i = 0; i < transitions.size(); i++){

			// If the transition matches set the output and return.
		if (transitions[i].Source_State() == source_state && transitions[i].Read_Character() == read_character){

			destination_state = transitions[i].Destination_State();
			write_character = transitions[i].Write_Character();
			move_direction = transitions[i].Move_Direction();

			return;
		}
	}

		// if no transition was returned crash the turing machine.
	throw crash("Unable to find transition");
}

/* Name: load
* Purpose: Loads transitions from a definition file.
* Operation: This method is passed a File and it reads it until, it 
	finds the next section's tag, a error in parsing the data happens, 
	or it reaches the end of the file.
*/
void Transition_Function::load(ifstream & definiton, bool & valid){

		// If the keyword the parser was looking for was found.
	bool Found_Keyword = false;

		// Attempt to load the list of transitions from the definition file.
	for (;;){
		string Source;
		string Read;
		string Destination;
		string Write;
		string Move;

			// Triggers the outter for loop to exit.
		bool Dead = false;

			// Load each of the next parts of the transition set and check for the keyword.
		for (unsigned int i = 0; i < 5; i++){
			string Temp = "";		

				// attempt to load the next part.
			definiton >> Temp;

				// Look for the keyword to trigger the switch to the next section.
			if (UpperCase(Temp) == "INITIAL_STATE:"){
				Found_Keyword = true;
				Dead = true;
				
					// If it is just starting the new transition and it finds the keyword break without error.
				if (i == 0){
					break;
				}else{
					std::cout << "Error: Incomplete transition.\n";
					valid = false;

					break;
				}
			}					

				// Assign it to the correct variable.
			switch (i){
				case 0: Source		= Temp;
					break;
				case 1: Read		= Temp;
					break;
				case 2: Destination = Temp;
					break;
				case 3: Write		= Temp;
					break;
				case 4: Move		= Temp;
					break;
			}
		}

			// If that was the end of the file break.
		if (definiton.eof()){ break; }

			// Triggered by keyword.
		if (Dead){ break;}


			// Validate the variables (Read, Write, and Move can only be one character long).
		bool Invalid = false;

		if (Read.size() != 1){ 
			cout << "Error: Transition character '" << Read << "' longer than one.\n"; 
			Invalid = true;
		}
		if (Write.size() != 1){ 
			cout << "Error: Transition character '" << Write << "' longer than one.\n"; 
			Invalid = true;
		}
		if (Move.size() != 1){ 
			cout << "Error: Transition character '" << Move << "' longer than one.\n"; 
			Invalid = true;
		}

			// Validate that the transition only contains L or R
		if (UpperCase(Move) != "R" && UpperCase(Move) != "L"){
			cout << "Error: Transition can only contain L or R not '" << Move << "'.\n";
			
			valid = false;
		}
				
		
			// If not invalid, add the new transition to the list.
		if (!Invalid){
			Transition NewTransition(Source, Read[0], Destination, Write[0], Move);

			transitions.push_back(NewTransition);
		}else{
			valid = false;
		}
	}	

	// Verify that the keyword was found, else error.
	if (!Found_Keyword){
		printf("Error: Unable to find the keyword 'INITIAL_STATE:' in the file.\n");

		valid = false;
	}
}
