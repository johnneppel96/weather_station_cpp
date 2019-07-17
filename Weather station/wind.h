#ifndef WIND_H
#define WIND_H
#include "pch.h"
#include <iostream>
#include<string>
#include<sstream>
#include<regex>
using namespace std;

//@author John Neppel
//CS-310

class Wind {
private:
	float windSpeed; //mph
	string windDirection;

public:
	Wind(float wSpeed, string wDirection);
	Wind();

	float getWindSpeed();
	void setWindSpeed();
	string getWindDirection();
	void setWindDirection();

};

#endif