// NumberList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"
using namespace std;
void NumberList::Init()
{
	count = 0;
}
void NumberList::Add(int x)
{
	if (x < 10)
	{
		numbers[count] = x;
		count = count + 1;
	}
	return false;

}
void Sort()
{
	for (int i = 0; i < count-1; i++)
	{
		for (int j = i + 1; j < count; j++)
			if (numbers[i] > numbers[j])
			{
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
	}
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}


