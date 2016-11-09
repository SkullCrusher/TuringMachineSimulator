#ifndef FAKECONNECTOR_H
#define FAKECONNECTOR_H

#include "Turing_Machine.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

#include <direct.h>
#define GetCurrentDir _getcwd


void FakeUserInput(std::string arg) {
	std::istringstream iss(arg);
	std::cin.rdbuf(iss.rdbuf());
}

std::stringstream buffer;
std::streambuf * old;

void Fake_StartSTDOutCapture(){	
	old = std::cout.rdbuf(buffer.rdbuf());
}

std::string Fake_GetSTDOutCapture() {
	return buffer.str();
}

Turing_Machine FakeTM() {

	char cCurrentPath[FILENAME_MAX];
	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) { int a = 0; }
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';

	std::string Path = cCurrentPath;
	Path += "\\..\\..\\..\\Example Files\\TM_DATA";

	Turing_Machine TM(Path);

	return TM;
}

#endif