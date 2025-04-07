#include "Fiat.h"
#include "Car.h"

Fiat::Fiat()
{
	fuelConsumption = 8;
	fuelCapacity = 60;
	speedSunny = 150;
	speedRainy = 120;
	speedSnow = 100;
}
double Fiat::GetFuelConsumption() const
{
	return fuelConsumption;
}
double Fiat::GetFuelCapacity() const
{
	return fuelCapacity;
}
double Fiat::GetSpeed(Weather weather) const
{
	if (weather == Weather::Sunny)
		return speedSunny;
	else
		if (weather == Weather::Rain)
			return speedRainy;
		else
			return speedSnow;
}
const char* Fiat::GetName() const
{
	return "Fiat";
}
