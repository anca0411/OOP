#pragma once
#include "Car.h"
#include "Weather.h"

class BMW :public Car
{
public:
	BMW();
	double GetFuelConsumption() const override;
	double GetFuelCapacity() const override;
	double GetSpeed(Weather weather) const override;
	const char* GetName() const override;
};


