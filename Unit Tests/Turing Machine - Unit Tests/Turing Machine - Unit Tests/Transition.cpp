/*
	Module: Transition
	File: Transition.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class is designed to hold a single Turing Machine definition transition.
		All other classes that want to use it must access it by using the class Transition_Function.
*/

#include "stdafx.h"
#include "Transition.h"

#include <string>

using namespace std;

	/* Name: Transition
	* Purpose: To create and load a new Transition object.
	* Operation: The local values are set to the argument values.
	*/
Transition::Transition(string source_state, char read_character, string destination_state, char write_character, Direction move_direction){
	Source = source_state;
	Read = read_character;
	Destination = destination_state;
	Write = write_character;
	Move = move_direction;
}

	/* Name: Source_State
	* Purpose: This method is used to get the current value of Source attribute that is contained in the class Transition.
	* Operation: Returns source.
	*/
string Transition::Source_State() const{
	return Source;
}

	/* Name: Read_Character
	* Purpose: This method is used to get the current value of Read attribute that is contained in the class Transition.
	* Operation: Returns read.
	*/
char Transition::Read_Character() const{
	return Read;
}

	/* Name: Destination_State
	* Purpose: This method is used to get the current value of State attribute that is contained in the class Transition
	* Operation: Returns destination.
	*/
string Transition::Destination_State() const{
	return Destination;
}

	/* Name: Write_Character
	* Purpose: This method is used to get the current value of write attribute that is contained in the class Transition
	* Operation: Returns write.
	*/
char Transition::Write_Character() const{
	return Write;
}

	/* Name: Move_Direction
	* Purpose: This method is used to get the current value of Direction attribute that is contained in the class Transition.
	* Operation: Returns Move.
	*/
Direction Transition::Move_Direction() const{
	return Move;
}

	/* Name: load
	* Purpose: This method is used to load a Transition from the Turing Machine definition file. 
	* Operation: This not currently used because it is handled by Transition function.
		It is kept for future changes in implementation.
	*/
void Transition::load(ifstream & definiton, bool & valid){}
