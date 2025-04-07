#pragma once
#include "Weather.h"
#include "Car.h"
class Car
{
public:

	double fuelConsumption;
    double fuelCapacity;
    double speedSunny;
	double speedRainy;
	double speedSnow;

	virtual double GetFuelConsumption() const = 0;
	virtual double GetFuelCapacity() const = 0;
	virtual double GetSpeed(Weather weather) const = 0;
	virtual const char* GetName() const = 0;
};