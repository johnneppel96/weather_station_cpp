#ifndef WEATHER_MEASUREMENT_H
#define WEATHER_MEASUREMENT_H
#include "pch.h"
#include <iostream>
#include "temperature.h"
#include "wind.h"
#include "regexValidation.h"
#include "genericInput.h"
#include<string>
#include<regex>
using namespace std;
//@author John Neppel

class WeatherMeasurement {
private:
	Temperature tempReading;
	Wind windReading;

	//**global variables for weather history keeping**//
	int historySize; //variable determines the size of the history keeper
	int numOfHistIndiciesFilled = 0;
	WeatherMeasurement* weatherHistory;

public:
	WeatherMeasurement(Temperature t, Wind w);
	WeatherMeasurement();

	void promptForHistorySize();
	void archiveWeatherData(Temperature temp, Wind w);
	void shiftArrayElements();
	void printWeatherHistory();
	void printWeatherData(Temperature temp, Wind wind);
};
#endif