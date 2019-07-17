#include "pch.h"
#include "genericInput.h"
#include "regexValidation.h"
#include <iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;


/* Function allows user to input a value.
	 If anything contained within the input isn't a positive integer,
	 the user is prompted to enter another. The validated positive int
	 is returned.
 */
int getPosIntegerInput() {
	string input;
	int inputAsAnInt;
	getline(cin, input); //takes in user's input originially as a string
	while (isAValidPosIntegerInput(input) == false) {//if the user's input wasn't a positive integer
		cout << "You didn't enter a valid numerical input, try entering another " << endl;
		getline(cin, input); //takes in a new input from the user to be tested for validity
	}
	stringstream(input) >> inputAsAnInt; //casts the validated input from a string into an integer
	return inputAsAnInt; //returns the validated integer

}
