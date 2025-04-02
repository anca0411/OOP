#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cstdio> 
using namespace std;

int Number::DetectareBaza(const char* b)
{
	int max_val = 0;
	for (int i = 0; b[i] != 0; i++)
	{
		if (b[i] >= 0 || b[i] <= 9)
			max_val = max(max_val, b[i] - '0');
		else
			if (b[i] >= 'A' || b[i] <= 'Z')
				max_val = max(max_val, b[i] - 'A' + 10);
			else return -1;
	}
	return max_val + 1;
}

Number::Number(const char* value, int base)
{
	this->val = new char[strlen(value)];
	strcpy(this->val, value);
	this->baza = base;
}
Number::~Number()
{
	delete this->val;
	
}

Number::Number(Number& x)
{
	this->val = new char[strlen(x.val)+1];
	strcpy(this->val, x.val);
	this->baza = x.baza;
}
Number::Number(Number&& x) noexcept
{
	this->val = x.val;
	x.val = nullptr;
	
	this->baza = x.baza;
	x.baza = 0;
}

void Number::SwitchBase(int newBase)
{
	int putere = 1, nr = 0,m=1;

	for (int i = strlen(val) - 1; i >= 0; i--)
	{
		if (val[i] >= '0' && val[i] <= '9')
		    nr = nr + (baza * putere * val[i] - '0');
		if (val[i] >= 'A' && val[i] <= 'F')
			nr = nr + (baza * putere * val[i] - 'A' + 10);
		putere = putere * baza;
	}
	int i= 0;
	char nrnou[101];
	while (nr != 0)
	{
		int r = nr % newBase;
		if (r >= 0 || r <= 9)
			nrnou[i++] = r - '0';
		else if(r>='A' || r<='F')
			nrnou[i++] = r - 'A' + 10;
		
		nr = nr / newBase;
	}
	nrnou[i] = '\0';
	int j;
	for (j = 0; j < i / 2; j++)
		swap(nrnou[j], nrnou[i - j - 1]);
	strcpy(this->val, nrnou);
	this->baza = newBase;

}
Number operator+(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	int nrnou = x + y;
	Number c(nullptr, max(a.baza,b.baza));
	char newval[101];
	int i = 0;
	while (nrnou != 0)
	{
		int r = nrnou % max(a.baza,b.baza);
		if (r < 10)
		{
			newval[i++] = r + '0';
		}
		else 
		{
			newval[i++] = r - 10 + 'A';
		}
		nrnou = nrnou / max(a.baza,b.baza);

	}
	newval[i] = '\0';
	int j;
	for (j = 0; j < i; j++)
		newval[j] = newval[i - j - 1];
	
	c.val = new char[strlen(newval) + 1];
	strcpy(c.val, newval);
	return c;
}
Number operator-(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	int nrnou = abs(x - y);
	Number c(nullptr, max(a.baza, b.baza));
	char newval[101];
	int i = 0;
	while (nrnou != 0)
	{
		int r = nrnou % max(a.baza, b.baza);
		if (r < 10)
		{
			newval[i++] = r + '0';
		}
		else
		{
			newval[i++] = r - 10 + 'A';
		}
		nrnou = nrnou / max(a.baza, b.baza);

	}
	newval[i] = '\0';
	int j;
	for (j = 0; j < i / 2; j++)
		swap(newval[j], newval[i - j - 1]);

	c.val = new char[strlen(newval) + 1];
	strcpy(c.val, newval);
	return c;
}
char& Number::operator[](int index)
{
	return this->val[index];
}
void Number::operator=(const Number& a)
{
	if (a.val == nullptr)
	{
		delete[] this->val;
		this->val = new char[2];
		strcpy(this->val, "0");
		this->baza = 10;
	}
	else
	{
		delete[] this->val;
		this->val = new char[strlen(a.val) + 1];
		strcpy(this->val, a.val);
		this->baza = a.baza;
	}
	this->baza = a.baza;
}
void Number::operator=(int a)
{
	sprintf(this->val, "%d", a);
	this->baza = 10;
}
void Number::operator=(const char* a)
{
	if (a == nullptr)
	{
		delete[] this->val;
		this->val = new char[2];
		this->val = nullptr;
		this->baza = 10;

	}
	else
	{
		delete[] this->val;
		this->val = new char[strlen(a) + 1];
		strcpy(this->val, a);
		this->baza = DetectareBaza(a);
	}
}
Number operator+=(Number& a,const Number& b)
{
	a = a + b;
	return a;
}
Number operator-=(Number& a, const Number& b)
{
	a = a - b;
	return a;
}
Number& Number::operator--()//eliminam prima cifra
{
	if (strlen(val) == 0 || this->val == nullptr)
		return *this;
	for (int i = 1; i < strlen(this->val); i++)
	{
		val[i - 1] = val[i];
	}
	val[strlen(this->val)-1] = '\0';
	return *this;
}
Number Number::operator--(int)//elimnam ultima cifra
{
	if (strlen(val) == 0 || this->val == nullptr)
		return *this;
	val[strlen(this->val) - 1] = '\0';
	return *this;
}
bool operator<(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x < y;
}
bool operator>(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x > y;
}
bool operator<=(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x <= y;
}
bool operator>=(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x >= y;
}
bool operator==(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x == y;
}
bool operator!=(const Number& a, const Number& b)
{
	int x = strtol(a.val, NULL, a.baza);
	int y = strtol(b.val, NULL, b.baza);
	return x != y;
}
void Number::Print()
{
	for (int i = 0; i <= strlen(val); i++)
		 cout << val[i];
}
int  Number::GetDigitsCount()
{
	return strlen(this->val);
}
int Number::GetBase()
{
	return this->baza;
}

