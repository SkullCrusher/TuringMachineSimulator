/*
	Module: Final_States
	File: Final_States.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: he state that if the Turing Machine transitions into cannot leave,
		the Input String is accepted, and the class Turing_machine sets operating to false.
*/
#include "stdafx.h"
#include "Final_States.h"
#include "Uppercase.h"
#include "States.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

	/* Name: load
	* Purpose: This method is called to load new final states into the class Final_States.
	* Operation: This stops when a keyword is found or the end of the file is reached. 
		All errors will be displayed to the user. If there are any errors the function 
		will set valid to fail thereby rejecting the Turing Machine Definition file. 
	*/
void Final_States::load(ifstream & definiton, bool & valid){

	for (;;){
		string Loaded_Final_State = "";

			// Unable to load the next final state.
		if (!(definiton >> Loaded_Final_State)){
			break;
		}

		name.push_back(Loaded_Final_State);
	}
}

	/* Name: view
	* Purpose: This method is used to display all of the current final states in a formatting 
		of the formal definition of the Turing Machine class.
	* Operation: Prints out all of the values in name.
	*/
void Final_States::view() const{
	

		// Print out the final states in the correct format.
	cout << "F = {";

	for (unsigned int i = 0; i < name.size(); i++){
		if (i == 0){
			cout << name[i];
		}else{
			cout << ", " << name[i];
		}
	}

	cout << "}\n\n";
}

	/* Name: validate
	* Purpose: This method is used validate that the final states are correct.
	* Operation: Checks that each of the final states that to see if it is
		contained within states and it does not contain invalid characters.
	*/
void Final_States::validate(States &states, bool & valid){
	
		// Prevent duplicate error messages about any final state.
	vector<int> Displayed;
	
	// Validate the states do not contain invalid characters.
	
		// To prevent multiple of the same error from being displayed.
	vector<string> DisplayedCharacters;

		// Check for any invalid characters in all of the states.		
	for (unsigned int i = 0; i < name.size(); i++){

		bool Skip = false;

			// Check if the error was displayed before.
		for (unsigned int z = 0; z < DisplayedCharacters.size(); z++){
			if (name[i] == DisplayedCharacters[z]){
				Skip = true;
			}
		}

		if (Skip){ continue; }
	
		for(int z = 0; z < name[i].size(); z++){		

				// Check it is printable and does not contain '\', '[', ']', '>', '<'.
			if (name[i][z] < '!'
				|| name[i][z] > '~'
				|| name[i][z] == '\\'
				|| name[i][z] == '['
				|| name[i][z] == ']'
				|| name[i][z] == '>'
				|| name[i][z] == '<'){

				valid = false;
				
				Displayed.push_back(i);

					// Block the display of this error again.
				DisplayedCharacters.push_back(name[i]);

					// Print the invalid character if it is printable.
				if (name[i][z] >= '!' && name[i][z] <= '~'){
					cout << "Error: Final state contains character '" << name[i] << "' that is reserved.\n";
				}else{
					cout << "Error: Final state contains a character that is not printable.\n";
				}
			}
		}
	}

		

		// Check that each final state is different O(N^2). 
	for (unsigned int i = 0; i < name.size(); i++){

		bool Skip = false;

			// Check the displayed list to see if this error was already displayed.
		for (unsigned int z = 0; z < Displayed.size(); z++){
			if (i == Displayed[z]){
				Skip = true;
				break;
			}
		}

		if (Skip){
			continue;
		}

			// If an error should be displayed.
		bool Error = false;

			// Check all of the elements after i.
		for (unsigned int g = i + 1; g < name.size(); g++){
			if (name[i] == name[g]){

					// Add the state to the already displayed list to prevent it from being checked.
				Displayed.push_back(g);

					// Set the definition to invalid.
				valid = false;

					// Set it to display an error.
				Error = true;
			}
		}

			// Display an error to the user.
		if (Error){
			cout << "Error: Final states must be unique but '" << name[i] << "' is not a unique state.\n";
		}
	}
	
	for (unsigned int i = 0; i < name.size(); i++){
		if(!states.is_element(name[i])){
			cout << "Error: Final states '" << name[i] << "' is not in the list of states.\n";
			valid = false;
		}
	}
	
	
	
	
	
	
}

	/* Name: is_element
	* Purpose:  This method is used to check if a state is a final state. 
	* Operation: Compares the value of the argument against all of the final state looking for a match.
	*/
bool Final_States::is_element(string value){

		// Search all of the final states.
	for (unsigned int i = 0; i < name.size(); i++){
		if (name[i] == value){
			return true;
		}
	}

	return false;
}
