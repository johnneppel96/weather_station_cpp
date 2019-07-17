#include "pch.h"
#include <iostream>
#include "temperature.h"
#include "wind.h"
#include "weatherMeasurement.h"
#include "genericInput.h"
#include<string>
using namespace std;

//@author John Neppel;
//CS-310

/*Constructor*/
WeatherMeasurement::WeatherMeasurement(Temperature t, Wind w) {
	tempReading = t;
	windReading = w;
}

/* Default constructor*/
WeatherMeasurement::WeatherMeasurement() {

}

	/*Function prompts user to enter the number of entries they
	want the weather history to hold. The weather history MUST
	store at least one weather reading. For this reason, the function
	will continue to execute until a valid history size greater than 0 is'
	entered. The valid history size they enter becomes the value of the historySize global variable
	*/
	void WeatherMeasurement:: promptForHistorySize() {
		int desiredHistSize = 0;
		bool validHistSizeEntered = false; //will be altered once a valid history size is entered

		cout <<"Enter how many entries you would like the weather history to store (it must be at least 1 entry) " << endl;
		desiredHistSize = getPosIntegerInput(); //variable gets integer returned by function

		while (validHistSizeEntered == false) {  //loop will continue to execute until a valid history size is entered

			if(desiredHistSize > 0) { //for valid desired history inputs
				cout << "History size set to " << desiredHistSize << " maximum entries" << endl << endl;
				historySize = desiredHistSize; //initializes the historysize to the user's input
				weatherHistory = new WeatherMeasurement[historySize]; //allocates the corresponding memory size for the pointer
				validHistSizeEntered = true; //alters control variable in order to exit the while loop
			}
			else { //for invalid desired history size inputs
				cout << "Invalid history size inputted, try entering another one (it must be greater than 0) " << endl;
				desiredHistSize = getPosIntegerInput(); //reinitalized to the next input user enters
			}
		} //emd of while loop
	}


	/*Function takes in the current weather variables
	  and stores it within the corresponding weather history array.
	  The newest weather readings are ALWAYS stored at index '0'.
	*/
	void WeatherMeasurement:: archiveWeatherData(Temperature temp, Wind w) {
		//creates local weatherMeasurement object 
		WeatherMeasurement newReading(temp, w); 
		//shifts the elements inside the history array to accomodate the newest weather history reading for index '0'.
		shiftArrayElements();
		weatherHistory[0] = newReading;

		if(numOfHistIndiciesFilled < historySize) {
			numOfHistIndiciesFilled++; //This will continue to increment until the variable is equal to the historySize.
									   //This is because indicies are forever filled when equal to the historySize.

		}
	}

	/*Function shifts the elements located in each index of the history array.
	This is done to ensure that the newest weather reading
	is always stored at index 0 and the others follow in queue.
	*/
	void WeatherMeasurement:: shiftArrayElements() {
		//This 'for' loop *will not* be entered at all if historySize is initialized to 1
		for (int index = historySize - 1; index > 0; index--) { 
			//starting at the last index in each array,
			//all data elements at each index becomes equal to the elements in the 
			//previous index (aside from index '0')
			weatherHistory[index] = weatherHistory[index - 1];
		}


	}

	/*Function takes in two float parameters for the temperature and
	  windspeed, and one string parameter for the wind direction. It
	  outputs each accordingly.
	*/
	void WeatherMeasurement:: printWeatherData(Temperature temp, Wind wind) {
		cout << "Temperature: " << temp.getDegreesInFahrenheit() << " F" << endl;
		cout << "Wind: " << wind.getWindSpeed() << " mph " << wind.getWindDirection() << endl;
		cout << endl;
	}


	/*Function outputs the full available weather history.
	It outputs the most recent weather reading first, followed by the older
	ones.
	*/
	void WeatherMeasurement:: printWeatherHistory() {
		cout << "Weather History- ordered most recent to oldest: " << endl;
		for (int i = 0; i < numOfHistIndiciesFilled; i++) {
			Temperature tempAtIndex = weatherHistory[i].tempReading; //init to temp object at current index
			Wind windAtIndex = weatherHistory[i].windReading; //init to the wind object at current index 
			printWeatherData(tempAtIndex, windAtIndex); //passes local weather variables to print the info at each index accordingly
		}

	}