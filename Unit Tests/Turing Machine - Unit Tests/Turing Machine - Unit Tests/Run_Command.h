/*
	Module: Run_Command
	File: Run_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class Run_Command will start the Turing Machine running on a selected input string. 

*/

#ifndef Run_Command_H
#define Run_Command_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Visable.h"
#include "Turing_Machine.h"

using namespace std;

/* Name: Run_Command
* Purpose: This function takes a list of input strings as a parameter and prompts for user input. 
* Operation: The input that the function asks for is a number that is assigned to a input string. 
	The number can be found using the list command on the command prompt. If the user enters nothing, 
	the function will return without any message or without starting the Turing Machine. If the input 
	is an invalid input string number, or the Turing Machine is already running on a input string, an
	error will be displayed, and the function will return. If the input is a valid string number, the
	input string that the user selected will be given to Turing_Machine, and the function will return.
*/
void Run_Command(Turing_Machine &TM, vector<string> list, int Truncation, int Max_Transitions){


		// Check if the list is empty.
	if (list.size() < 1){
		cout << "Error: No input strings.\n";
		return;
	}

		// Check if the turing machine is not running, set up a input string.
	if (!TM.is_operating()){
	
			// Storage to hold the user entered string.
		std::string New_String;

			// Ask for input from the user.
		cout << "Input string number: ";
		getline(std::cin, New_String);

			// If the input is empty return without doing anything.
		if (New_String == ""){
			return;
		}

		// Validate that the input is only from 0-9 characters.
		for (unsigned int i = 0; i < New_String.size(); i++){
			if (New_String[i] > '9' || New_String[i] < '0'){
				cout << "Error: A non-numerical input entered.\n";
				return;
			}
		}

		int Input_String_Index = 0;

			// Prevent buffer overflows when a large number is provided with the try block.
		try {
			// Convert the input to be a int.
			//Input_String_Index = std::stoi(New_String);
			Input_String_Index = atoi(New_String.c_str());

		}
		catch (const std::out_of_range& oor) {
			cout << "Error: number is too large.\n";
			return;
		}

			// Validate the size they input.
		if (Input_String_Index <= 0){
			cout << "Error: The input string number must be 1 or greater.\n";
			return;
		}

			// Remove one from the index to match it to an array.
		Input_String_Index--;

			// Check that index is correct.
		if (Input_String_Index >= list.size()){
			cout << "Error: Number is not a index to a input string.\n";
			return;
		}
					
		
			// The input string was already validated when entered so just run it.
		TM.initialize(list[Input_String_Index]);

			// Show the ID before starting.
		TM.view_instantaneous_description(Truncation);
	}

	
		// Preform the transitions.
	TM.perform_transitions(Max_Transitions);

		// Display the ID from the transitions.
	TM.view_instantaneous_description(Truncation);

		// Handle accept.
	if (TM.is_accepted_input_string()){
		cout << "Input string " << Visable(TM.input_string()) << " was accepted in " << TM.total_number_of_transitions() << " transitions.\n";
	}

		// Handle reject.
	if(TM.is_rejected_input_string()){
		cout << "Input string " << Visable(TM.input_string()) << " was rejected in " << TM.total_number_of_transitions() << " transitions.\n";
	}

}

#endif
