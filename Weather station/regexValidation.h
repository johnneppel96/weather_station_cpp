#ifndef REGEX_VALIDATION_H
#define REGEX_VALIDATION_H
#include "pch.h"
#include <iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;
//@author John Neppel
//CS-310


//declaration of functions
bool matchesRegex(string inputTest, string validation);
bool isAValidPosIntegerInput(string inputTest);

#endif