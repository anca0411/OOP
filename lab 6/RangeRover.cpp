#include "RangeRover.h"
#include "Car.h"

RangeRover::RangeRover()
{
	fuelConsumption = 14;
	fuelCapacity = 80;
	speedSunny = 250;
	speedRainy = 230;
	speedSnow = 200;
}
double RangeRover::GetFuelConsumption() const
{
	return fuelConsumption;
}
double RangeRover::GetFuelCapacity() const
{
	return fuelCapacity;
}
double RangeRover::GetSpeed(Weather weather) const
{
	if (weather == Weather::Sunny)
		return speedSunny;
	else
		if (weather == Weather::Rain)
			return speedRainy;
		else
			return speedSnow;
}
const char* RangeRover::GetName() const
{
	return "RangeRover";
}
