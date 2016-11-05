/*
	Module: States
	File: States.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The possible states the Turing machine can be in at any given time.
*/
#include "stdafx.h"
#include "States.h"
#include "Uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

	/* Name: load
	* Purpose: Loads the states from a definition file.
	* Operation: This method is called by the Turing_Machine class that it is contained inside. 
		This method will attempt to load Turing Machine states from the file until when a keyword 
		is found or the end of the file is reached. All errors will be displayed to the user.
		If there are any errors the function will set valid to fail thereby rejecting the Turing 
		Machine Definition file. 
	*/
void States::load(ifstream & definiton, bool & valid)
{
		// If the keyword the parser was looking for was found.
	bool Found_Keyword = false;

		// Attempt to load the list of states from the definition file.
	for (;;){
		std::string Temp;

			// Load the next character set.
		definiton >> Temp;

			// If that was the end of the file break.
		if (definiton.eof()){ break; }

			// Look for the keyword to trigger the switch to the next section.
		if (UpperCase(Temp) == "INPUT_ALPHABET:"){
			Found_Keyword = true;
			break;
		}else{
				// Add the current to the list of states.
			Names.push_back(Temp);
		}
	}

		// Verify that the keyword was found, else error.
	if (!Found_Keyword){
		cout << "Error: Unable to find the keyword 'INPUT_ALPHABET:' in the file.\n";

		valid = false;
	}
	
	// Validate the list of states.
	
		// Prevent duplicate error messages about any final state.
	vector<int> Displayed;

		// Check that each final state is different O(N^2). 
	for (unsigned int i = 0; i < Names.size(); i++){

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
		for (unsigned int g = i + 1; g < Names.size(); g++){
			if (Names[i] == Names[g]){

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
			cout << "Error: States must be unique but '" << Names[i] << "' is not a unique state.\n";
		}
	}
	
	// Validate the states do not contain invalid characters.
	
		// To prevent multiple of the same error from being displayed.
	vector<string> DisplayedCharacters;

		// Check for any invalid characters in all of the states.		
	for (unsigned int i = 0; i < Names.size(); i++){

		bool Skip = false;

			// Check if the error was displayed before.
		for (unsigned int z = 0; z < DisplayedCharacters.size(); z++){
			if (Names[i] == DisplayedCharacters[z]){
				Skip = true;
			}
		}

		if (Skip){ continue; }
	
		for(int z = 0; z < Names[i].size(); z++){		

				// Check it is printable and does not contain '\', '[', ']', '>', '<'.
			if (Names[i][z] < '!'
				|| Names[i][z] > '~'
				|| Names[i][z] == '\\'
				|| Names[i][z] == '['
				|| Names[i][z] == ']'
				|| Names[i][z] == '>'
				|| Names[i][z] == '<'){

				valid = false;

				// Block the display of this error again.
				DisplayedCharacters.push_back(Names[i]);

				// Print the invalid character if it is printable.
				if (Names[i][z] >= '!' && Names[i][z] <= '~'){
					cout << "Error: State contains character '" << Names[i] << "' that is reserved.\n";
				}else{
					cout << "Error: State contains a character that is not printable.\n";
				}
			}
		}
	}
	
	
	
}

	/* Name: view
	* Purpose: This method is used to display the current states that are attributes 
		of the current class instance of States.
	* Operation: Prints out the values in Names.
	*/
void States::view() const{
	
	cout << "Q = {";

	for (unsigned int i = 0; i < Names.size(); i++){
		if (i == 0){
			cout << Names[i];
		}else{
			cout << ", " << Names[i];
		}
	}

	cout << "}\n\n";
}

	/* Name: is_element
	* Purpose: This method is used to check if a state is contained in the current class instance of State.
	* Operation: Searchs Names and returns if a match was found.
	*/
bool States::is_element(string value){

		// Attempt to find the string inside the list of states.
	for (unsigned int i = 0; i < Names.size(); i++){
		if (Names[i] == value){
			return true;
		}
	}

	return false;
}
