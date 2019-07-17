#include "pch.h"
#include <iostream>
#include "temperature.h"
#include "wind.h"
#include "regexValidation.h"
#include "genericInput.h"
#include "weatherMeasurement.h"
#include <string>
#include <regex>
#include <sstream>
using namespace std;

//@author John Neppel
//CS-310

//global variables for weather data
string stationName;
Temperature currentTemperature;
Wind windConditions;
WeatherMeasurement reading; //used for storing the weather readings

//declaration of functions
void printControlOptions();
string promptForStationName();
void printStationName();



int main(int argc, string argv[]) {
	stationName = promptForStationName(); 
	cout << "Welcome to " << stationName << endl;
    reading.promptForHistorySize();

	bool stop = false;
	bool weatherEntered = false; //flags whether weather info has been entered by the user

	while (stop == false) { //loop will continue to execute unless user selects to exit

		int inputCommand; //stores the number that executes the control of the program
		printControlOptions();
		inputCommand = getPosIntegerInput(); //function returns a validated positive integer

		switch (inputCommand) {
		case 1:
			//calls upon 'set' methods which get's the user's validated input for each weather variable
			currentTemperature.setDegrees();
			windConditions.setWindSpeed();
			windConditions.setWindDirection();
			weatherEntered = true; /*confirms that weather information has been entered */
			reading.archiveWeatherData(currentTemperature, windConditions); //archives the current weather report
			cout << "All weather information has been successfully inputted and archived" << endl << endl;
			break;

		case 2:
			if (weatherEntered == true) {//checks to see if there is weather information available
				printStationName();
				cout << "Current Weather Data: " << endl;
				reading.printWeatherData(currentTemperature,windConditions); //passes in variables as parameters to print
			}
			else {
				cout << "Oops, there is no weather data available" << endl << endl;
			}
			break;

		case 3: //prints full weather history
			if (weatherEntered == true) {
				printStationName();
				reading.printWeatherHistory();
			}
			else {
				cout << "Oops, there is no weather data history available" << endl << endl;
			}
			break;
		case 4:
			cout << "Peace out " << endl;
			stop = true; //alters the variable which halts the execution of the loop
			break;

		default:
			cout << "Oops, you didn't enter one of the required options! Try again!" << endl; //for invalid inputs
			break;

		}//end of switch statement
	}//end of while statement

	return 0;
	
}


/*Function prompts user to enter a name for the Weather Station.
 It forces the user to enter a name that is less than 30 characters
long. This name gets returned as a  String.*/
string promptForStationName() {
	string inputForName="";
	cout << "Hello, please enter the desired name of the Weather Station" << endl;
	do {
		getline(cin, inputForName);//takes the entire line of user input as the name of the station
		if (inputForName.length() > 30) {
			cout << "Oops, the name you entered exceeds the maximum allowed 30 characters, please enter another one" << endl;
		}
	} while (inputForName.length() > 30); //will continue to loop until the user's input is less than 30 characters long

	return inputForName;
}


/* Function prints out control options available for the user to take
*/
void printControlOptions() {
	//---Begins control options---
	cout << "Enter one of the following numbers to perform each designated task:" << endl;
	cout << "Enter 1 to input a complete weather reading" << endl;
	cout << "Enter 2 to print the current weather reading" << endl;
	cout << "Enter 3 to print a full weather history" << endl;
	cout << "Enter 4 to exit the Weather Station program" << endl;
}




/*Function outputs the name of the Weather Station*/
void printStationName() {
	cout << "Weather Station Name: " << stationName << endl;
}





 