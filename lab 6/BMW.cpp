#include "BMW.h"
#include "Car.h"

BMW::BMW()
{
	fuelConsumption = 9;
	fuelCapacity = 70;
	speedSunny = 250;
	speedRainy = 240;
	speedSnow = 200;
}
double BMW::GetFuelConsumption() const
{
	return fuelConsumption;
}
double BMW::GetFuelCapacity() const
{
	return fuelCapacity;
}
double BMW::GetSpeed(Weather weather) const
{
	if (weather == Weather::Sunny)
		return speedSunny;
	else
		if (weather == Weather::Rain)
			return speedRainy;
		else
			return speedSnow;
}
const char* BMW::GetName() const
{
	return "BMW";
}
