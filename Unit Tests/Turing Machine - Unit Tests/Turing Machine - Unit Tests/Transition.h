/*
	Module: Transition
	File: Transition.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class is designed to hold a single Turing Machine definition transition.
		All other classes that want to use it must access it by using the class Transition\_Function.
*/

#ifndef Transition_H
#define Transition_H

#include "Direction.h"

#include <string>

using namespace std;

class Transition{

private:
		// This attribute contains the name of the current state that the Turing machine must be in to use this transition.
	string Source;

		// This attribute contains the name of the state that is currently the current tape cell.
	char Read;

		// This attribute contains the name of the state that the Turing Machine will transfer to if it uses this transition.
	string Destination;

		// This attribute contains the character that will be written to the class Tape where the Turing Machine is currently pointing. 
		// This happens before the transition moves the current\_cell that is contained in the class Tape.
	char Write;

		// This attribute contains the direction that the tape head will move after the character is 
		// written to the class Tape. It can only be to the right or to the left.
	Direction Move;

public:
	/* Name: Transition
	* Purpose: To create and load a new Transition object.
	* Operation: The local values are set to the argument values.
	*/
	Transition(string source_state, char read_character, string destination_state, char write_character, Direction move_direction);

	/* Name: Source_State
	* Purpose: This method is used to get the current value of Source attribute that is contained in the class Transition.
	* Operation: Returns source.
	*/
	string Source_State() const;

	/* Name: Read_Character
	* Purpose: This method is used to get the current value of Read attribute that is contained in the class Transition.
	* Operation: Returns read.
	*/
	char Read_Character() const;

	/* Name: Destination_State
	* Purpose: This method is used to get the current value of State attribute that is contained in the class Transition
	* Operation: Returns destination.
	*/
	string Destination_State() const;

	/* Name: Write_Character
	* Purpose: This method is used to get the current value of write attribute that is contained in the class Transition
	* Operation: Returns write.
	*/
	char Write_Character() const;

	/* Name: Move_Direction
	* Purpose: This method is used to get the current value of Direction attribute that is contained in the class Transition.
	* Operation: Returns Move.
	*/
	Direction Move_Direction() const;

	/* Name: load
	* Purpose: This method is used to load a Transition from the Turing Machine definition file. 
	* Operation: This not currently used because it is handled by Transition function.
		It is kept for future changes in implementation.
	*/
	void load(ifstream& definiton, bool& valid);
};


#endif
