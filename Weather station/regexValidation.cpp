#include "pch.h"
#include "regexValidation.h"
#include <iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

//@author John Neppel
//CS-310

/*Function takes in a test variable and a regex validation statement. The test
  variable will be tested against the regex validation statement. Function returns
  true if it validated against the regex statement, and false otherwise.
*/
bool matchesRegex(string inputTest, string validation) {
	const char* test = inputTest.c_str(); //converts the input test value into a char* variable
	regex re(validation);
	cmatch match;
	if (regex_match(test, match, re)) {  //tests to see if the input matches the regex statement
		return true; //returns true if the test matches the regex statement
	}
	else {
		return false;
	}
}

/*Function takes a string to test whether it
 represents a positive integer value. Function
 returns true if the test-string is a positive integer
 and false otherwise.
*/
bool isAValidPosIntegerInput(string inputTest) {
	string validation = "[0-9]*";
	//validation covers 0 and any positive integer
	if (matchesRegex(inputTest, validation)) { //tests the inputted String against the regex validation
		return true;
	}
	else {
		return false;
	}

}