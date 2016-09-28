
default: crash.o Final_States.o Main.o States.o Input_Alphabet.o Tape_Alphabet.o Tape.o Transition_Function.o Transition.o Turing_Machine.o Visable.o
	g++ -g -o TM crash.o Final_States.o Main.o States.o Input_Alphabet.o Tape_Alphabet.o Tape.o Transition_Function.o Transition.o Turing_Machine.o Visable.o

crash.o:
	g++ -g -c crash.cpp
	
Visable.o:
	g++ -g -c Visable.cpp
	
Turing_Machine.o:
	g++ -g -c Turing_Machine.cpp

Transition_Function.o:
	g++ -g -c Transition_Function.cpp
	
Transition.o:
	g++ -g -c Transition.cpp
	
Tape_Alphabet.o:
	g++ -g -c Tape_Alphabet.cpp
	
Tape.o:
	g++ -g -c Tape.cpp	
	
Final_States.o:
	g++ -g -c Final_States.cpp

Main.o:
	g++ -g -c Main.cpp

States.o:
	g++ -g -c States.cpp

Input_Alphabet.o:
	g++ -g -c Input_Alphabet.cpp
	


clean:
	rm -f crash.o
	rm -f Final_States.o
	rm -f Main.o
	rm -f States.o
	rm -f Tape_Alphabet.o
	rm -f Transition.o
	rm -f Turing_Machine.o
	rm -f Final_States.o
	rm -f Visable.o
	rm -f Input_Alphabet.o
	rm -f Tape.o
	rm -f Transition_Function.o 
	rm -f TM
