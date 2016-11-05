/*
	Module: Turing_Machine
	File: Turing_Machine.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class is designed to hold a single Turing Machine definition transition.
	All other classes that want to use it must access it by using the class Transition_Function.
*/
#include "stdafx.h"
#include "Turing_Machine.h"

#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"
#include "Uppercase.h"
#include "Visable.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


	/* Name: Turing_Machine
	* Purpose: This function accepts a file name and appends ".TM" to it and attempts to load the file. 
	* Operation: If it is unable to load the file it displays an error and returns. If the file is found 
			and is able to be read, this function will read the name of the description of the Turing 
			Machine from the file, and the open file will be passed to the following classes in this 
			order. First States, Input_Alphabet, Tape_Alphabet, Transition_Function, back to this 
			function where it will read the initial state and pass the file to Tape_Alphabet, and 
			finally to Final_States.	
	*/
void Turing_Machine::view_definiton() const{

		// Print off the description for the TM definition file.
	string Combined = "";

	for (unsigned int i = 0; i < Description.size(); i++){
		if (i == 0){
			Combined += Description[i];
		}else{
			Combined += " " + Description[i];
		}
	}
		// catch if the description is empty.
	if (Description.size() > 0){
		cout << Combined << "\n\n";
	}

		// Print the list of states.
	states.view();
	
		// Print the input alphabet.
	input_alphabet.view();
		 
		// Print the tape alphabet.
	tape_alphabet.view();

		// Print the transitions.
	transition_function.view();

		// Print the inital state.
	cout << "Q0 = " << Inital_State << "\n\n";

		// Print the blank character.
	tape.view();

		// Print the final states.
	final_states.view();
}


	/* Name: view_definiton
	* Purpose: This function prints out the definition of the Turing Machine 
		that was loaded from the Turing Machine definition file.
	* Operation:  To do this the function calls the correct display function 
		for each component contained within it.
	*/	
