#include "Seat.h"
#include "Car.h"

Seat::Seat()
{
	fuelConsumption = 5;
	fuelCapacity = 20;
	speedSunny = 100;
	speedRainy = 80;
	speedSnow = 50;
}
double Seat::GetFuelConsumption() const
{
	return fuelConsumption;
}
double Seat::GetFuelCapacity() const
{
	return fuelCapacity;
}
double Seat::GetSpeed(Weather weather) const
{
	if (weather == Weather::Sunny)
		return speedSunny;
	else
		if (weather == Weather::Rain)
			return speedRainy;
		else
			return speedSnow;
}
const char* Seat::GetName() const
{
	return "Seat";
}
