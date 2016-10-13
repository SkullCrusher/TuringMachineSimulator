/*
	Module: Show_Command
	File: Show_Command.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: The show command lists the status of the program and Turing machine. 
		The information displayed is based on user settings and the current status of 
		the Turing Machine. The differences in the Turing machine status are: it has 
		run before; is currently running; or was accepted; rejected or the user 
		terminated it.
*/

#ifndef Show_Command_H
#define Show_Command_H

#include <iostream>

#include "Turing_Machine.h"
#include "Visable.h"

using namespace std;

/* Name: Show_Command
* Purpose: The show command lists the status of the program and Turing machine.
* Operation: The function Show_Command() displays the status of the Turing Machine. 
	The elements that are listed are the course name, semester, year, instructor, author, 
	version number, max transitions, max cells to the left and right, the name of the 
	Turing Machine file, and the Turing machine status. If the Turing machine has never 
	been run before, a message is displayed to that effect. If the Turing machine is 
	currently running, the input string it is running on is displayed as well as the number 
	of transitions already preformed. If the Turing Machine has accepted, rejected, or the
	user has terminated operation, the number of transitions and reason the operation was
	stopped are displayed.  
*/
void Show_Command(Turing_Machine &TM, string TM_NAME, int Transition_Count, int Truncation) {
	cout << "Course name: CPT_S 322\n";
	cout << "Semester: Spring\n";
	cout << "Year: 2016\n\n";

	cout << "Instructor: Neil Corrigan\n";
	cout << "Author: David Harkins\n\n";

	cout << "Version number: 3\n";

	cout << "Max transitions: " << Transition_Count << "\n";
	cout << "Max cells to left and right: " << Truncation << "\n\n";
	cout << "Name of TM: " << TM_NAME << "\n";

		// Case 1: Turing machine has never been used.
	if (!TM.is_used()){
		cout << "TM Status: Has not run.\n";

		return;
	}

		// Case 2: Turing machine is in operation.
	if (TM.is_operating()){
		cout << "TM Status: Running.\nCurrently running on the input string " << Visable(TM.input_string()) << " for " << TM.total_number_of_transitions() << " transitions.\n";

		return;
	}
		// Case 3: Turing machine is accepted, rejected, or was stopped by the user.
	if (!TM.is_operating()){
		cout << "TM Status: Completed. \nThe input string " << Visable(TM.input_string()) << " was ";
		
			// Which case is true about the Turing machine.
		if (TM.is_accepted_input_string()){
			cout << "accepted";
		}else if (TM.is_rejected_input_string()){
			cout << "rejected";
		}else{
			cout << "not accepted or rejected";
		}

		cout << " in " << TM.total_number_of_transitions() << " transitions.\n";
	}
}


#endif
