#include <iostream>
#include <stdio.h>
#include <string>

// Change w to TM status: completed, never be run, currently running. (move current string down)


void Command_Help() {

	printf("(D)elete   - Delete input string from list.\n"); 
	printf("E(x)it     - Exit application.\n"); 
	printf("(H)elp     - Help user.\n"); 
	printf("(I)nsert   - Insert input string into list.\n"); 
	printf("(L)ist     - List input strings.\n"); 
	printf("(Q)uit     - Quit operation of Turing machine on input string.\n"); 
	printf("(R)un      - Run Turing machine on input string.\n"); 
	printf("S(e)t      - Set maximum number of transitions to perform.\n"); 
	printf("Sho(w)     - Show status of application.\n");
	printf("(T)runcate - Truncate instantaneous description.\n"); 
	printf("(V)iew     - View Turing machine.\n"); 
}

void Command_View() {

	printf("This Turing machine accepts the language of one or more a's followed by the same number of b's.\n\n");

	printf("Q = {s0, s1, s2, s4}\n\n");
	
	printf("Sigma = {a, b}\n\n");

	printf("Gamma = {a, b, X, Y, -}\n\n");

	printf("Delta(s0, a) = (s1, X, R)\n");
	printf("Delta(s0, Y) = (s3, Y, R)\n");
	printf("Delta(s1, a) = (s1, a, R)\n");
	printf("Delta(s1, b) = (s2, Y, R)\n");
	printf("Delta(s1, Y) = (s1, Y, R)\n");
	printf("Delta(s2, a) = (s2, a, R)\n");
	printf("Delta(s2, X) = (s0, X, R)\n");
	printf("Delta(s2, Y) = (s2, Y, R)\n");
	printf("Delta(s3, Y) = (s3, Y, R)\n");
	printf("Delta(s3, -) = (s4, -, R)\n\n");

	printf("Q0 = s0\n\n");

	printf("B = -\n\n");

	printf("F = {s4}\n\n");
}

void Command_List() {
	printf("1. a\n");
	printf("2. ab\n");
	printf("3. \\\n");
	printf("4. aaabb\n");
	printf("5. aaaaaaaaaaabbbbbbbbbb\n");
	printf("6. aabb\n");
	printf("7. aaaaaabbbbbbb\n");
	printf("8. ba\n");
	printf("9. aba\n");
	printf("10. bb\n");
}

void Command_Insert() {
	printf("Input string: abbb\n");
	printf("String inserted into list!\n");
}

void Command_Delete() {
	printf("Input string number: 1\n");
	printf("String deleted!\n");
}

void Command_Set() {
	printf("Maximum number of transitions [1]: 20\n");
	printf("Number of transitions changed to 20.\n");
}

void Command_Truncate() {
	printf("Maximum number of cells [32]: 10\n");
	printf("Setting changed!\n");
}

void Command_Run() {
	printf("Input string number: 1\n");
	printf("0. [s0]aaabb\n");
	printf("7. XXXXY-[s4]\n");
	printf("Input string aaabb was accepted in 7 transitions.\n");
}

void Command_Quit() {
	printf("Input string aaabb was not accepted or rejected in 112 transitions.\n");
}

void Command_Exit() {
	printf("Input string file successfully saved to disc.\n");
}

void Command_Show() {
	printf("Course name: CPT_S 322\n");
	printf("Semester: Spring\n");
	printf("Year: 2016\n\n");

	printf("Instructor: Neil Corrigan\n");
	printf("Author: David Harkins\n\n");

	printf("Version number: 1\n");
	printf("Max transitions: 10\n");
	printf("Max cells to left and right: 10\n");
	printf("Name of TM: A\n");
	printf("TM Status: Completed\nThe input string aaabb has been accepted in 7 transitions.\n");
}

int main() {
	printf("Successfully loaded TM.\n");

	bool Quit = false;

	while (!Quit) {
				
		printf("Command: ");

		std::string Input_Str = "";
		std::getline (std::cin, Input_Str);

		if(Input_Str.size() > 1){
		  
			bool space = false;

		  	for(int i = 0 ; i < Input_Str.size(); i++){
				if(Input_Str[i] == ' '){
					space = true;
					break;		
				}
		  	}
		
			if(space){
				printf("Invalid command: Too many commands.\n");
				continue;
			}else{
				printf("Invalid command: Too many characters in the command.\n");	
				continue;
			}	
		}

		if(Input_Str.size() < 1){
			continue;
		}

		switch (Input_Str[0]) {

				// E(x)it
			case 'x':
				Command_Exit();
				return 0;
				break;

				// (D)elete
			case 'd':
				Command_Delete();
				break;

				// (H)elp 
			case 'h':
				Command_Help();
				break;

				// (L)ist
			case 'l':
				Command_List();
				break;

				// (Q)uit
			case 'q':
				Command_Quit();
				break;

			case 'i':
				Command_Insert();
				break;

				// (R)un
			case 'r':
				Command_Run();
				break;

				// S(e)t
			case 'e':
				Command_Set();
				break;

				// Sho(w)
			case 'w':
				Command_Show();
				break;

				// (T)runcate
			case 't':
				Command_Truncate();
				break;

				// (V)iew 
			case 'v':
				Command_View();
				break;


			default:
				printf("Invalid command: Not a legal command.\n");
			break;
		}
	}

	return 0;
}
