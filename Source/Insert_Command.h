/*
	Module: Insert_Command
	File: Insert_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The class Insert_Command allows the user to enter a new input string. 
		The input string that will be  inserted can be used to run on the Turing Machine. 
		If the user wishes to specify the empty string they must enter the backslash 
		character. 
*/

#ifndef Insert_Command_H
#define Insert_Command_H

#include <iostream>
#include <vector>
#include <string>

#include "Turing_Machine.h"

using namespace std;

/* Name: Insert_Command
* Purpose: Allows the user to enter a new input string.
* Operation: This function will user input, and if the input is not empty, it will 
	validate the input against the current Turing_Machine. If the input is empty, 
	the function will return with no display or change in list. If the input is invalid 
	for the Turing Machine definition, an error is displayed and the function returns. 
	If the input is valid, the new input string is added to the end of the list. If the 
	user enters the backslash character will be replaced with an empty string before 
	validation occurs.
*/
void Insert_Command(vector<string> &list, const Turing_Machine &TM){

		// Storage to hold the user entered string.
	std::string New_String;
		
		// Ask for input from the user.
	cout << "Input string: ";
	getline(std::cin, New_String);

		// If the input is empty return without doing anything.
	if (New_String == ""){
		return;
	}

		// Prevent duplication in the list.
	for (unsigned int i = 0; i < list.size(); i++){
			// Check every string but the empty string.
		if (list[i] == New_String){
			cout << "Error: String '" << Visable(New_String) << "' is already in the list!\n";
			return;
		}

			// Check the empty string.
		if (New_String == "\\"){
			if (list[i] == ""){
				cout << "Error: String '" << New_String << "' is already in the list!\n";
				return;
			}
		}
	}


		// If the input string is the empty string.
	if (New_String == "\\"){

		list.push_back("");
		return;
	}

		// Validate the user entered string.
	if(TM.is_valid_input_string(New_String)){
		list.push_back(New_String);
		cout << "String '" << Visable(New_String) << "' inserted into list!\n";
	}else{
		cout << "Error: Invalid input string.\n";
	}
}

#endif
