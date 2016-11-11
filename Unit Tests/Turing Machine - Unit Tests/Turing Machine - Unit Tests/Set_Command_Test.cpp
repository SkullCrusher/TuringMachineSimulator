#include "stdafx.h"
#include "CppUnitTest.h"

#include "Set_Command.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Set_Command_Test)
		{
			// Fake user input ;)
			std::istringstream iss("1\nds1\n");
			std::cin.rdbuf(iss.rdbuf());

			std::stringstream buffer;
			std::streambuf * old;

			int Transition_Max = 0;
			old = std::cout.rdbuf(buffer.rdbuf());


			Set_Command(Transition_Max);
			std::string Result = buffer.str();

			Assert::AreEqual(Result[0], 'M');

			Set_Command(Transition_Max);
			Result = buffer.str();

			Assert::AreEqual(Result[106], 'E');

		}

	};
}