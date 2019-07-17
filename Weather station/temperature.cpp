#include "pch.h"
#include <iostream>
#include "temperature.h"
#include "regexValidation.h"
#include "genericInput.h"
#include<string>
#include<sstream>
#include<regex>
using namespace std;

//@author John Neppel
//CS-310

/* Constructor */
Temperature::Temperature(float dgrees) {
	degrees = dgrees;
}

/*Default constructor*/
Temperature::Temperature() {
	degrees = 0;
}

float Temperature::getDegreesInFahrenheit() {
	return degrees;
 }

float Temperature::getDegreesInCelsius() {
	return((degrees - 32) * 5 / 9);
}



/*Function takes a string value as input to test whether
its value represents a valid Temperature (Degrees Fahrenheit).
Function will loop through recursion until a valid Temperature is entered.
Once a validated input is entered, the function returns it as a string
*/
string checkForValidTemperature(string inputTest) {
	string validation = "[0]|[-]?[1-9]|[-]?[1-9][0-9]|[-]?1[0-2][0-9]";
	//validation covers values 0->(+-9), +-10->(+-99), +-100-> (+-129)

	if (matchesRegex(inputTest, validation)) { //calls upon function to verify whether input is valid through regex statement
		return inputTest; //the validated inputTest is returned
	}
	else {
		cout << "Invalid temperature inputted" << endl;
		cout << "Try entering another temperature value" << endl;
		inputTest = "";//ensures inputTest buffer for method is clear
		string newInputAttempt;
		getline(cin, newInputAttempt); //takes a new temperature input from the user
		return checkForValidTemperature(newInputAttempt); //recurses through the method again with new input
	}
}


/* Function prompts user to input a temperature reading,
makes sure its valid and returns the validated float for a temperature*/
float TemperatureInput() {
	float currentTemperature;
	cout << "Enter the value of the current Temperature in terms of degrees Fahrenheit" << endl;
	string input = "";
	getline(cin, input);
	 //passes input into function to ensure it's valid, a validated input is returned
	input = checkForValidTemperature(input);
	stringstream(input) >> currentTemperature; //casts the validated input into a float
	return currentTemperature; //returns the temperature as a float
}

void Temperature::setDegrees() {
	degrees = TemperatureInput();
}
