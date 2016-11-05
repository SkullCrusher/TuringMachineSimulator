#include "stdafx.h"
#include "CppUnitTest.h"

#include "Visable.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Visible_Command)
		{
			std::string a = "\\";
			std::string b = Visable("");


			//Assert::AreEqual(a, b);
		}

	};
}