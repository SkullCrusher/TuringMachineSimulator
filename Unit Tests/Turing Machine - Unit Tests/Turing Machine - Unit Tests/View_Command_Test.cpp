#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include <string>
#include <sstream>

#include "Turing_Machine.h"

#include <stdio.h>  /* defines FILENAME_MAX */

#include <direct.h>
#define GetCurrentDir _getcwd


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TuringMachineUnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(View_Command_Test)
		{
			// Fake user input ;)
			std::istringstream iss("1\nds1\n");
			std::cin.rdbuf(iss.rdbuf());

			char cCurrentPath[FILENAME_MAX];
			if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){int a = 0;}
			cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';

			std::string Path = cCurrentPath;
			Path += "\\..\\..\\..\\Example Files\\TM_DATA";

			Turing_Machine TM(Path);

			


		}

	};
}