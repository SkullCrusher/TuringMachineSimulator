/*
	Module: Input_Alphabet
	File: Input_Alphabet.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: Holds the alphabet for the input strings.
*/
#include "stdafx.h"
#include "Input_Alphabet.h"
#include "Uppercase.h"
#include "Tape_Alphabet.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

	/* Name: load
	* Purpose:  This function attempts to load the Input_Alphabet from the File.
	* Operation: If there is a failure on reading or parsing the file, the function 
		will set valid to false, display the error, and return. If the function 
		is able to read and parse the file, the function will return.
	*/
void Input_Alphabet::load(ifstream& definiton, bool& valid){

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
		if (UpperCase(Temp) == "TAPE_ALPHABET:"){
			Found_Keyword = true;
			break;
		}else{
				// Add the current input character to the alphabet.
			if (Temp.size() == 1){
				Alphabet.push_back(Temp[0]);
			}else{
				cout << "Error: Tape character '" << Temp << "' longer than one.\n";

				valid = false;
			}
		}
	}

		// Verify that the keyword was found, else error.
	if (!Found_Keyword){
		cout << "Error: Unable to find the keyword 'TAPE_ALPHABET:' in the file.\n";

		valid = false;
	}
	
		// To prevent multiple of the same error from being displayed.
	vector<char> DisplayedCharacters;

		// Check for any input alphabet character that is valid the tape alphabet.		
	for (unsigned int i = 0; i < Alphabet.size(); i++){

		bool Skip = false;

			// Check if the error was displayed before.
		for (unsigned int z = 0; z < DisplayedCharacters.size(); z++){
			if (Alphabet[i] == DisplayedCharacters[z]){
				Skip = true;
			}
		}

		if (Skip){
			continue;
		}

			// Check it is printable and does not contain '\', '[', ']', '>', '<'.
		if (Alphabet[i] < '!'
			|| Alphabet[i] > '~'
			|| Alphabet[i] == '\\'
			|| Alphabet[i] == '['
			|| Alphabet[i] == ']'
			|| Alphabet[i] == '>'
			|| Alphabet[i] == '<'){

			valid = false;

				// Block the display of this error again.
			DisplayedCharacters.push_back(Alphabet[i]);

				// Print the invalid character if it is printable.
			if (Alphabet[i] >= '!' && Alphabet[i] <= '~'){
				cout << "Error: Input alphabet character '" << Alphabet[i] << "' is reserved.\n";
			}else{
				cout << "Error: Input alphabet character is not printable.\n";
			}
		}
		
	}
	
	
}

	/* Name: view
	* Purpose: This function displays the contents of Alphabet.
	* Operation: Prints out the characters in Alphabet.
	*/
void Input_Alphabet::view() const{

	cout << "Sigma = {";

	for (unsigned int i = 0; i < Alphabet.size(); i++){
		if (i == 0){
			cout << Alphabet[i];
		}else{
			cout << ", " << Alphabet[i];
		}
	}

	cout << "}\n\n";
}

	/* Name: is_element
	* Purpose: This function checks if the parameters character is contained within Alphabet.
	* Operation: Compares the argument with every character in alphabet to find a match.
	*/
bool Input_Alphabet::is_element(char value) const{

		// Check if the argument is in the alphabet.
	for (unsigned int i = 0; i < Alphabet.size(); i++){
		if (Alphabet[i] == value){
			return true;
		}
	}

	return false;
}

	/* Name: validate
	* Purpose: To determine if the loaded alphabet is valid.
	* Operation: This function compares the elements loaded from the Turing Machine definition 
		file to the ones in Tape_Alphabet.
	*/
void Input_Alphabet::validate(Tape_Alphabet tape_alphabet, bool & valid){

	// Prevent duplicate error messages about any alphabet character.
	vector<int> Displayed;

	// Check that each input alphabet character is different O(N^2). 
	for (unsigned int i = 0; i < Alphabet.size(); i++){

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
		for (unsigned int g = i + 1; g < Alphabet.size(); g++){
			if (Alphabet[i] == Alphabet[g]){

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
			cout << "Error: Input alphabet must be unique but '" << Alphabet[i] << "' is not unique.\n";
		}
	}

	// To prevent multiple of the same error from being displayed.
	vector<char> DisplayedCharacters;

	// Check for any input alphabet character that is valid/n the tape alphabet.		
	for (unsigned int i = 0; i < Alphabet.size(); i++){

		bool Skip = false;

		// Check if the error was displayed before.
		for (unsigned int z = 0; z < DisplayedCharacters.size(); z++){
			if (Alphabet[i] == DisplayedCharacters[z]){
				Skip = true;
			}
		}

		if (Skip){
			continue;
		}



		// Check it is printable and does not contain '\', '[', ']', '>', '<'.
		if (Alphabet[i] < '!'
			|| Alphabet[i] > '~'
			|| Alphabet[i] == '\\'
			|| Alphabet[i] == '['
			|| Alphabet[i] == ']'
			|| Alphabet[i] == '>'
			|| Alphabet[i] == '<'){

			valid = false;

			// Block the display of this error again.
			DisplayedCharacters.push_back(Alphabet[i]);

			// Print the invalid character if it is printable.
			if (Alphabet[i] >= '!' && Alphabet[i] <= '~'){
				cout << "Error: Input alphabet character '" << Alphabet[i] << "' is reserved.\n";
			}
			else{
				cout << "Error: Input alphabet character is not printable.\n";
			}
		}else if (tape_alphabet.is_element(Alphabet[i]) == false){
			// Check if it is not in the the tape alphabet.
			valid = false;

			cout << "Error: Input alphabet character '" << Alphabet[i] << "' is not in the tape alphabet.\n";
		}
	}

}
