/*
	Module: Turing_Machine
	File: Turing_Machine.h
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

#ifndef Turing_Machine_H
#define Turing_Machine_H

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




class Turing_Machine {
private:
	
		// The tape for that is used by the simulation to hold the characters on the tape plus the blank character.
	Tape tape;

		// The list of characters that can be used in a input string.
	Input_Alphabet input_alphabet;

		// The list of characters that can be written to the tape.
	Tape_Alphabet tape_alphabet;

		// The list of transitions that can occur.
	Transition_Function transition_function;

		// The list of states that the turing machine can be in.
	States states;

		// the list of states that will cause the turing machine to accept if entered.
	Final_States final_states;

		// The attribute description stores the description that was loaded from the Turing Machine definition file.
	vector<string> Description;

		// The attribute the initial_state of the Turing machine that was loaded from the Turing Machine definition file.
	string Inital_State;

		// The attribute the current_state that the Turing machine is on in the simulation.
	string Current_state;

		// The attribute original_input_string contains the original input string that was initially put on the Turing Machine tape.
	string Original_Input_String;

		// This attribute stores the number of transitions that the Turing Machine has run.
	int number_of_transitions;

		// This attribute holds the state for if the Turing_Machine is a valid Turing Machine.
	bool valid;

		// This attribute stores if the Turing_Machine has been used before.
	bool used;

		// This attribute stores if the Turing_Machine is currently operating on a input string.
	bool operating;

		// This attribute stores if the Turing_Machine has accepted the input string,
	bool accepted;

		// The attribute rejected is used to store if the Turing_Machine was rejected or not.
	bool rejected;

public:

	/* Name: Turing_Machine
	* Purpose: This function accepts a file name and appends ".TM" to it and attempts to load the file. 
	* Operation: If it is unable to load the file it displays an error and returns. If the file is found 
			and is able to be read, this function will read the name of the description of the Turing 
			Machine from the file, and the open file will be passed to the following classes in this 
			order. First States, Input_Alphabet, Tape_Alphabet, Transition_Function, back to this 
			function where it will read the initial state and pass the file to Tape_Alphabet, and 
			finally to Final_States.	
	*/
	Turing_Machine(string definition_file_name);

	/* Name: view_definiton
	* Purpose: This function prints out the definition of the Turing Machine 
		that was loaded from the Turing Machine definition file.
	* Operation:  To do this the function calls the correct display function 
		for each component contained within it.
	*/
	void view_definiton() const;

	/* Name: view_instantaneous_description
	* Purpose: This function displays the instantaneous description to the user.
	* Operation: When displaying, the side is displayed with the max number of cells
		being the argument passed in. Next the current state is inserted. Finally,
		the right side is displayed with the max number of cells being the parameter.
	*/
	void view_instantaneous_description(int maxiumum_number_of_cells) const;

	/* Name: initialize
	* Purpose: This function prepares the turing machine for operation.
	* Operation: This function sets the current input string to input_string if operating 
		is set to false. The initial state of the Turing Machine's tape is displayed 
		to the user. If operating is set to true, an error message is displayed and 
		the function returns.
	*/
	void initialize(string input_string);

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
	void perform_transitions(int maximum_number_of_transitions);

	/* Name: terminate_operation
	* Purpose: This function makes the Turing_Machine unable to continue and forces 
		the user to start a new simulation on a input string.
	* Operation: This function stops the operation on the current input string 
		by setting the operating variable to false.
	*/
	void terminate_operation();

	/* Name: input_string
	* Purpose:  To get the current input string.
	* Operation: This function returns Original_Input_String.
	*/
	string input_string() const;

	/* Name: total_number_of_transitions
	* Purpose: This function returns the amount of transitions that have been 
		completed on the currently selected input string.
	* Operation: Returns the number_of_transitions.
	*/
	int total_number_of_transitions() const;

	/* Name: is_valid_definition
	* Purpose: This function returns if the validation by the components, 
		that are contained within the Turing_Machine class, all validated correctly.
	* Operation: Returns valid.
	*/
	bool is_valid_definition() const;

	/* Name: is_valid_input_string
	* Purpose: This function returns if the input string is valid.
	* Operation: This function checks that every character in the input string is contained within the input_alphabet. 
		If any character contains a character that is reserved or is not in the input_alphabet it returns false.
		If it contains only characters that are in the input alphabet it returns true. 
	*/
	bool is_valid_input_string(string value) const;

	/* Name: is_used
	* Purpose: This function returns if the Turing_Machine has been used before.
	* Operation: Returns used.
	*/
	bool is_used() const;

	/* Name: is_operating
	* Purpose: This function returns the value of operating.
	* Operation: Returns operating.
	*/
	bool is_operating() const;

	/* Name: is_accepted_input_string
	* Purpose: This function returns the value of accepted.
	* Operation: Returns accepted.
	*/
	bool is_accepted_input_string() const;

	/* Name: is_rejected_input_string
	* Purpose: This function returns the value of rejected.
	* Operation: Returns rejected.
	*/
	bool is_rejected_input_string() const;
};

#endif
