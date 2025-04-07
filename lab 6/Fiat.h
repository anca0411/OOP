#pragma once
#include "Car.h"
#include "Weather.h"

class Fiat :public Car
{
public:
	Fiat();
	double GetFuelConsumption() const override;
	double GetFuelCapacity() const override;
	double GetSpeed(Weather weather) const override;
	const char* GetName() const override;
};


