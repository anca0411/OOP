#include "Volvo.h"
#include "Car.h"

Volvo::Volvo()
{
	fuelConsumption = 7;
	fuelCapacity = 80;
	speedSunny = 180;
	speedRainy = 150;
	speedSnow = 120;
}
double Volvo::GetFuelConsumption() const
{
	return fuelConsumption;
}
double Volvo::GetFuelCapacity() const
{
	return fuelCapacity;
}
double Volvo::GetSpeed(Weather weather) const
{
	if (weather == Weather::Sunny)
		return speedSunny;
	else
		if (weather == Weather::Rain)
			return speedRainy;
	else 
			return speedSnow;
}
const char* Volvo::GetName() const
{
	return "Volvo";
}
