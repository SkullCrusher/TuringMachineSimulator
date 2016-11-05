/*
	Module: Truncate_Command
	File: Truncate_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The Truncate_Command gets user input and updates the truncation setting. 
		The value that the user enters must be an integer and greater than zero, if it is
		not an error, is displayed and the function returns without changing the setting. 
*/

#ifndef Truncate_Command_H
#define Truncate_Command_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/* Name: Truncate_Command
* Purpose: This function gets user input and updates the truncation setting.
* Operation: The value of the user input must be a integer and greater than zero. If it is
	not, an error message is displayed and the function returns without changing the setting. 
	If the user enters nothing, the function returns without changing the setting or displaying
	any message. If the user enters a value that is greater than zero, the value is changed
	and a message is displayed.
*/
void Truncate_Command(int &Limit) {

	std::string New_String;

	// Ask for input from the user.
	cout << "Maximum number of cells [" << Limit << "]: ";
	getline(std::cin, New_String);

		// Validate that the input is only from 0-9 characters.
	for (unsigned int i = 0; i < New_String.size(); i++){
		if (New_String[i] > '9' || New_String[i] < '0'){
			cout << "Error: A non-numerical input entered.\n";
			return;
		}
	}

	int New_Limit = 0;

		// Prevent buffer overflows when a large number is provided with the try block.
	try {
			// Convert the input to be a int.
		//New_Limit = std::stoi(New_String);
		New_Limit = atoi(New_String.c_str());

	}catch (const std::out_of_range& oor) {
		cout << "Error: Truncation limit is too large.\n";
		return;
	}

		// Validate the size they input.
	if (New_Limit < 0){
		cout << "Error: The limit must be positive.\n";
		return;
	}

		// Set the new limit.
	Limit = New_Limit;

	cout << "Setting changed to " << Limit << ".\n";
}

#endif
