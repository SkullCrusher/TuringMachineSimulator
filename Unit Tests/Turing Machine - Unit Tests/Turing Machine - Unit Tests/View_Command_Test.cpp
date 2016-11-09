#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include <string>
#include <sstream>

#include "FakeConnectors.h"
#include "View_Command.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(View_Command_Test)
		{
				// Capture the std::cout.
			Fake_StartSTDOutCapture();
				
				// Create a turing machine.
			Turing_Machine TM = FakeTM();

				// Trigger the command.
			View_Command(TM);

				// Get the output.
			std::string Output = Fake_GetSTDOutCapture();

			Assert::AreEqual(Output[0], 'T');

		}

	};
}