#include "Canvas.h"
#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	m = new char* [height+1];
	for (int i = 1; i <= height; i++)
		m[i] = new char[width];
	Clear();
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if(x>=0 && x<=height && y>=0 && y <= width)
			m[x][y] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int d;
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			d = pow((i - x), 2) + pow((j - y), 2);
			if (d <= ray * (ray - 1) && d <= ray * (ray + 1))
				SetPoint(i, j, ch);

		}
		
	}

	
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			if (pow((i - x), 2) + pow((j - y), 2) <= ray * ray)
				SetPoint(i, j, ch);
			else
				m[i][j] = ' ';
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top; i <= bottom; i++)
	{
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			SetPoint(i, j, ch);
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	while (x1 <= x2 && y1 <= y2)
	{
		SetPoint(x1, y1, ch);
		y1++;
		x1++;
	}
}

void Canvas::Clear()
{
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			m[i][j] = ' ';
}
void Canvas::Print()
{
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
			std::cout << m[i][j];
		std::cout << '\n';
	}
}
