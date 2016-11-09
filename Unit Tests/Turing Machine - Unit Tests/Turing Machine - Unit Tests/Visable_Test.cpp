#include "stdafx.h"
#include "CppUnitTest.h"

#include "Visable.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Visable_Test)
		{
			// TODO: Your test code here
			std::string ShouldBeAllUpper = Visable("");

			Assert::AreEqual(ShouldBeAllUpper, std::string("\\"));
		}

	};
}