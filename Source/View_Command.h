/*
	Module: View_Command
	File: View_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The View_Command displays the Turing machine definition file that is contained
		inside of a Turing machine. Before the function can be called, the program has validated 
		that the Turing machine definition is valid.
*/

#ifndef View_Command_H
#define View_Command_H

#include "Turing_Machine.h"

/* Name: View_Command
* Purpose: This function prints the currently stored Turing Machine definition from a Turing machine.   
* Operation: Calls the print function on the Turing_Machine.
*/
void View_Command(Turing_Machine &TM) {
	TM.view_definiton();
}

#endif
