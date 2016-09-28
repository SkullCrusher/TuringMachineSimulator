/*
	Module: UpperCase 
	File: Uppercase.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: Converts a string to a uppercase string.
*/

#ifndef UpperCase_H
#define UpperCase_H

#include <string>
#include <iostream>

#include <stdio.h>
#include <ctype.h>

using namespace std;

/* Name: UpperCase
* Purpose: Converts a string to a uppercase string.
* Operation: Calls toupper on each character of the string.
*/
static string UpperCase(string value) {
	for (unsigned int i = 0; i < value.size(); i++){
			// Convert to upper case.
		value[i] = toupper(value[i]);
	}

	return value;
}
#endif
