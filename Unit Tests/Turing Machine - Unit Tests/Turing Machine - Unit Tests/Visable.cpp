/*
	Module: Visable
	File: Visable.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: Makes the empty string printable.
*/
#include "stdafx.h"
#include "Visable.h"

#include <string>

using namespace std;

/* Name: Visable
* Purpose: Makes the empty string printable.
* Operation: Changes the empty string to "\"
*/
string Visable(string value) {

	const string lambda("\\");

	if (value.empty()) {
		value = lambda;
	}

	return value;
}
