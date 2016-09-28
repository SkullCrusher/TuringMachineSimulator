/*
	Module: Set_Command
	File: Set_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This Set_Command is used to change the maximum number of 
		transitions for the Turing_Machine to perform before the operation pauses.
*/

#ifndef Set_Command_H
#define Set_Command_H

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/* Name: Set_Command
* Purpose: Allows the user to change the maximum number of transitions.
* Operation: This function displays the current setting of the maximum transitions and waits for user input. 
	If the user enters nothing, the function returns without changing the setting or displaying a message. 
	If the user does not enter a number greater than 0, and that is a integer, an error is displayed, and 
	the function returns. If the input is valid, the maximum transitions is changed, a message is displayed, 
	and the function returns.
*/
void Set_Command(int &Transition_Max) {

	std::string New_String;

		// Ask for input from the user.
	cout << "Maximum number of transitions [" << Transition_Max << "]: ";
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
		cout << "Error: Transition max is too large.\n";
		return;
	}

	// Validate the size they input.
	if (New_Limit < 0){
		cout << "Error: The transition max must be positive.\n";
		return;
	}

	// Set the new limit.
	Transition_Max = New_Limit;

	cout << "Number of transitions changed to " << Transition_Max << ".\n";
}

#endif
