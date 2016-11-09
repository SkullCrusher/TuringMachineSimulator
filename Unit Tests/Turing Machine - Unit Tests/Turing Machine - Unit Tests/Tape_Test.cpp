#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Tape_Test)
		{
			// Fake user input ;)
			std::istringstream iss("1\nds1\n");
			std::cin.rdbuf(iss.rdbuf());

			/*
			class Tape {

			private:
				string cells;

				int current_cell;
				char blank_character;
			public:
				Tape();

				void load(ifstream& definiton, bool& valid);
				void validate(const Input_Alphabet& input_Alphabet, const Tape_Alphabet& tape_alphabet, bool &valid) const;
				void view() const;
				void initialize(string input_string);
				void update(char write_character, Direction move_direction);
				string left(int maximum_number_of_cells) const;
				string right(int maximum_number_of_cells) const;
				char current_character() const;
				bool is_first_cell() const;

			};

			*/

		}

	};
}