Turing_Machine::Turing_Machine(string definition_file_name){

		// Set the internal values.
	number_of_transitions = 0;
	valid = true;
	used = false;
	operating = false;
	accepted = false;
	rejected = false;


		// The path to the turing machine definiton file.
	string Path = definition_file_name + ".DEF";
	

		// Attempt to open the file.
	ifstream Definition_File(Path.c_str());
		
		// Check if the file was unable to be opened.
	if (!Definition_File.is_open()){
		printf("Error: Unable to find turing machine definiton file.\n");
		valid = false;

		return;
	}

		// If the keyword the parser was looking for was found.
	bool Found_Keyword = false;

		// Attempt to load the description from the definition file.
	for (;;){
		std::string Temp;

			// Load the next character set.
		Definition_File >> Temp;

			// If that was the end of the file break.
		if (Definition_File.eof()){ break; }

			// Look for the keyword to trigger the switch to the next section.
		if (UpperCase(Temp) == "STATES:"){
			Found_Keyword = true;
			break;
		}else{
				// Add the current to the list.
			Description.push_back(Temp);
		}
	}

		// Verify that the keyword was found, else error.
	if (!Found_Keyword){
		printf("Error: Unable to find the keyword 'STATES:' in the file.\n");

		valid = false;

			// Close the Turing machine definition file because it is no longer required. 
		Definition_File.close();

		return;
	}
	
	
		// Handle keyword 'STATES:' by passing the file to States states;
	states.load(Definition_File, valid);		

		// Handle keyword 'INPUT_ALPHABET:' by passing the file to Input_Alphabet input_alphabet;
	input_alphabet.load(Definition_File, valid);

		// Handle keyword 'TAPE_ALPHABET:' by passing the file to Tape_Alphabet tape_alphabet;
	tape_alphabet.load(Definition_File, valid);

		// Handle keyword 'TRANSITION_FUNCTION:' by passing the file to Transition_Function transition_function;
	transition_function.load(Definition_File, valid);
		
		// Handle keyword 'INITIAL_STATE:' by simply loading the initial state into string Inital_State;
	string Loaded_Initial_State = ""; // A storage place for the initial state from the file.
	string Next_Keyword = "";		 // A storage place for the next keyword from the file.

	Definition_File >> Loaded_Initial_State >> Next_Keyword;
	
	
	for(int z = 0; z < Loaded_Initial_State.size(); z++){	

			// Check it is printable and does not contain '\', '[', ']', '>', '<'.
		if (Loaded_Initial_State[z] < '!'
			|| Loaded_Initial_State[z] > '~'
			|| Loaded_Initial_State[z] == '\\'
			|| Loaded_Initial_State[z] == '['
			|| Loaded_Initial_State[z] == ']'
			|| Loaded_Initial_State[z] == '>'
			|| Loaded_Initial_State[z] == '<'){

			valid = false;
	
				// Print the invalid character if it is printable.
			if (Loaded_Initial_State[z] >= '!' && Loaded_Initial_State[z] <= '~'){
				cout << "Error: Initial state contains character '" << Loaded_Initial_State << "' that is reserved.\n";
			}else{
				cout << "Error: Initial state contains a character that is not printable.\n";
			}
		}
	}
	
		// If that was the end of the file or the keyword was not found.
	if (Definition_File.eof() || UpperCase(Next_Keyword) != "BLANK_CHARACTER:"){
		cout << "Error: Unable to find the keyword 'BLANK_CHARACTER:' in the file.\n";

		valid = false;
	}else{
		Inital_State = Loaded_Initial_State;
	}

		// Handle keyword 'BLANK_CHARACTER:' by passing the file to Tape tape;
	tape.load(Definition_File, valid);

		// Handle keyword 'FINAL_STATES:' by passing the file to Final_States final_states;
	final_states.load(Definition_File, valid);


		// Close the Turing machine definition file because it is no longer required. 
	Definition_File.close();



		// Validate the turing machine.
	tape.validate(input_alphabet, tape_alphabet, valid);
	input_alphabet.validate(tape_alphabet, valid);	
	transition_function.validate(tape_alphabet, states, valid);
	final_states.validate(states, valid);

		// Check that the inital state is in the set of states.
	if (states.is_element(Inital_State) == false){
		cout << "Error: Initial state '" << Inital_State << " is not in the list of states.\n";
		valid = false;
	}
}

	/* Name: view_instantaneous_description
	* Purpose: This function displays the instantaneous description to the user.
	* Operation: When displaying, the side is displayed with the max number of cells
		being the argument passed in. Next the current state is inserted. Finally,
		the right side is displayed with the max number of cells being the parameter.
	*/
void Turing_Machine::view_instantaneous_description(int maximum_number_of_cells) const{

	cout << number_of_transitions << ". " 
		 << tape.left(maximum_number_of_cells) 
		 << "["
		 << Current_state
		 << "]"
		 << tape.right(maximum_number_of_cells)
		 << "\n";
}

	/* Name: initialize
	* Purpose: This function prepares the turing machine for operation.
	* Operation: This function sets the current input string to input_string if operating 
		is set to false. The initial state of the Turing Machine's tape is displayed 
		to the user. If operating is set to true, an error message is displayed and 
		the function returns. This also sets operating to true.
	*/
void Turing_Machine::initialize(string input_string){

		// Reset the machine.
	used = true;
	accepted = false;
	rejected = false;
	number_of_transitions = 0;

	Current_state = Inital_State;
	Original_Input_String = input_string;

	tape.initialize(input_string);

	
		// If the initial state is the final state, accept it.
	if (final_states.is_element(Inital_State)){
		accepted = true;
	}
}

	/* Name: perform_transitions
	* Purpose: This function call will simulate the Turing Machine that is loaded in 
		from the Turing Machine definition file on the set input string. 
	* Operation: The simulation can only happen if operating is set to true, accepted 
		and rejected are both set to false. The function will continue to simulate 
		the Turing Machine until the amount of transitions reaches the 
		maximum_number_of_transitons unless the Turing machine rejects or accepts 
		the input string before the maximum_number_of_transitions is met. If the 
		Turing Machine is accepted or rejected, operating is set to false, and a 
		message is displayed to the user.
	*/
