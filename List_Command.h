/*
	Module: List_Command
	File: List_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class List_Command displays the current list of input 
		strings to the user. If there are no input strings a message will be 
		displayed saying such.
*/

#ifndef List_Command_H
#define List_Command_H

#include <iostream>
#include <vector>
#include <string>

#include "Visable.h"

using namespace std;

/* Name: List_Command
* Purpose: Displays the list of input strings.
* Operation: This function displays each input string on its own line with 
	its input string index before it, and the function returns. If there 
	are no input strings a message is displayed saying such and the function 
	returns.
*/
void List_Command(vector<string> &list) {

		// Handle special case that the list is empty.
	if (list.size() == 0){
		cout << "There are no input strings.\n";
		return;
	}

		// List all of the input strings.
	for (unsigned int i = 0; i < list.size(); i++){
		cout << (i + 1) << ". " << Visable(list[i]) << "\n";
	}
}

#endif
