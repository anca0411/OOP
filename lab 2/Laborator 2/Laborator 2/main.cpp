#include <iostream>

#include "NumberList.h"
#define _SECURE_CRT_NO_WARNINGS

; int main()
{	
	NumberList list;
	list.Add(10);
	list.Add(7);
	list.Add(5);
	list.Add(3);
	list.Add(13);
	list.Add(16);
	list.Sort();
	list.Print();
	return 0;
}