/*
	Module: Final_States
	File: Final_States.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: he state that if the Turing Machine transitions into cannot leave, 
		the Input String is accepted, and the class Turing_machine sets operating to false.
*/

#ifndef Final_States_H
#define Final_States_H

#include "Final_States.h"
#include "Uppercase.h"
#include "States.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Final_States{

private:
		// This attribute contains all of the states that are considered final states. 
		// All of the Final_States must be contained in the class States as well.
	vector<string> name;

public:
	
	/* Name: load
	* Purpose: This method is called to load new final states into the class Final_States.
	* Operation: This stops when a keyword is found or the end of the file is reached. 
		All errors will be displayed to the user. If there are any errors the function 
		will set valid to fail thereby rejecting the Turing Machine Definition file. 
	*/
	void load(ifstream& definiton, bool& valid);

	/* Name: view
	* Purpose: This method is used to display all of the current final states in a formatting 
		of the formal definition of the Turing Machine class.
	* Operation: Prints out all of the values in name.
	*/
	void view() const;

	/* Name: validate
	* Purpose: This method is used validate that the final states are correct.
	* Operation: Checks that each of the final states that to see if it is
		contained within states and it does not contain invalid characters.
	*/
	void validate(States &states, bool & valid);

	/* Name: is_element
	* Purpose:  This method is used to check if a state is a final state. 
	* Operation: Compares the value of the argument against all of the final state looking for a match.
	*/
	bool is_element(string value);

};
#endif
