/*
	Module: States
	File: States.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The possible states the Turing machine can be in at any given time.
*/

#ifndef States_H
#define States_H

#include "States.h"
#include "Uppercase.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class States{

private:
		// This attribute contains all of the state names. 
		// They are loaded from a Turing Machine definition file and validated while they are loaded.
	std::vector<string> Names;

public:
	/* Name: load
	* Purpose: Loads the states from a definition file.
	* Operation: This method is called by the Turing_Machine class that it is contained inside. 
		This method will attempt to load Turing Machine states from the file until when a keyword 
		is found or the end of the file is reached. All errors will be displayed to the user.
		If there are any errors the function will set valid to fail thereby rejecting the Turing 
		Machine Definition file. 
	*/
	void load(ifstream& definiton, bool& valid);

	/* Name: view
	* Purpose: This method is used to display the current states that are attributes 
		of the current class instance of States.
	* Operation: Prints out the values in Names.
	*/
	void view() const;

	/* Name: is_element
	* Purpose: This method is used to check if a state is contained in the current class instance of State.
	* Operation: Searchs Names and returns if a match was found.
	*/
	bool is_element(string value);

};
#endif
