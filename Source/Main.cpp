/*
	Module: Main
	File: Main.cpp
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016
	
	Description: The main entry point for the application. 
		It takes user command input and calls the correct commands.
*/

#include "Visable.h"
#include "Delete_Command.h"
#include "Exit_Command.h"
#include "Help_Command.h"
#include "Insert_Command.h"
#include "List_Command.h"
#include "Quit_Command.h"
#include "Run_Command.h"
#include "Set_Command.h"
#include "Show_Command.h"
#include "Truncate_Command.h"
#include "View_Command.h"
#include "Turing_Machine.h"

#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

/* Name: main
* Purpose: The entry point for the application.
* Operation: This function attempts to load the Turing Machine definition file named after 
	the user passed parameter. If the Turing Machine file is able to be loaded, and it is 
	valid, the function continues. If it was not able to be loaded, or it was invalid, an 
	error message is displayed, and the application terminates. Next, the function attempts 
	to load the input string file. On failure or success, the application continues to a 
	loops that prompts for a command from the user, and calls the correct function to handle it.
*/
int main(int argc, char** arg) {

	const int Success(0);
	const int Failure(-1);


		// Validate input.
	if (argc < 2 || argc > 3) {
		printf("Incorrect argument count.\n");

		return Failure;
	}

		// Turing machine class.
	Turing_Machine TM(arg[1]);

		// The amount of truncation to do.
	int Truncation = 32;

		// The number of transitions to do per run command.
	int Transition_Count = 1;

	bool Input_Strings_Changed = false;
	
		// The list of input string.
	vector<string> Input_Strings;

	if (TM.is_valid_definition() == false) {
		return -1;
	}
		
	printf("Successfully loaded TM.\n");

		// Attempt to load the input string list	
	string line;
	
	line += arg[1];
	line += ".STR";
	
	ifstream InputString_File (line.c_str());
	if (InputString_File.is_open()){		
		while ( getline (InputString_File,line) ){
		  
				// If the input string is the empty string just add it to the list.
			if(line == "\\"){
				Input_Strings.push_back("");
				continue;
			}
		  
				// Check the input string against the TM machine.			
			if(TM.is_valid_input_string(line)){
				// It is a valid input string.
				Input_Strings.push_back(line);
			}else{
				// it is not a valid input string.
				cout << "Warning: Input string '" << line << "' is not valid and was removed.\n"; 
				Input_Strings_Changed = true;
			} 
		}
		InputString_File.close();
	}

		// Print out the help guide.
	Help_Command();
	
		// The input string size before and after the command.
	int Temp_Size = 0;
	bool Quit = false;

	while (!Quit) {

		printf("Command: ");

		std::string Input_Str = "";
		std::getline(std::cin, Input_Str);

		if (Input_Str.size() > 1) {

			bool space = false;

			for (unsigned int i = 0; i < Input_Str.size(); i++) {
				if (Input_Str[i] == ' ') {
					space = true;
					break;
				}
			}

			if (space) {
				printf("Invalid command: Too many commands.\n");
				continue;
			}else {
				printf("Invalid command: Too many characters in the command.\n");
				continue;
			}
		}

		if (Input_Str.size() < 1) {
			continue;
		}

		switch (Input_Str[0]) {

				// E(x)it
			case 'x':
				if(Input_Strings_Changed){			
					Exit_Command(arg[1], Input_Strings);
				}
				return 0;
				break;

				// (D)elete
			case 'd':
				Temp_Size = Input_Strings.size();
				
				Delete_Command(Input_Strings, TM);
				
				if(Temp_Size != Input_Strings.size()){
					Input_Strings_Changed = true;					
				}
				
				break;

				// (H)elp 
			case 'h':
				Help_Command();
				break;

				// (L)ist
			case 'l':
				List_Command(Input_Strings);
				break;

				// (Q)uit
			case 'q':
				Quit_Command(TM);
				break;

			case 'i':
			
				Temp_Size = Input_Strings.size();
			
				Insert_Command(Input_Strings, TM);
				
				if(Temp_Size != Input_Strings.size()){
					Input_Strings_Changed = true;					
				}
				
				break;

				// (R)un
			case 'r':
				Run_Command(TM, Input_Strings, Truncation, Transition_Count);
				break;

				// S(e)t
			case 'e':
				Set_Command(Transition_Count);
				break;

				// Sho(w)
			case 'w':
				Show_Command(TM, arg[1], Transition_Count, Truncation);
				break;

				// (T)runcate
			case 't':
				Truncate_Command(Truncation);
				break;

				// (V)iew 
			case 'v':
				View_Command(TM);
				break;

			default:
				printf("Invalid command: Not a legal command.\n");
				break;
		}
	}

	return Success;
}
