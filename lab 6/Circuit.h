#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
private:
	Weather weather;
	double length;
	Car* cars[10];
	int carCount;
	double time[10];
public:
	Circuit();
	~Circuit();
	void SetLength(double x);
    void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	void ShowWhoDidNotFinish();
};

