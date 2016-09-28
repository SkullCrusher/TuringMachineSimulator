/*
	Module: Crash
	File: crash.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: Crash is used to send the message to halt the Turing machine
		to the caller of a function.
*/

#include "crash.h"

#include <stdexcept>
#include <string>

using namespace std;

/* Name: crash
* Purpose: To crash the operation of the Turing Machine and 
	trigger the state to be rejected.
* Operation: The crash accepts a message and is caught by the 
	Turing Machine which can read the message.
*/
crash::crash(string reason) : runtime_error(reason.c_str()){ }
