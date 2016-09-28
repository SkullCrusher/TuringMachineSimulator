/*
	Module: File_Out
	File: File_Out.h
	Application: Turing Machine Application
	Language: GNU C++
	Computer: Dell - Optiplex 990
	Operating system: Ubuntu 14.04.4 LTS
	Course: CPT_S 322
	Author: David Harkins
	Date: 4/30/2016

	Description: This class File_Out is used to offload the input string list 
		when the application is closing. The file will only be written out to disk 
		if there were changes made to the file (Invalid input string was removed, 
		the user added a string, or user deleted a string). 
*/

#ifndef File_Out_H
#define File_Out_H

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/* Name: File_Out
* Purpose: Used to save the changed input string list to file.
* Operation: This function saves the entire input string list a file named after 
	the parameter TM_Name. This will overwrite the original input string list if it 
	exists, or will create a new one if it does not. If it is unable to save the 
	input string file to disk, an error will be displayed, and the application will 
	terminate. If the function was able to save the file to disk, a message is 
	displayed and the application terminates.    
*/
void File_Out(string TM_Name, vector<string> List) {

		// Attach the .STR
	string Definition_File_Name = TM_Name + ".STR";
	

		// Attempt to open the file we will dump to.
	ofstream file(Definition_File_Name.c_str(), ios::trunc | ios::out);

	bool First = true;
	
		// Check if the file was able to be opened.
	if (file.is_open()){
		for (unsigned int i = 0; i < List.size(); i++){
			
				// Don't add newlines until required.
			if(First){
				First = false;
				file << List[i];
			}else{
				file << "\n" << List[i];
			}	
					
		}

		file.close();
			// Display a success message.
		cout << "Input string file successfully saved to disc.\n";
	}else{
			// Display a error message.
		cout << "Unable to save the input strings to file.\n";
	}
}

#endif
