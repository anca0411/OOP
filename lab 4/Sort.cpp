#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <iostream>
Sort::Sort(int nr, int minx, int maxx)
{
	this->size = nr;
	vector = new int[nr];
	time_t t;
	srand((unsigned)time(&t));
		for (int i = 0; i < nr; i++)
			vector[i] = minx + rand() % (maxx - minx + 1);
}
Sort::Sort() : vector(new int[6] {1, 2, 3, 4, 5, 6})
{
	this->size = 6;

}
Sort::Sort(int* a, int nr)
{
	this->size = nr;
	vector = new int[nr];
	for (int i = 0; i < nr; i++)
		vector[i] = a[i];
}
Sort::Sort(int count,...)
{
	this->size = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i <= count; i++)
		vector[i] = va_arg(vl, int);
	va_end(vl);
}
Sort::Sort(char* c)
{
	int k= 0;
	for (int i = 0; c[i] != '\0'; i++)
		if (c[i] == ',')
			k++;
	vector = new int[k];
	int j = 0, nr = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == ',')
		{
			vector[j++] = nr;
			nr = 0;
		}
		else
		{
			nr = nr * 10 + (c[i] - '0');
		}
	}
	this->size = k;
}
void Sort::InsertSort(bool ascendent)
{
	int j;
	for (int i = 1; i < size; i++)
	{
		int a = vector[i];
		j = i - 1;
		while (j >= 0 && a < vector[j])
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j+1] = a;
	}
}

int Sort::partitie(int mini, int maxi, bool ascendent)
{
	int pivot = vector[maxi];
	int i = mini - 1;

	for (int j = mini; j < maxi; j++)
	{
		if ((ascendent && vector[j] < pivot) || (!ascendent && vector[j] > pivot))
		{
			i++;
			int aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
		}
	}
	int aux = vector[i + 1];
	vector[i + 1] = vector[maxi];
	vector[maxi] = aux;
	return i + 1;
}
void Sort::QuickSort1(int mini, int maxi, bool ascendent)
{
	if (mini < maxi)
	{
		int pivot = partitie(mini, maxi, ascendent);
		QuickSort1(mini, pivot - 1, ascendent);
		QuickSort1(pivot + 1, maxi, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	QuickSort1(0, size - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
			if (vector[j] > vector[j + 1])
			{
				int aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
	}
}
void Sort::Print()
{
	for (int i = 0; i < size; i++)
	  std::cout << vector[i]<<" ";
}
int Sort::GetElementsCount()
{
	return size;
}
int Sort ::  GetElementFromIndex(int index)
{
	return vector[index];
	
}