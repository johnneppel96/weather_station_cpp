#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "pch.h"
#include <iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

class Temperature {
private:
	float degrees; //in Fahrenheit

public:
	Temperature(float dgrees);
	Temperature();

	float getDegreesInFahrenheit();
	float getDegreesInCelsius();
	void setDegrees();

};


#endif