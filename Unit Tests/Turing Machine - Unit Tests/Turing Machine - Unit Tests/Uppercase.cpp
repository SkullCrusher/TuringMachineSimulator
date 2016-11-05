#include "stdafx.h"
#include "CppUnitTest.h"

#include "Uppercase.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Uppercase)
		{
			// TODO: Your test code here
			std::string ShouldBeAllUpper = UpperCase("AaaA");

			Assert::AreEqual(ShouldBeAllUpper, std::string("AAAA"));
		}

	};
}