void Turing_Machine::perform_transitions(int maximum_number_of_transitions){

		// Loop until no more transitions are allowed.
	for (int i = 0; i < maximum_number_of_transitions; i++){

			// We check if the current state is a final state, if so accept and quit.
		if (final_states.is_element(Current_state)){

				// End the turing machine and accept it.
			accepted = true;
			operating = false;
		
			return;
		}
		
			// Get the current tape character.
		char CurrentTapeCharacter = tape.current_character();

		string destination_state;			
		char write_character = ' ';		
		Direction move_direction;

		// Attempt to find a transition.
		try{
			transition_function.find_transition(Current_state, CurrentTapeCharacter, destination_state, write_character, move_direction);
		}catch (exception &Error){

			rejected = true;
			operating = false;	

			return;
		}

		try{
			tape.update(write_character, move_direction);
		}catch (exception &Error){

			rejected = true;
			operating = false;

			return;
		}
		
			// Everything worked so change the Turing machine state.
		Current_state = destination_state;
		number_of_transitions++;

		operating = true;

	}
	
	// Check that at the end if it is in a final state, accept.
	if (final_states.is_element(Current_state)){

			// End the turing machine and accept it.
		accepted = true;
		operating = false;
		
		return;
	}
}

	/* Name: terminate_operation
	* Purpose: This function makes the Turing_Machine unable to continue and forces 
		the user to start a new simulation on a input string.
	* Operation: This function stops the operation on the current input string 
		by setting the operating variable to false.
	*/
void Turing_Machine::terminate_operation(){
	operating = false;
}

	/* Name: input_string
	* Purpose:  To get the current input string.
	* Operation: This function returns Original_Input_String.
	*/
string Turing_Machine::input_string() const{
	return Original_Input_String;
}

	/* Name: total_number_of_transitions
	* Purpose: This function returns the amount of transitions that have been 
		completed on the currently selected input string.
	* Operation: Returns the number_of_transitions.
	*/
int Turing_Machine::total_number_of_transitions() const{
	return number_of_transitions;
}

	/* Name: is_valid_definition
	* Purpose: This function returns if the validation by the components, 
		that are contained within the Turing_Machine class, all validated correctly.
	* Operation: Returns valid.
	*/
bool Turing_Machine::is_valid_definition() const{
	return valid;
}

	/* Name: is_valid_input_string
	* Purpose: This function returns if the input string is valid.
	* Operation: This function checks that every character in the input string is contained within the input_alphabet. 
		If any character contains a character that is reserved or is not in the input_alphabet it returns false.
		If it contains only characters that are in the input alphabet it returns true. 
	*/
bool Turing_Machine::is_valid_input_string(string value) const{

		// Check each element
	for (unsigned int i = 0; i < value.size(); i++){
			// Validate the character.
		if (!input_alphabet.is_element(value[i])){
			return false;
		}
	}

	return true;
}

	/* Name: is_used
	* Purpose: This function returns if the Turing_Machine has been used before.
	* Operation: Returns used.
	*/
bool Turing_Machine::is_used() const{
	return used;
}

	/* Name: is_operating
	* Purpose: This function returns the value of operating.
	* Operation: Returns operating.
	*/
bool Turing_Machine::is_operating() const{
	return operating;
}

	/* Name: is_accepted_input_string
	* Purpose: This function returns the value of accepted.
	* Operation: Returns accepted.
	*/
bool Turing_Machine::is_accepted_input_string() const{
	return accepted;
}

	/* Name: is_rejected_input_string
	* Purpose: This function returns the value of rejected.
	* Operation: Returns rejected.
	*/
bool Turing_Machine::is_rejected_input_string() const{
	return rejected;
}
