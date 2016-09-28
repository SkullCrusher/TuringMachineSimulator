/*
	Module: Help_Command
	File: Help_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class Help_Command displays the usage to the user. 
		This displays all of the valid commands for the users to use and 
		a short description of each.	
*/

#ifndef Help_Command_H
#define Help_Command_H

#include <iostream>

using namespace std;

/* Name: Help_Command
* Purpose: The Help_Command displays the usage to the user.
* Operation: Prints out a static usage to the user.
*/
void Help_Command() {

	cout << "(D)elete   - Delete input string from list.\n";
	cout << "E(x)it     - Exit application.\n";
	cout << "(H)elp     - Help user.\n";
	cout << "(I)nsert   - Insert input string into list.\n";
	cout << "(L)ist     - List input strings.\n";
	cout << "(Q)uit     - Quit operation of Turing machine on input string.\n";
	cout << "(R)un      - Run Turing machine on input string.\n";
	cout << "S(e)t      - Set maximum number of transitions to perform.\n";
	cout << "Sho(w)     - Show status of application.\n";
	cout << "(T)runcate - Truncate instantaneous description.\n";
	cout << "(V)iew     - View Turing machine.\n";
}

#endif
