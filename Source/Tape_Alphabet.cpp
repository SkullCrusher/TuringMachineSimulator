/*
	Module: Tape_Alphabet
	File: Tape_Alphabet.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The list of characters that can be written to the type cells in Tape.
*/

#include "Tape_Alphabet.h"
#include "Uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

	/* Name: load
	* Purpose: This method is used to load new Tape_Alhpabet characters from a file.
	* Operation: This stops when a keyword is found or the end of the file is reached. 
		All errors will be displayed to the user. If there are any errors the function 
		will set valid to fail thereby rejecting the Turing Machine Definition file. 
	*/
void Tape_Alphabet::load(ifstream & definiton, bool & valid){

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
		if (UpperCase(Temp) == "TRANSITION_FUNCTION:"){
			Found_Keyword = true;
			break;
		}else{
				// Add the current tape character to the alphabet.
			if (Temp.size() == 1){
				Alphabet.push_back(Temp[0]);
			}else{
				valid = false;
				cout << "Error: Input character '" << Temp << "' longer than one.\n";
			}
		}
	}

	// Verify that the keyword was found, else error.
	if (!Found_Keyword){
		valid = false;
		cout << "Error: Unable to find the keyword 'TRANSITION_FUNCTION:' in the file.\n";
	}

	// Validate the tape alphabet.


		// Prevent duplicate error messages about any alphabet character.
	vector<int> Displayed;

		// Check that each tape alphabet character is different O(N^2). 
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
			cout << "Error: Tape alphabet must be unique but '" << Alphabet[i] << "' is not unique.\n";
		}
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
				cout << "Error: Tape alphabet character '" << Alphabet[i] << "' is reserved.\n";
			}else{
				cout << "Error: Tape alphabet character is not printable.\n";
			}
		}
		
	}

}

	/* Name: view
	* Purpose: To display the tape alphabet.
	* Operation: Prints out the values in the tape alphabet.
	*/
void Tape_Alphabet::view() const{

	// Print out the tape alphabet.
	cout << "Gamma = {";

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
	* Purpose: This method is used to check if the character is within the alphabet. 
	* Operation: Compares the argument to alphabet and returns if a match was found.
	*/
bool Tape_Alphabet::is_element(char value) const{

		// Check if the character is in the list.
	for (unsigned int i = 0; i < Alphabet.size(); i++){
		if (Alphabet[i] == value){
			return true;
		}
	}

	return false;
}
