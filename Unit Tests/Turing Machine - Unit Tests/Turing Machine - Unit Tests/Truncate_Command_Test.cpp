#include "stdafx.h"
#include "CppUnitTest.h"

#include "Truncate_Command.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Truncate_Command_Test)
		{
				// Fake user input ;)
			istringstream iss("1\nds1\n");
			cin.rdbuf(iss.rdbuf());

				// Valid input.
			int zz = 0;
			Truncate_Command(zz);
			Assert::AreEqual(zz, 1);

				// Invalid input.
			zz = 0;
			Truncate_Command(zz);
			Assert::AreNotEqual(zz, 1);
		}

	};
}