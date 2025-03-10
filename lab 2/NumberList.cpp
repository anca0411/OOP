#include "NumberList.h"

#include <iostream>
#define _SECURE_CRT_NO_WARNINGS

void NumberList::Init()
{
	count = 0;
}
void NumberList::Add(int x)
{
	numbers[++count] = x;
}
void NumberList::Sort()
{
	for(int i = 1; i< count; i++)
		for (int j = i + 1; j <= count; j++)
		{
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
	for (int i = 1; i <= count; i++)
		std :: cout << numbers[i]<<" ";

}
