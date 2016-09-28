/*
	Module: Exit_Command
	File: Exit_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: Saves the input string list when the application closes.
*/

#ifndef Exit_Command_H
#define Exit_Command_H

#include <iostream>
#include "File_Out.h"

using namespace std;

/* Name: Exit_Command
* Purpose: To save the input string list.
* Operation: It calls File_Out.
*/
void Exit_Command(string TM_Name, vector<string> List) {
	File_Out(TM_Name, List);
}

#endif
