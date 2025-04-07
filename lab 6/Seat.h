#pragma once
#include "Car.h"
#include "Weather.h"

class Seat :public Car
{
public:
	Seat();
	double GetFuelConsumption() const override;
	double GetFuelCapacity() const override;
	double GetSpeed(Weather weather) const override;
	const char* GetName() const override;
};


