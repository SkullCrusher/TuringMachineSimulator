#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Direction_Test)
		{
			// Fake user input ;)
			std::istringstream iss("1\nds1\n");
			std::cin.rdbuf(iss.rdbuf());

	
		}

	};
}