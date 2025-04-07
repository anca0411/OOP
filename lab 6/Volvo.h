#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo :public Car
{
public:
	Volvo();
	double GetFuelConsumption() const override;
	double GetFuelCapacity() const override;
	double GetSpeed(Weather weather) const override;
	const char* GetName() const override;
};



