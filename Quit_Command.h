/*
	Module: Quit_Command
	File: Quit_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: When the Turing machine class is currently running on a input string the class the Quit_Command 
		will terminate the running on the input string. The Turing machine will neither accept or reject the input 
		string is the Quit_Command is used. If the command is used, and the Turing machine is not running on a input 
		string, a error will be displayed, and Quit_Command will return. 
*/

#ifndef Quit_Command_H
#define Quit_Command_H

#include <iostream>
#include "Turing_Machine.h"

using namespace std;

/* Name: Quit_Command
* Purpose: The Quit_Command function will terminate the running of a Turing machine on a input string. 
* Operation: If there is no input string running or the Turing machine has accepted, rejected, or 
	never been used before an error will be displayed and the function will return.
*/
void Quit_Command(Turing_Machine &TM) {

		// Check that the Turing machine is currently running.
	if (!TM.is_operating()){
		cout << "Error: Unable to stop, Turing Machine not running.\n";
		return;
	}

		// Stop the operation.
	TM.terminate_operation();

	cout << "Input string " << Visable(TM.input_string()) << " was not accepted or rejected in " << TM.total_number_of_transitions() << " transitions.\n";
}

#endif
