#include "pch.h"
#include <iostream>
#include "wind.h"
#include "regexValidation.h"
#include "genericInput.h"
#include<string>
#include<sstream>
#include<regex>
using namespace std;
//@author John Neppel
//CS-310


/*Constructor for Wind Object*/
Wind::Wind(float wSpeed, string wDirection) {
	windSpeed = wSpeed;
	windDirection = wDirection;
}

/*Default constructor for Wind Object*/
Wind::Wind() {
	windSpeed = 0;
	windDirection = "";
}

float Wind::getWindSpeed() {
	return windSpeed;
}

string Wind::getWindDirection() {
	return windDirection;
}

string checkForValidWindSpeed(string inputTest) {
	string validation = "[0-9]|[1-9][0-9]|1[0-5][0-9]|2[0-5][0-5]";
	//validation covers values 0->9, 10->99, 100->159, 200->255

	if (matchesRegex(inputTest, validation)) { //calls upon function to verify whether input is a valid through regex statement
		return inputTest; //returns the input that was validated
	}
	else {
		cout << "Invalid wind speed inputted" << endl;
		cout << "Try entering another windspeed value" << endl;
		inputTest = ""; //clears input buffer
		string newInputAttempt;
		getline(cin, newInputAttempt); //takes a new windspeed input from the user
		return checkForValidWindSpeed(newInputAttempt); //recurses through the method again with new input
	}
}


/*Function prompts user to input a wind speed reading and
makes sure its valid by calling upon checkForValidWindSpeed() function
The validated windspeed is returned as a float*/
float windSpeedInput() {
	float windSpeed;
	cout << "Enter the value of the wind speed in terms of mph" << endl;
	string input = "";
	getline(cin, input); /*takes in the line of input initially as a String*/
	input = checkForValidWindSpeed(input);//passes input into function to check if it's valid; function will return a validated input
	stringstream(input) >> windSpeed; //casts validated input into a float
	return windSpeed;
}


 void Wind::setWindSpeed() {
	 windSpeed = windSpeedInput();
}


/*Function takes in a string value to test against a regular expression
in order to ensure that it's a valid wind direction input.
It continues to execute until the user enters a valid wind direction
*/
string checkForValidWindDir(string inputTest) {
	string validation = "[N]|[N][E]|[N][W]|[S]|[S][E]|[S][W]|[W]|[E]";
	//validation covers "N","NE","NW","S","SE","SW","W","E"
	if (matchesRegex(inputTest, validation)) { //tests input against the regex, 'true' will be returned if it is validated
		return inputTest;
	}
	else {
		cout << "Invalid wind direction inputted" << endl;
		cout << "Try entering one of the following: " << endl;
		cout << "(N, NW, NE, S, SW, SE, W, E)" << endl;
		inputTest = ""; //clears input buffer
		string newInputAttempt;
		getline(cin, newInputAttempt); //takes a new windspeed input from the user
		return checkForValidWindDir(newInputAttempt); //recurses through the method again with new input
	}
}


/*Function prompts user to input a wind speed
 and returns it as a string
*/
string windDirectionInput() {
	string windDirection = "";
	cout << "Enter the wind direction in one of the following formats: " << endl;
	cout << "(N, NW, NE, S, SW, SE, W, E)" << endl;
	getline(cin, windDirection);
	windDirection = checkForValidWindDir(windDirection); //variable is reinitialized by the validated string returned
	return windDirection;
}

void Wind::setWindDirection() {
	windDirection = windDirectionInput(); //gets a valid wind input through method
}