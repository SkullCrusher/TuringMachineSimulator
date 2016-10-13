/*
	Module: Delete_Command
	File: Delete_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class Delete_Command is used to remove input strings from the input string list.
*/

#ifndef Delete_Command_H
#define Delete_Command_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Turing_Machine.h"

using namespace std;

/* Name: Delete_Command
* Purpose: Allows the user to delete a input string from the list.
* Operation: This function prompts for the user to enter a valid input string index number. If the user 
	enters nothing, the function returns without a message. If the user enters a number that is not 
	above zero, or that is not a integer, an error is displayed and the function returns. If the user 
	enters a valid input string, index it is deleted, a message is displayed, and the function returns.
*/
void Delete_Command(vector<string> &list, Turing_Machine &TM) {

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

	}catch (const std::out_of_range& oor) {
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

		// Remove the string from the list.
	list.erase(list.begin() + Input_String_Index);

	cout << "Input string was removed from the list.\n";
}

#endif
