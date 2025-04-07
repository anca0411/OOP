#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <iostream>
#include <iomanip>

using namespace std;

Circuit::Circuit()
{
	this->length = 0;
	this->weather = Weather::Sunny;
	this->carCount = 0;

}
Circuit::~Circuit()
{
	for (int i = 0; i < carCount; i++)
		delete[] this->cars[i];
}
void Circuit::AddCar(Car* car)
{
	if (carCount < 10)
	{
		this->cars[carCount] = car;
		carCount++;
	}
}
void Circuit::SetLength(double x)
{
	this->length = x;
}
void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::Race() 
{
	for (int i = 0; i < carCount; i++)
	{
		double speed = cars[i]->GetSpeed(weather);
		double fuelNeeded = (cars[i]->GetFuelConsumption() / 100.0) * length;
		double fuelAvailable = cars[i]->GetFuelCapacity();
		if (fuelNeeded <= fuelAvailable)
			time[i] = length / speed;
		else
			time[i] = -1;
	}
}
void Circuit::ShowFinalRanks() 
{
	for(int i = 0; i< carCount-1;i++)
		for(int j = 0; j< carCount; j++)
			if(time[i]!=-1)
				if (time[i] < time[j])
				{
					int aux = time[i];
					time[i] = time[j];
					time[j] = time[i];
				}
	for (int i = 0; i < carCount; i++)
		if(time[i]!=-1)
		   cout << cars[i]->GetName() << " a terminat in "<< setprecision(2) << time[i] << " ore"<<endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < carCount; i++)
		if (time[i] == -1)
			cout << cars[i]->GetName() << " nu a reusit sa termine cursa"<<endl;
}
